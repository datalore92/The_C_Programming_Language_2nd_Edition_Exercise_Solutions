#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Exercise 3-5: Write the function itob(n, s, b) that converts the integer n 
into a base b character representation in the string s. In particular, 
itob(n, s, 16) formats n as a hexadecimal integer in s. */

void reverse(char s[]);
void itob(int, char[], int);

int main(void) {
    char s[10000];
    itob(11259375, s, 16);
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

void itob(int n, char s[], int b) {
    // formula: 
    // quotient = n/b
    // remainder = n%b
    int quotient = n;
    int remainder, i;

    for (i = 0; quotient != 0; ++i) {
        remainder = quotient % b;               
        quotient = quotient / b;                
        // convert remainder to character and add it to s
        // you're gonna have to reverse s in the end because it's doing this in reverse order
        if (remainder > 9) {
            s[i] = 'A' + remainder - 10;
        }
        else {
            s[i] = '0' + remainder;
        }
    }
    reverse(s);
}