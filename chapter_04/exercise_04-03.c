#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>     // for atof()
#define BUFSIZE     100
#define MAXVAL      100 // maximum depth of val stack
#define MAXOP       100 // max size of operand or operator
#define NUMBER      '0' // signal that a number was found

/* Exercise 4-3: Given the basic framework, it's straightforward to extend the 
calculator. Add the modulus (%) operator and provisions for negative numbers */

/* NOTE: I got the modulus part right but I got the "add provisions for negative 
numbers" part wrong. :(  So I copied someone else's answer I found online.  What 
happened was, instead of just skipping the negative sign and using atof(), I did 
some kinda complicated thing where I made a variable that stores if the previous 
character was a negative sign, and if sp was less than 2, then change the number to 
negative, and although that did seem to work for small equations, if I entered a big 
equation, then it wouldn't give a correct answer. After reviewing someone else's answer 
online, I realized I could skip the negative sign like whitespace if the next char was a digit, 
then use atof() to turn the number into a negative. ;_; */

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf
int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack

int getch(void);        // get a (possibly pushed back) character
void ungetch(int);      // push character back on input
int getop(char[]);      // get next operator or numeric operand
void push(double);      // push f onto value stack
double pop(void);       // pop and return top value from stack

int main(void) {
    int type, op1_int, op2_int;
    double op2;
    char s[MAXOP];

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
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int getch(void) {                                       // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}

int getop(char s[]) {                                   // get next operator or numeric operand
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {  // skip whitespace
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;                                       // not a number
    }
    i = 0;
    if (isdigit(c) || c == '-') {
        while (isdigit(s[++i] = c = getch())) {         // collect integer part
            ;
        }
    }
    if (c == '.') {                                     // collect fraction part
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    if (s[0] == '-' && i == 1) {
        return '-';
    }
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