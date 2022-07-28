#include <stdio.h>

/* Exercise 1-8: Write a program to count blanks, tabs, and newlines. */

main()
{
  int c, blanks = 0, tabs = 0, nl = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ')
      ++blanks;
    if (c == '\t')
      ++tabs;
    if (c == '\n')
      ++nl;
  }

  // print results
  printf("Blanks: %d\nTabs: %d\nNewLines: %d\n", blanks, tabs, nl);

  return 0;
}
