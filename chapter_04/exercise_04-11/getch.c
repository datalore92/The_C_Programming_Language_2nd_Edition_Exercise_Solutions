#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {                                       // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}