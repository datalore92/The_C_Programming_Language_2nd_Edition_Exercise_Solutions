#include <stdio.h>
#define BUFSIZE     2

/* Exercise 4-8: Suppose that there will never be more than one character of 
pushback. Modify getch and ungetch accordingly. */

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

int getch(void);        // get a (possibly pushed back) character
void ungetch(int);      // push character back on input

int main(void) {

    return 0;
}

int getch(void) {                                       // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    buf[bufp++] = c;
}
