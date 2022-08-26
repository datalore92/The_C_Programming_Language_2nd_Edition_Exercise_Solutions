#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

/* Exercise 5-1: As written, getint treats a + or - not followed by a digit as a 
valid representation of zero. Fix it to push such a character back on the input. */

char buf[BUFSIZE];   // buffer for ungetch
int bufp = 0;        // next free position in buf

int getch(void);     // get a (possibly pushed back) character
void ungetch(int); // push character back on input
int getint(int*); // get next integer from input *pn

int main(void) {
    int x = 0;
    int *pn = &x;
    getint(pn);
    printf("%d\n", *pn);

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

int getint(int *pn) {
    int sign;
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
        if (!isdigit(c) && c != EOF) {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {    // turn the text into a number
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}