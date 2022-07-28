#include <stdio.h>

/* Exercise 1-14: Write a program to print a histogram of the frequencies of 
different characters in its input. */ 

#define ARR_SIZE    128 
#define ASCII_START 32

main() {
  int arr[ARR_SIZE] = {0}, i, j, c = 0;
  while ((c = getchar()) != EOF)
    ++arr[c];
  // print histogram 
  for (i = ASCII_START; i < ARR_SIZE; ++i) {
    printf("\n%c: ", i);
    for (j = 0; j < arr[i]; ++j) {
      putchar('-');
    }
  }
}
