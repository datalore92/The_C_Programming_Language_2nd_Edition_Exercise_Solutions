#include <stdio.h>

/* Exercise 1-20: Write a program "detab" that replaces tabs in the input with the 
proper number of blanks to space to the next tab stop.  Assume a fixed set of 
tab stops, say every n columns.  Should n be a variable or a symbolic parameter? */ 

#define BLANKS_PER_TAB 6
#define MAXINPUT       10000

char input[MAXINPUT];
char output[MAXINPUT];

void get_input(void);
void detab(void);
void copy(void);

int main() {
  printf("INPUT:\n");
  get_input();
  detab(); 
  copy();
  printf("OUTPUT:\n%s", input);

  return 0;    
}

void get_input(void) {
  int c, i;
  extern char input[];

  for (i = 0; i < MAXINPUT - 1 && (c = getchar()) != EOF; ++i) {
    input[i] = c;
  }
  input[i] = '\0';
}

void detab(void) {
  int i, i2;
  extern char input[];
  extern char output[];

  for (i = 0, i2 = 0;  i < MAXINPUT - 1 && input[i] != '\0'; ++i, ++i2) {
    if (input[i] == '\t') {
      ++i;
      for (int i3 = 0; i3 < BLANKS_PER_TAB; ++i3, ++i2) {
        output[i2] = ' ';
      }
    }
    output[i2] = input[i];
  }
  output[i2] = '\0';
}

void copy(void) {
  int i, i2;
  extern char input[];
  extern char output[];

  for (i = 0, i2 = 0; i < MAXINPUT - 1 && i2 < MAXINPUT - 1 && output[i2] != '\0'; ++i, ++i2) {
    input[i] = output[i2];
  }
  input[i] = '\0';
}