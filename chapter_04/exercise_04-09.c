#include <stdio.h>
#define BUFSIZE 100

/* Exercise 4-9: Our getch and ungetch do not handle a pushed-back EOF 
correctly. Decide what their properties ought to be if an EOF is pushed back, 
then implement your design. */

int buf[BUFSIZE];       // buffer for ungetch
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
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}