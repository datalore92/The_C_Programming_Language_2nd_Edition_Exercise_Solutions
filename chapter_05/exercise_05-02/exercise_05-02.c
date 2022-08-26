#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define BUFSIZE 100

/* Exercise 5-2: Write getfloat, the floating-point analog of getint. What 
type does getfloat return as its function value? */

char buf[BUFSIZE];   // buffer for ungetch
int bufp = 0;        // next free position in buf

int getch(void);     // get a (possibly pushed back) character
void ungetch(int); // push character back on input
double getfloat(double*); // get next integer from input *pn

int main(void) {
    double x = 0;
    double *pn = &x;
    getfloat(pn);
    printf("%lf\n", *pn);

    return 0;
}

int getch(void) {
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

double getfloat(double *pn) {
    double sign;
    int c;

    while (isspace(c = getch())) {      // skip whitespace
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     // not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()) {    // turn the text into a number
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.') {
        c = getch();
        for (double i = 1.0; isdigit(c); ++i, c = getch()) {
            *pn += (double)(c - '0') / pow(10.0, i);
        }
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}