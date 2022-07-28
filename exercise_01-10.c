#include <stdio.h>

/* Exercise 1-10: Write a program to copy its input to its output, replacing each
tab by \t, each backspace by \b, and each backslash by \\.  This makes tabs 
and backspaces visible in an unambiguous way. */ 

main()
{
  int c, d;

  while ((c = getchar()) != EOF) {
    d = 0;
    if (c == '\t') {
      putchar('\\');
      putchar('t');
      d = 1;
    }
    if (c == '\b') {
      putchar('\\');
      putchar('b');
      d = 1;
    }
    if (c == '\\') {
      putchar('\\');
      putchar('\\');
      d = 1;
    }
    if (d == 0)
      putchar(c);
  }
  return 0;
}
