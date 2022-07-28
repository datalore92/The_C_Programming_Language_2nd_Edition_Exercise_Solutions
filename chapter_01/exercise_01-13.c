#include <stdio.h>

/* Exercise 1-13: Write a program to print a histogram of the lengths of words in 
its input.  It is easy to draw the histogram with the bars horizontal; a vertical 
orientation is more challenging. */ 

#define ARRAY_SIZE        1000
#define HISTOGRAM_END     10

main() 
{
  // declare variables and array
  int arr[ARRAY_SIZE], c, i = 0, i2, words_greater_than_ten = 0, i3, char_counter = 0;
  while (i < ARRAY_SIZE) { 
    arr[i] = 0;
    ++i;
  }
  i = 0;
  // explain what the program does
  printf("This program prints a histogram of the lengths of words in its input. \n Go ahead and start typing in words and hit ENTER when you are finished.\n >> ");
  // create loop and get input
  while ((c = getchar()) != EOF && char_counter < ARRAY_SIZE) {
    ++char_counter;
    // if not white space, then ++i 
    if (c != ' ' && c != '\t' && c != '\n') 
      ++i;
    // if white space, then update array, reinitialize i to 0
    else {
      ++arr[i];
      i = 0;
    }   
    if (c == '\n')
      c = EOF;
  }
  // draw the histogram 
  for (i = 1; i < HISTOGRAM_END; ++i) {
    printf("\nWords with a length of   %d: ", i);
    for (i2 = 0; i2 < arr[i]; ++i2) {
      putchar('-');
    }
  }
  // add up all the values of words greater than 10
  for (i3 = 10; i3 < ARRAY_SIZE; ++i3) {
    words_greater_than_ten = words_greater_than_ten + arr[i3];
  }
  // append the histogram with the value of words greater than 10
  printf("\nWords with a length of %d+: ", i);
  for (i3 = 0; i3 < words_greater_than_ten; ++i3)
    putchar('-');
  putchar('\n');

  return 0;
}
