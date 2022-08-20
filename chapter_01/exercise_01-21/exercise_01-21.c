#include <stdio.h>

/* Exercise 1-21: Write a program entab that replaces strings of blanks by the 
minimum number of tabs and blanks to achieve the same spacing.  Use the 
same tab stops as for detab.  When either a tab or a single blank would suffice 
to reach a tab stop, which should be given preference? */

#define BLANKS_PER_TAB 2
#define MAX_INPUT      10000

char input[MAX_INPUT];
char output[MAX_INPUT];

void get_input(void);
void entab(void);
void copy(void);

int main() {
  printf("INPUT:\n");
  get_input();
  entab();
  copy();
  printf("OUTPUT:\n%s", input);
  
  return 0;
}

void get_input(void) {
  int c, i;
  extern char input[];

  for (i = 0; i < MAX_INPUT - 1 && (c = getchar()) != EOF; ++i) {
    input[i] = c;
  }
  input[i] = '\0';
}

void entab(void) {
  int space_cntr, tab_cntr, in_i, out_i;
  extern char input[];
  extern char output[];
  
  for (space_cntr = tab_cntr = in_i = out_i = 0; input[in_i] != '\0';) {
    if (input[in_i] != ' ') {
      output[out_i++] = input[in_i++]; 
    }
    while (input[in_i] == ' ') {
      ++space_cntr;
      ++in_i;
      while (space_cntr >= BLANKS_PER_TAB) {
        output[out_i++] = '\t';
        space_cntr -= BLANKS_PER_TAB;
      }
    }
    for (int i = 0; i < space_cntr; ++i) {
      output[out_i++] = ' '; 
    }
    space_cntr = 0;
  }
}

void copy(void) {
  int i, i2;
  extern char input[];
  extern char output[];

  for (i = 0, i2 = 0; i < MAX_INPUT - 1 && i2 < MAX_INPUT - 1 && output[i2] != '\0'; ++i, ++i2) {
    input[i] = output[i2];
  }
  input[i] = '\0';
}