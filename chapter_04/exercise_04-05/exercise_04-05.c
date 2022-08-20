#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>     // for atof()
#include <math.h>
#define BUFSIZE     100
#define MAXVAL      100 // maximum depth of val stack
#define MAXOP       100 // max size of operand or operator
#define NUMBER      '0' // signal that a number was found

/* Exercise 4-5: Add access to library functions like sin, exp, and pow. 
See <math.h> in Appendix B, Section 4. */

// command p: print the top element of the stack without popping
// command d: duplicate the top element of the stack
// command s: swap the top two elements of the stack
// command c: clear the stack
// command !: performs sin(x) and returns the result, takes 1 argument, the top element of the stack
// command e: performs exp(x) and returns the result, takes 1 argument, the top element of the stack
// command ^: performs pow(double, double) and returns the result, takes 2 args, the top 2 elements of the stack

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf
int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack
 
int getch(void);        // get a (possibly pushed back) character
void ungetch(int);      // push character back on input
int getop(char[]);      // get next operator or numeric operand
void push(double);      // push f onto value stack
double pop(void);       // pop and return top value from stack
void print_top(void);   // prints the top element of the stack without popping
void duplicate(void);   // duplicates the top element of the stack
void swap(void);        // swaps the top two elements of the stack
void clear(void);       // clears the stack


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
            case 'p':
                print_top();
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap();
                break;
            case 'c':
                clear();
                break;
            case '!':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case '^':
                double x = pop();
                push(pow(pop(), x));
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
    if (c == 'p') {
        return c;
    }
    if (c == 'd') {
        return c;
    }
    if (c == 's') {
        return c;
    }
    if (c == 'c') {
        return c;
    }
    if (c == '!') {
        return c;
    }
    if (c == 'e') {
        return c;
    }
    if (c == '^') {
        return c;
    }
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

void duplicate(void) {                                  // duplicates the top element of the stack
    if (sp > 0) {
        val[sp] = val[sp - 1];
        ++sp;
    }
    else {
        printf("error: stack empty\n");
    }
}

void print_top(void) {                                  // prints the top element of the stack without popping it
    if (sp > 0) {
        printf("%f\n", val[sp - 1]);
    }
    else {
        printf("error: stack empty\n");
    }
}

void swap(void) {                                       // swaps the top two elements of the stack
    if (sp > 1) {
        int i = val[sp - 2];
        val[sp - 2] = val[sp - 1];
        val[sp - 1] = i;
    }
    else {
        printf("error: not enough values in stack\n");
    }
}

void clear(void) {                                      // clears the stack
    sp = 0;
}

