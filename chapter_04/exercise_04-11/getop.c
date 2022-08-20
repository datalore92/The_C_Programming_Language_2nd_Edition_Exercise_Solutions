#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#define BUFSIZE 100

int getop(char s[]) {                                   // get next operator or numeric operand
    int i, c;
    static int c_2 = 0;

    if (c_2 == 0) {
        c = getch();
    }
    else {
        c = c_2;
        c_2 = 0;
    }
    while ((s[0] = c) == ' ' || c == '\t') {  // skip whitespace
        c = getch();
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;                                       // not a number
    }
    i = 0;
    if (isdigit(c)) {
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
        c_2 = c;
    }
    return NUMBER;
}