#include <stdio.h>
#include <string.h>  // for strlen()
#define BUFSIZE     100

/* Exercise 4-7: Write a routine ungets(s) that will push back an entire string 
onto the input. Should ungets know about buf and bufp, or should it just use 
ungetch? */

/* it's just easier to use ungetch */

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

int getch(void);        // get a (possibly pushed back) character
void ungetch(int);      // push character back on input
// pushes back an entire string onto the input
void ungets(char[]);

int main(void) {
    char s[] = "peepee poopoo, now mommy has to change you ";
    int c;

    ungets(s);
    while ((c = getch()) != EOF) {
        putchar(c);
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

void ungets(char s[]) {
    int i;
    for (i = strlen(s) - 1; i != 0; --i) {
        ungetch(s[i]);
    }
    ungetch(s[i]);
}

