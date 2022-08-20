#include <stdio.h>

/* Write a function invert(x, p, n) that returns x with the n bits 
that begin at position p inverted (i.e., 1 changed into 0 and vice versa), 
leaving the others unchanged. */

int invert(int, int, int);

int main(void) {
    printf("%d\n", invert(255, 7, 4));

    return 0;
}

int invert(int x, int p, int n) {
    // comments for debugging purposes:
    // x = 1100 (11)11
    // p = 3
    // n = 2
    
    // a = 1111 (11)11
    int a = ~0;

    // a = 1111 (11)11
    a = a >> n;
    
    // a = 1111 (11)00
    a = a << n;
    
    // a = 1111 (00)00
    a = a << (p + 1 - n);
    
    // z = 1111 (11)11
    int z = ~0;
    
    // z = 1111 (11)11
    z = z >> n;
    
    // z = 1111 (11)00
    z = z << n;
    
    // z = 0000 (00)11
    z = ~z;
    
    // z = 0000 (00)11
    // a = 1111 (00)00
    //z|a= 1111 (00)11
    z = z | a;
    
    // z = 1111 (00)11
    // x = 1100 (11)11
    //z&x= 1100 (00)11
    x = z & x;

    return x;
}

// this one was hard for me too U_U'
// but i did it, using comments really helped me visualize it