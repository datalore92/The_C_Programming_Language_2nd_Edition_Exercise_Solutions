#include <stdio.h>

/* Exercise 1-22: Write a program to "fold" long input lines into two or more 
shorter lines after the last non-blank character that occurs before the n-th 
column of input. Make sure your program does something intelligent with very 
long lines, and if there are no blanks or tabs before the specified column. */ 

#define LASTCOL  20
#define MAXINPUT 10000

void folder(void);
int skip_blank(int);

char input[] = "Public school, battle grounds. Two students, come around like loaded soldiers, packing heat. Inside \
a shotgun, gun click. To the beat, down. We shoot you down. We come around and when we blow off that trigger, get down. \
We shoot you down, we come around. The gun goes click, click, click. Ra-ta-ta-ta. Ra-ta-ta-ta-ta. Ra-ta-ta-ta-ta-ta Ra-ta-ta-ta-ta-ta.";
char output[MAXINPUT];

int main() {
  folder();
  printf("INPUT:\n%s\nOUTPUT:\n%s\n", input, output);

  return 0;
}

// if no blanks or tabs before LASTCOL, then you need to append a '-' to the letter before 
// the last column and then append a '\n'

void folder(void) {
  extern char input[];
  extern char output[];
  int i, i2, cntr;
  
  for (i = i2 = cntr = 0; input[i] != '\0'; ++cntr) {
    // if input[i] reaches the last column and input[i] equals a alphabet character, then append a "-\n" to output 
    if (cntr != 0 && cntr % (LASTCOL) == 0 && (input[i] < 121 && input[i] > 65) && (input[i - 1] < 121 && input[i - 1] > 65)) {
      output[i2++] = '-';
      output[i2++] = '\n';
      cntr = 0;
      // skip whitespace
      i = skip_blank(i);
    }
    // if input[i] == '.' or something like that, then include then append the period and add a newline
    else if (cntr != 0 && cntr % (LASTCOL) == 0 && (input[i] > 43 && input[i] < 48) || (input[i] > 57 && input[i] < 60)) {
      output[i2++] = input[i++];
      output[i2++] = '\n';
      cntr = 0;
      // skip whitespace
      i = skip_blank(i);
    }
    else if (cntr != 0 && cntr % (LASTCOL) == 0) {
      output[i2++] = ' ';
      output[i2++] = '\n';
      cntr = 0;
      // skip whitespace
      i = skip_blank(i);
    } 
    output[i2++] = input[i++];
  }
}

int skip_blank(int i) {
  extern char input[];

  while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
    ++i;
  }
  return i;
}