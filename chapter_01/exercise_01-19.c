#include <stdio.h>
#define MAXLENGTH 10000

/* Exercise 1-19: Write a function reverse(s) that reverses the character 
string s.  Use it to write a program that reverses its input a line at a time. */ 

void reverse_string(char input_string[], char output_string[]);
void get_string(char input_string[], int maxlength);

int main() {
  char input_string[MAXLENGTH];
  char output_string[MAXLENGTH];

  printf("THIS PROGRAM REVERSES YOUR INPUT ONE LINE AT A TIME.\nINPUT:\n");
  get_string(input_string, MAXLENGTH);
  reverse_string(input_string, output_string);
  printf("OUTPUT:\n%s", output_string);

  return 0;
}

void get_string(char input_string[], int maxlength) {
  int c, i;
  for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF; ++i) {
    input_string[i] = c;
  }
  input_string[i] = '\0';
}

void reverse_string(char input_string[], char output_string[]) {
  int input_index = 0;
  int output_index = 0;
  int input_counter = 0;

  while (input_string[input_index] != '\0') {
    while (input_string[input_index] != '\n') {
      ++input_index;
      ++input_counter;
    }
    ++input_index;
    --input_counter;
    while (input_counter >= 0 && input_string[input_counter] != '\n' && input_string[input_counter] != '\0') {
      output_string[output_index++] = input_string[input_counter--];
    }
    output_string[output_index++] = '\n';
    input_counter = input_index;
  }
  output_string[output_index] = '\0';
}
