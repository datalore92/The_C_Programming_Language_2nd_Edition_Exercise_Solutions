#include <stdio.h>

/* Exercise 1-23: Write a program to remove all comments from a C program. 
Don't forget to handle quoted strings and character constants properly. C 
comments do not nest. */ 

#define MAXINPUT 200000

void remover(char input[], char output[]);

int main() {
  char input[] = "\"/\"\n\"string with //a comment in it\"\ntesting /*this is a comment */\n\"string with / a single slash in it\"\n/";
  char output[MAXINPUT];

  remover(input, output);
  printf("INPUT:\n%s\nOUTPUT:\n%s\n", input, output);

  return 0;
}

void remover(char input[], char output[]) {
  int i, i2;

  for (i = i2 = 0; input[i] != '\0';) {
    if (input[i] == '/' && input[i + 1] == '/' && input[i - 1] != '\'') {
      while (input[i++] != '\n') {
      }
      --i;
    }
    else if (input[i] == '/' && input[i + 1] == '*') {
      i += 2;
      while (input[i] != '*' && input[i + 1] != '/') {
        ++i;
      }
      i += 2;
    }
    else {
      output[i2++] = input[i++];
    }
  }
  output[i2] = '\0';
}