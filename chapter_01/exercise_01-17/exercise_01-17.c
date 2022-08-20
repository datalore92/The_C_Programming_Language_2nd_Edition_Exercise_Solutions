#include <stdio.h>

/* Exercise 1-17: Write a program to print all input lines that are longer than 80 
  characters. */ 

#define MAXLENGTH    1000                    /* max length of input line */ 
#define EIGHTY_CHARS 80                      /* if line characters exceed this value, then print the line */ 

// function declaration that gets input lines, returns length
int get_line(char line[], int maxline);

int main() {
  char line[MAXLENGTH];
  int len;
  // get line 
  while ((len = get_line(line, MAXLENGTH)) > 0) {
  // print line if greater than 80 characters
  if (len > EIGHTY_CHARS)
    printf("%s", line);
  }

  return 0;
}

// function definition that gets input lines, returns length 
int get_line(char line[], int maxline) {
  int c, i;
  printf("Please input a line of text: \n");
  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i++] = c;
  }
  line[i] = '\0';
  return i;
}
