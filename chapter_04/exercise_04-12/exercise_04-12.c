#include <stdio.h>
#define MAXLEN 100

/* Exercise 4-12: Adapt the ideas of printd to write a recursive version of itoa; 
that is, convert an integer into a string by calling a recursive routine. */

void itoa(int, char[]);

int main(void) {
    char s[MAXLEN];
    int n = 12345;
    int n1 = -12345;

    itoa(n, s);
    printf("%s\n", s);
    itoa(n1, s);
    printf("%s\n", s);

    return 0;
}

// itoa: convert n to characters in s
void itoa(int n, char s[]) {
    static int i = 0, recurs = 0;

    if (n < 0) {
        n = -n;
        s[i++] = '-';
    }
    if (n / 10) {
        ++recurs;
        itoa((n / 10), s);
    }
    s[i++] = (n % 10) + '0';
    s[i] = '\0';
    if (recurs == 0) {
        i = 0;
        ++recurs;
    }
    --recurs;
}