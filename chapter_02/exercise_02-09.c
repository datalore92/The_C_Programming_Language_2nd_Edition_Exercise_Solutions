#include <stdio.h>
#include <ctype.h>

/* Exercise 2-9: In a two's complement number system, x &= (x - 1) deletes 
the rightmost 1-bit in x. Explain why. Use this observation to write a faster 
version of bitcount. */

/* ANSWER:
0000 1010 = x
0000 1001 = x - 1
0000 1000 = x &= x - 1

0000 1000 = x
0000 0111 = x - 1
0000 0000 = x &= x - 1

(x - 1) flips every bit from the rightmost 1-bit of x to the end. Then the & 
operation turns every one of those bits into a 0-bit.  Utilizing this method 
is an effective alternative way to count the number of 1-bits in a binary number 
if it's in a loop. */

/* bitcount: count 1 bits in x 
int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }
    return b;
}
*/

int bitcount(unsigned);

int main(void) {
    unsigned int x = 0;
    printf("%d\n", bitcount(x));

    return 0;
}

int bitcount(unsigned x) {
    int b;
    while (x > 0) {
        x &= (x - 1);
        ++b;
    }
    return b;
}