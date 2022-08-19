#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>     // for atof()
#include <math.h>
#define BUFSIZE     100
#define MAXVAL      100 // maximum depth of val stack
#define MAXOP       100 // max size of operand or operator
#define NUMBER      '0' // signal that a number was found
#define LETTER      '1' // signal that a letter was found
#define MAXVARS     27  // maximum number of variables
#define ALPHSTART   97  // ASCII number for 'a'

/* Exercise 4-6: Add commands for handling variables. (It's easy to provide 
twenty-six variables with single-letter names.) Add a variable for the most 
recently printed value. */

/* syntax of using variables:
1_a == a = 1
2_b == b = 2
a b + == 1 + 2
3 == a + b

Variable for most recently printed value: X
*/

// command @: print the top element of the stack without popping
// command #: duplicate the top element of the stack
// command $: swap the top two elements of the stack
// command ~: clear the stack
// command !: performs sin(x) and returns the result, takes 1 argument, the top element of the stack
// command &: performs exp(x) and returns the result, takes 1 argument, the top element of the stack
// command ^: performs pow(double, double) and returns the result, takes 2 args, the top 2 elements of the stack
// variable for most recently printed value: X

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf
int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack
char vars[MAXVARS];     // an array for storing letters (variables)
double nums[MAXVARS];   // an array for storing numbers

int getch(void);        // get a (possibly pushed back) character
void ungetch(int);      // push character back on input
int getop(char[]);      // get next operator or numeric operand
void push(double);      // push f onto value stack
double pop(void);       // pop and return top value from stack
void print_top(void);   // prints the top element of the stack without popping
void duplicate(void);   // duplicates the top element of the stack
void swap(void);        // swaps the top two elements of the stack
void clear(void);       // clears the stack
// function for storing nums (values associated with variables)
void store_num(char, double);
// function that takes a letter (variable) and retrieves the value associated with it
double retr_var_val(char);

int main(void) {
    int type, op1_int, op2_int;
    double op2;
    char s[MAXOP];

    // initialize the variable array
    for (int i1 = 0, i2 = ALPHSTART; i2 < ALPHSTART + MAXVARS; ++i1, ++i2) {
        vars[i1] = i2;
    }
    vars[MAXVARS - 1] = 'X';

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case LETTER: 
                push(retr_var_val(s[0]));
                break;
            case 'X':
                push(retr_var_val(s[0]));
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
                double i = pop();
                printf("\t%.8g\n", i);
                // assign value of i to variable X
                store_num('X', i);
                break;
            case '@':
                print_top();
                break;
            case '#':
                duplicate();
                break;
            case '$':
                swap();
                break;
            case '~':
                clear();
                break;
            case '!':
                push(sin(pop()));
                break;
            case '&':
                push(exp(pop()));
                break;
            case '^':
                double x = pop();
                push(pow(pop(), x));
                break;
            case '_':
                // get the letter that comes next
                char c;
                double i2;
                while (!(islower(c = getch()))) {
                    ;
                }
                if (islower(c)) {
                    i2 = pop();
                    store_num(c, i2);
                    push(i2);
                }
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
    if (islower(c)) {
        return LETTER;
    }
    if (c == 'X') {
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

// function for storing nums (values associated with variables)
void store_num(char c, double n) {
    int i;
    // find the letter
    for (i = 0; i < MAXVARS; ++i) {
        if (vars[i] == c) {
            nums[i] = n;
            break;
        }
    }
}
// function that takes a letter (variable) and retrieves the value associated with it
double retr_var_val(char c) {
    int i;
    for (i = 0; i < MAXVARS; ++i) {
        if (vars[i] == c) {
            return nums[i];
        }
    }
}