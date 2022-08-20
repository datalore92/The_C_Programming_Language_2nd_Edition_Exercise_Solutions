#include <stdio.h>

/* Exercise 2-8: Write a function rightrot(x, n) that returns the value of the 
integer x rotated to the right by n bit positions. */

int rightrot(int, int);

int main(void) {
    int x = 10, n = 2;
    printf("%ld\n", rightrot(x, n));

    return 0;
}

int rightrot(int x, int n) {
    int z;
    // x = 0000 0000 0000 0000 0000 0000 0000 1010
    // n = 2
    // result should be 1000 0000 0000 0000 0000 0000 0000 0010
    // or 2147483650
    for (int i = 0; i < n; ++i) {
        // find out if the rightmost bit of x is a 1
        if (1 & x) {
            // rightmost bit is a 1
            // right shift by 1
            x = x >> 1;
            // now turn the leftmost bit into a 1
            z = 1;                                    // z == 0000 0000 0000 0000 0000 0000 0000 0001
            z = z << ((sizeof(int) * 8) - 1);         // z == 1000 0000 0000 0000 0000 0000 0000 0000
            x = x | z;
        }
        // if rightmost bit of x is not a 1
        else {
            // rightmost bit is a 0
            // right shift by 1
            x = x >> 1;
        }
    }
    return x;
}