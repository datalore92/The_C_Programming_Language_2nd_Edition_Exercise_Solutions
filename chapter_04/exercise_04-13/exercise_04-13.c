#include <stdio.h>
#include <string.h> // for strlen()

/* Exercise 4-13: Write a recursive version of the function reverse(s), which 
reverses the string s in place. */

void reverse(char[]);

int main(void) {
    char s[] = "Fifth";
    char s1[] = "Cell Phones";

    reverse(s);
    printf("%s\n", s);
    reverse(s1);
    printf("%s\n", s1);

    return 0;
}

void reverse(char s[]) {
    static int c, i = 0, j, levels = 0;

    if (levels == 0) {
        j = strlen(s) - 1;
    }
    ++levels;
    if (i < j && levels > 0) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        ++i;
        --j;
        reverse(s);
    }
    else {
        i = 0;
    }
    --levels;
}