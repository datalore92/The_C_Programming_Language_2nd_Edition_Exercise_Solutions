#include <stdio.h>

/* Exercise 2-6: Write a function setbits(x,p,n,y) that returns x with the n 
bits that begin at position p set to the rightmost n bits of y, leaving the other 
bits unchanged. */

int setbits(int, int, int, int);

int main(void) {
    printf("%d", setbits(8, 7, 3, 7));

    return 0;
}

int setbits(int x, int p, int n, int y) {
    // need to set all bits left of position n on y to 0
    int z = ~0;
    z = z >> n;
    z = z << n;
    z = ~z;
    // so you just made z all 1's, then you shifted right by n, then shifted left by n, 
    // so now the n right most bits are 0's while the rest are 1's. then you flipped everything 
    // so that everything is 0's except the n right most bits are 1's now.
    z = z & y;
    // this uses the & operator to AND z and y.  so now z's n rightmost bits are whatever y's 
    // n right most bits are.
    // now we need to shift z to whatever position that we need to change on x
    z = z << (p + 1 - n);
    // the bits are in position
    x = x | z;

    return x;
}

// this one was hard for me U_U'