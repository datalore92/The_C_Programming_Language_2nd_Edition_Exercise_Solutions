#include <stdio.h>

/* Exercise 1-12: Write a program that prints its input one word per line. */ 
#define BLANK     ' '
#define NEWLINE   '\n'
#define TAB       '\t'
#define ON        1 
#define OFF       0

main() 
{
  int c = ' ', first_word_state = ON;

  while (c != EOF) {
    // if c is a blank/tab/nl and first word state is on
    while ((c == BLANK || c == NEWLINE || c == TAB) && first_word_state == ON && c != EOF) {
      c = getchar();
      // if c is a letter and first word state is on
      if (c != BLANK && c != NEWLINE && c != TAB && first_word_state == ON && c != EOF) {
        first_word_state = OFF;
      }
    }
    // if c is a letter and first word state is off
    while (c != BLANK && c != NEWLINE && c != TAB && first_word_state == OFF && c != EOF) {
      putchar(c);
      c = getchar();
    }
    putchar('\n');
    first_word_state = ON;
  }
}
