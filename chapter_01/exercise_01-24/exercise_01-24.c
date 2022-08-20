#include <stdio.h>

/* Exercise 1-24: Write a program to check a C program for rudimentary syntax 
errors like unbalanced parentheses, brackets and braces. Don't forget about 
quotes, both single and double, escape sequences, and comments. (This program 
is hard if you do it in full generality.) */ 

// i need to implement a push pop stack to do this i think

#define MAXINPUT 100000

void push(char c, char stack[]);
void pop(char stack[]);
int stack_checker(char c, char stack[]);
void checker(char input[], char stack[]);
void end_stack(char stack[]);

int main() {
  char input[] = "\"(')}]{[(')\"";
  char stack[MAXINPUT];

  checker(input, stack);
  //check the stack to see if there are any leftover characters, if so, then print a warnings
  end_stack(stack);

  return 0;
}

/* comment for visualization of stack: 
if input is something like "(')')"
push "
push (
push '
if ), then pop (
if ', then pop '
pop )
pop "
so you need to check what the last pushed character was before popping to make sure that 
you are popping the right one off the stack.
so with a proper checker function it would look like this:
push "
push (
push '
check what last character pushed on the stack was
it is '
skip )
pop '
pop )
pop "
so you need a push function, a pop function, and a checker function. 
give the checker function the character you're asking if should be popped. */

//function that checks the stack for leftover characters at the end of the program
void end_stack(char stack[]) {
  int i;
  for (i = 0; stack[i] != '\0'; ++i) {
    if (stack[i] == '(') {
      printf("WARNING: UNBALANCED PARENTHESIS\n");
    }
    else if (stack[i] == '[') {
      printf("WARNING: UNBALANCED BRACKETS\n");
    }
    else if (stack[i] == '{') {
      printf("WARNING: UNBALANCED BRACES\n");
    }
    else if (stack[i] == '\'') {
      printf("WARNING: UNBALANCED SINGLE QUOTES\n");
    }
    else if (stack[i] == '"') {
      printf("WARNING: UNBALANCED DOUBLE QUOTES\n");
    }
    else if (stack[i] == '/') {
      printf("WARNING: UNBALANCED COMMENTS\n");
    }
  }
}

//function for pushing chars on stack
void push(char c, char stack[]) {
  int i;
  for (i = 0; stack[i] != '\0'; ++i) {
  }
  stack[i++] = c;
  stack[i] = '\0';
}

//function for popping chars off stack
void pop(char stack[]) {
  int i;
  for (i = 0; stack[i] != '\0'; ++i) {
  }
  if (i > 0) {
    --i;
    stack[i] = '\0';
  }
}

//function for checking the last character on the stack and returning 1 for if it's the same character, or 0 if not
int stack_checker(char c, char stack[]) {
  int i;
  for (i = 0; stack[i] != '\0'; ++i) {
  }
  if (i > 0) {
    --i;
    if (stack[i] == c)
      return 1;
    else
     return 0;
  }
  else
    return 0;
}

void checker(char input[], char stack[]) {
  int i; char par_1 = '('; char par_2 = ')'; char brack_1 = '['; char brack_2 = ']'; char brace_1 = '{'; char brace_2 = '}';
  char s_quot_1 = '\''; char s_quot_2 = '\''; char d_quot_1 = '"'; char d_quot_2 = '"'; char comm_a_1 = '/'; char comm_a_2 = '/';
  char comm_a_3 = '\n'; char comm_b_1 = '/'; char comm_b_2 = '*'; char comm_b_3 = '*'; char comm_b_4 = '/'; 

  for (i = 0; input[i] != '\0'; ++i) {
    // if input[i] == (, and last char on stack is not " or ', then push (
    if (input[i] == par_1 && !(stack_checker(s_quot_1, stack)) && !(stack_checker(d_quot_1, stack))) {
      push(par_1, stack);
    }
    // if input[i] == ) and last char on stack is (, then pop
    else if (input[i] == par_2 && stack_checker(par_1, stack)) {
      pop(stack);
    }
    // if input[i] == [, and last char on stack is not " or ', then push [
    else if (input[i] == brack_1 && !(stack_checker(s_quot_1, stack)) && !(stack_checker(d_quot_1, stack))) {
      push(brack_1, stack);
    }
    // if input[i] == ] and last char on stack is [, then pop
    else if (input[i] == brack_2 && stack_checker(brack_1, stack)) {
      pop(stack);
    }
    // if input[i] == {, and last char on stack is not " or ', then push {
    else if (input[i] == brace_1 && !(stack_checker(s_quot_1, stack)) && !(stack_checker(d_quot_1, stack))) {
      push(brace_1, stack);
    }
    // if input[i] == } and last char on stack is {, then pop
    else if (input[i] == brace_2 && stack_checker(brace_1, stack)) {
      pop(stack);
    }
    // if input[i] == ' and last character on stack is NOT ' or ", then push '
    else if (input[i] == s_quot_1 && !(stack_checker(s_quot_1, stack)) && !(stack_checker(d_quot_1, stack))) {
      push(s_quot_1, stack);
    }
    // if input[i] == ' and last character on stack is ', then pop
    else if (input[i] == s_quot_1 && stack_checker(s_quot_1, stack)) {
      pop(stack);
    }
    // if input[i] == " and last character on stack is NOT " or ', then push "
    else if (input[i] == d_quot_1 && !(stack_checker(d_quot_1, stack)) && !(stack_checker(s_quot_1, stack))) {
      push(d_quot_1, stack);
    }
    // if input[i] == " and last char on stack is ", then pop
    else if (input[i] == d_quot_1 && stack_checker(d_quot_1, stack)) {
      pop(stack);
    }
    // if input[i] == / and input[i+1] == / and last char on stack is not " or ', then proceed to the end of the comment
    else if (input[i] == comm_a_1 && input[i + 1] == comm_a_2 && !(stack_checker(s_quot_1, stack)) && !(stack_checker(d_quot_1, stack))) {
      while (input[i] != '\n') {
        ++i;
      }
    }
    else if (input[i] == comm_b_1 && input[i + 1] == comm_b_2 && !(stack_checker(s_quot_1, stack)) && !(stack_checker(d_quot_1, stack))) {
      push(comm_a_1, stack);
    }
    else if (input[i] == comm_b_3 && input[i + 1] == comm_b_4 && (stack_checker(comm_a_1, stack))) {
      pop(stack);
    }
  }
}