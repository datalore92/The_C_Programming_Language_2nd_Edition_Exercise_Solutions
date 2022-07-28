#include <stdio.h>

/* Exercise 1-3: Modify the temperature conversion program to 
print a heading above the table */ 

/* print Fahrenheit-Celsius table
  for fahr = 0, 20, ..., 300 */ 
main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;      /* lower limit of temperature table */ 
  upper = 300;    /* upper limit */ 
  step = 20;      /* step size */ 
  fahr = lower;

  /* Print a heading above the table */ 
  printf("\nFahrenheit-Celsius Table\n");

  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%9.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  printf("\n");
}
