#include <stdio.h>
#define swap(t,x,y)    {t z = x; x = y; y = z;}

/* Exercise 4-14: Define a macro swap(t,x,y) that interchanges two arguments 
of type t. (Block structure will help.) */

int main(void) {
    int a = 1, b = 2;
    printf("a = %d, b = %d\n", a, b);
    // using swap(int, a, b) should give a the value 2, and b the value 1
    swap(int, a, b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}