#include <stdio.h>

/* Exercise 1-9: Write a program to copy its input to its output, replacing each
string of one or more blanks by a single blank. */

main()
{
  int prev_char, current_char;

  // initialize current_char with getchar()
  current_char = getchar();
  // initialize prev_char with value of current_char
  prev_char = current_char;

  putchar(current_char);

  // start while loop to get character and check if EOF
  while ((current_char = getchar()) != EOF) {
    if (current_char == ' ')
      if (prev_char != ' ')
        putchar(current_char);
    if (current_char != ' ')
      if (prev_char != ' ')
        putchar(current_char);
    if (current_char != ' ')
      if (prev_char == ' ')
        putchar(current_char);
    prev_char = current_char;
  }

  return 0;
}
