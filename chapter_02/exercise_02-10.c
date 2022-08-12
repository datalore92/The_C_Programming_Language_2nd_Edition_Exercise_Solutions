#include <stdio.h>
#include <ctype.h>

/* Exercise 2-10: Rewrite the function lower, which converts upper case 
letters to lower case, with a conditional expression instead of if-else. */

/* lower: convert c to lower case; ASCII only 
int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    else {
        return c;
    }
} */

int lower(int);

int main(void) {
    printf("%c\n", lower('G'));

    return 0;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}