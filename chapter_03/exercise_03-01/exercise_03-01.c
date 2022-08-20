#include <stdio.h>
#include <ctype.h>
#include <time.h>       // for measuring the run-time of the different functions

/* Exercise 3-1: Our binary search makes two tests inside the loop, when one 
would suffice (at the price of more tests outside). Write a version with only one 
test inside the loop and measure the difference in run-time. */

int binsearch1(int, int[], int);
int binsearch2(int, int[], int);

int main(void) {
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;
    int x = 2;
    
    clock_t t;
    
    t = clock();
    printf("%d\n", binsearch1(x, v, n));
    t = clock() - t;
    double time_taken = ((double) t)/CLOCKS_PER_SEC;  // in seconds
    printf("binsearch1() took %f seconds to execute \n", time_taken);
    
    t = clock();
    printf("%d\n", binsearch2(x, v, n));
    t = clock() - t;
    time_taken = ((double) t)/CLOCKS_PER_SEC;
    printf("binsearch2() took %f seconds to execute \n", time_taken);


    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1] */ 

int binsearch1(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        }
        else if (x > v[mid]) {
            low = mid + 1;
        }
        else {                      // found match
            return mid;
        }
    }
    return -1;                      // no match
}


int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (x == v[mid]) {
        return mid;
    }
    else {
        return -1;
    }
}