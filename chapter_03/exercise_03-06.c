#include <stdio.h>
#include <string.h>

/* Exercise 3-6: Write a version of itoa that accepts three arguments instead of 
two. The third argument is a minimum field width; the converted number must 
be padded with blanks on the left if necessary to make it wide enough. */

void reverse(char[]);
void itoa(int, char[], int);

int main(void) {
    char s[10000];
        
    itoa(-10000, s, 10);
    printf("%s\n", s);
    itoa(-5000, s, 10);
    printf("%s\n", s);
    itoa(-1000, s, 10);
    printf("%s\n", s);
    itoa(-500, s, 10);
    printf("%s\n", s);
    itoa(-100, s, 10);
    printf("%s\n", s);
    itoa(-50, s, 10);
    printf("%s\n", s);
    itoa(-10, s, 10);
    printf("%s\n", s);
    itoa(-5, s, 10);
    printf("%s\n", s);
    
    itoa(0, s, 10);
    
    printf("%s\n", s);
    itoa(5, s, 10);
    printf("%s\n", s);
    itoa(10, s, 10);
    printf("%s\n", s);
    itoa(50, s, 10);
    printf("%s\n", s);
    itoa(100, s, 10);
    printf("%s\n", s);
    itoa(500, s, 10);
    printf("%s\n", s);
    itoa(1000, s, 10);
    printf("%s\n", s);
    itoa(5000, s, 10);
    printf("%s\n", s);
    itoa(10000, s, 10);
    printf("%s\n", s);

    return 0;
}

void reverse(char s[]) {
    int i1, i2, c;
    for (i1 = 0, i2 = strlen(s) - 1; i1 < i2; ++i1, --i2) {
        c = s[i1];
        s[i1] = s[i2];
        s[i2] = c;
    }
}

void itoa(int n, char s[], int w) {
    int i, sign, j1, j2 = 1;

    if ((sign = n) < 0) {         // record sign
        n = -n;                 // make n positive 
        ++j2;                   // account for the - sign
    }
    // count how many chars there are going to be
    j1 = n;
    do {
        j1 /= 10;
        ++j2;
    } while (j1 != 0);
    i = 0;
    do {                        // generate digits in reverse order
        s[i++] = n % 10 + '0';  // get next digit
    } while ((n /= 10) > 0);    // delete it
    if (sign < 0) 
        s[i++] = '-';
    // add the space characters
    for (w -= j2; w > 0; --w) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}