#include <stdio.h>

/* Exercise 1-15: Rewrite the temperature conversion program of Section 1.2 to 
  use a function for conversion. */ 

/* print Fahrenheit-Celsius table
  for fahr = 0, 20, ..., 300 */ 

int f_to_c(int f);

int main() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;    /* lower limit of temperature table */ 
  upper = 300;  /* upper limit */ 
  step = 20; ;  /* step size */ 
  
  fahr = lower;
  while (fahr <= upper) {
    //celsius = 5 * (fahr - 32) / 9;        /* deprecated */
    celsius = f_to_c(fahr);
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
}

/* f_to_c: Convert fahrenheit to celsius */ 
int f_to_c(int f) {
  return (5 * (f - 32) / 9);
}
