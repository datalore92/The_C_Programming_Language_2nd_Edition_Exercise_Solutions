#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>     // for atof()
#define BUFSIZE     100
#define MAXVAL      100 // maximum depth of val stack
#define MAXOP       100 // max size of operand or operator
#define NUMBER      '0' // signal that a number was found

/* Exercise 4-10: An alternate organization uses getline to read an entire input 
line; this makes getch and ungetch unnecessary. Revise the calculator to use 
this approach. */

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf
int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack

int getch(void);        // get a (possibly pushed back) character
void ungetch(int);      // push character back on input
void get_line(void);    // gets a line of input
int getop(char[]);      // get next operator or numeric operand
void push(double);      // push f onto value stack
double pop(void);       // pop and return top value from stack

int main(void) {
    int type, op1_int, op2_int;
    double op2;
    char s[MAXOP];

    get_line();

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                }
                else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2_int = pop();
                op1_int = pop();
                if (op2_int != 0) {
                    push(op1_int % op2_int);
                }
                else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                get_line();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void get_line(void) {
    // get the line
    int c;
    bufp = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        buf[bufp++] = c;
    }
    if (c == '\n') {
        buf[bufp++] = c;
    }
    buf[bufp] = '\0';
    bufp = 0;
}

int getop(char s[]) {                                   // get next operator or numeric operand
    int i, c;

    while ((s[0] = c = buf[bufp++]) == ' ' || c == '\t') { // skip whitespace
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;                                       // not a number
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = buf[bufp++])) {     // collect integer part
            ;
        }
    }
    if (c == '.') {                                     // collect fraction part
        while (isdigit(s[++i] = c = buf[bufp++])) {
            ;
        }
    }
    s[i] = '\0';
    /*if (c != EOF) {
        ungetch(c);
    }*/
    return NUMBER;
}

void push(double f) {                                   // push f onto value stack
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) {                                      // pop and return top value from stack
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
