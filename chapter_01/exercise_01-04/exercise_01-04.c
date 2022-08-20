#include <stdio.h>

/* Exercise 1-4: Write a program to print the 
corresponding Celsius to Fahrenheit table. */

/* print Fahrenheit-Celsius table
  for fahr = 0, 20, ..., 300 */ 
main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;      /* lower limit of temperature table */ 
  upper = 300;    /* upper limit */ 
  step = 20;      /* step size */ 
  celsius = lower;

  /* Print a heading above the table */ 
  printf("\nCelsius-Fahrenheit Table\n");

  while (celsius <= upper) {
    fahr = ((celsius * (9.0/5.0)) + 32.0);
    printf("%9.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
  printf("\n");
}
