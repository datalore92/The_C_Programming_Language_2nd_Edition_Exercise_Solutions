#include <stdio.h>

#define ON 1
#define OFF 0
#define LIM 10

/* for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
     s[i] = c; */

/* Exercise 2-2: Write a loop equivalent to the for loop above without using && or ||. */ 

int main(void) {
  int i;
  char s[LIM], c, loop;
  
  // /*
  printf("INPUT: ");
  for (i = 0, loop = ON; loop; ++i) {
    if (!(i < LIM - 1)) {
      loop = OFF;
    }
    else if (!((c = getchar()) != '\n')) {
      loop = OFF;
    }
    else if (!(c != EOF)) {
      loop = OFF;
    }
    else {
      s[i] = c;
    }
  }
  --i;
  s[i] = '\0';
  printf("OUTPUT: %s\n", s);
  // */

   /* // used this for comparing to the loop I made
  printf("INPUT: ");
  // example loop
  for (i = 0; i < LIM - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    s[i] = c;
  }
  s[i] = '\0';
  printf("OUTPUT: %s\n", s);
   */

  return 0;
}
