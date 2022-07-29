#include <stdio.h>

/* Exercise 1-18: Write a program to remove trailing blanks and tabs from each 
  line of input, and to delete entirely blank lines. */ 

#define MAXTEXTLENGTH          10000      // max length of text

void get_text(char text[], int max_text_length);
void blank_remover(char input_text[], char output_text[]);

int main() {
  char input_text[MAXTEXTLENGTH];
  char output_text[MAXTEXTLENGTH];

  get_text(input_text, MAXTEXTLENGTH);  
  blank_remover(input_text, output_text);
  printf("\nThe new edited text: \n%s", output_text);

  return 0;
}

void get_text(char input_text[], int max_text_length) {
  printf("Please enter text: \n");
  int i, c; 
  
  for (i = 0; i < max_text_length - 1 && (c = getchar()) != EOF; ++i) {
    input_text[i] = c;
  }
  input_text[i] = '\0';
}

/* NOTE: I wasn't sure by the description of the exercise, if for example, if there's a tab, then a space, and a tab, like "\t \t",
if I should just keep it like that, since technically I think they're not trailing tabs or spaces.  So I didn't accomodate the program 
to fix that or things of that nature */
void blank_remover(char input_text[], char output_text[]) {
  char previous_character = '\0';
  char current_character = '\0';
  int output_index = 0;

  for (int input_index = 0; input_text[input_index] != '\0'; ) {
    current_character = input_text[input_index++];
    while ((previous_character == current_character) && ((current_character == ' ' && previous_character == ' ') || (current_character == '\t' && previous_character == '\t') || (current_character == '\n' && previous_character == '\n'))) {
      current_character = input_text[input_index++];
    }
    output_text[output_index++] = current_character;
    previous_character = current_character;
  }
  output_text[output_index] = '\0';
}
