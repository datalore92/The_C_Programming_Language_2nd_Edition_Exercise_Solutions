#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

/* Exercise 3-4: In a two's complement number representation, our version of 
itoa does not handle the largest negative number, that is, the value of n equal 
to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly, 
regardless of the machine on which it runs. */

/* My Answer: itoa does not handle the largest negative number because when it changes 
it to positive, you get an overflow, but you have to change it to positive in order to 
convert it to int. So what I did was increment the largest negative number by 1, so that it's 
no longer the largest negative number, then I made a token for use in the loop to sort of 
remind the function that it needs to change it back to the largest negative number when it's 
converting it to a string. */

void reverse(char[]);
void itoa(int, char[]);

int main(void) {
    char s[1000];
    int n = -2147483647;

    itoa(n, s);
    
    printf("%s\n", s);
    printf("Largest negative number is: %d\n", INT_MIN);

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

void itoa(int n, char s[]) {
    int i = 0, sign, max_neg = 0;

    if (n == INT_MIN) {
        ++n;
        ++max_neg;
    }
    if ((sign = n) < 0)     // record sign
        n = -n;             // make n positive
    do {
        if (max_neg) {
            s[i++] = n % 10 + '1';
            --max_neg;
        }
        else {
            s[i++] = n % 10 + '0';
        }
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}