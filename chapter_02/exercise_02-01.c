#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Exercise 2-1: Write a program to determine the ranges of char, short, int, 
and long variables, both signed and unsigned, by printing appropriate 
values from standard headers and by direct computation. Harder if you compute 
them: determine the ranges of the various floating-point types. */ 

#define UNSIGNED_MIN 0

int main(void) {
  signed char c1_low; signed char c1_high; signed short i1_low; 
  signed short i1_high; signed int j1_low; signed int j1_high; signed long k1_low; signed long k1_high;
  unsigned char c2_low; unsigned char c2_high; unsigned short i2_low; unsigned short i2_high; 
  unsigned int j2_low; unsigned int j2_high; unsigned long k2_low; unsigned long k2_high;
  
  // prints lowest and highest values of a signed char
  for (c1_low = 0; c1_low > -1;) {
    ++c1_low;
  }
  printf("signed char's computed lowest value is: %d\nsigned char's actual lowest value is: %d\n", c1_low, SCHAR_MIN);
  for (c1_high = 0; c1_high < 1;) {
    --c1_high;
  }
  printf("signed char's computed highest value is: %d\nsigned char's actual highest value is: %d\n\n", c1_high, SCHAR_MAX);

  // prints the lowest and highest values of an unsigned char
  for (c2_low = 1; c2_low > 0;) {
    ++c2_low;
  }
  printf("unsigned char's computed lowest value is: %d\nunsigned char's actual lowest value is: %d\n", c2_low, UNSIGNED_MIN);
  for (c2_high = 1; c2_high < 2;) {
    --c2_high;
  }
  printf("unsigned char's computed highest value is: %d\nunsigned char's actual highest value is: %d\n\n", c2_high, UCHAR_MAX);

  // prints the lowest and highest values of a signed short
  for (i1_low = 0; i1_low > -1;) {
    ++i1_low;
  }
  printf("signed short's computed lowest value is: %d\nsigned short's actual lowest value is: %d\n", i1_low, SHRT_MIN);
  for (i1_high = 0; i1_high < 1;) {
    --i1_high;
  }
  printf("signed short's computed highest value is: %d\nsigned short's actual highest value is: %d\n\n", i1_high, SHRT_MAX);

  // prints the lowest and highest values of an unsigned short
  for (i2_low = 1; i2_low > 0;) {
    ++i2_low;
  }
  printf("unsigned short's computed lowest value is: %d\nunsigned short's actual lowest value is: %d\n", i2_low, UNSIGNED_MIN);
  for (i2_high = 1; i2_high < 2;) {
    --i2_high;
  }
  printf("unsigned short's computed highest value is: %d\nunsigned short's actual highest value is: %d\n\n", i2_high, USHRT_MAX);

  // prints the lowest and highest values of a signed int
  for (j1_low = 2147483547; j1_low > -1;) {
    ++j1_low;
  }
  printf("signed int's computed lowest value is: %d\nsigned int's actual lowest value is: %d\n", j1_low, INT_MIN);
  for (j1_high = -2147483647; j1_high < 1;) {
    --j1_high;
  }
  printf("signed int's computed highest value is: %d\nsigned int's actual highest value is: %d\n\n", j1_high, INT_MAX);

  // prints the lowest and highest values of an unsigned int
  for (j2_low = 1; j2_low > 0;) {
    ++j2_low;
  }
  printf("unsigned int's computed lowest value is: %d\nunsigned int's actual lowest value is: %d\n", j2_low, UNSIGNED_MIN);
  for (j2_high = 1; j2_high < 2;) {
    --j2_high;
  }
  printf("unsigned int's computed highest value is: %u\nunsigned int's actual highest value is: %u\n\n", j2_high, UINT_MAX);

  // prints the lowest and highest values of a signed long
  for (k1_low = 9223372036854775707; k1_low > -1;) {
    ++k1_low;
  }
  printf("signed long's computed lowest value is: %ld\nsigned long's actual lowest value is: %ld\n", k1_low, LONG_MIN);
  for (k1_high = -9223372036854775707; k1_high < 1;) {
    --k1_high;
  }
  printf("signed long's computed highest value is: %ld\nsigned long's actual highest value is: %ld\n\n", k1_high, LONG_MAX);

  // prints the lowest and highest values of an unsigned long
  for (k2_low = 18446744073709551613UL; k2_low > 1;) {
    ++k2_low;
  }
  k2_low = 0;
  printf("unsigned long's computed lowest value is: %lu\nunsigned long's actual lowest value is: %d\n", k2_low, UNSIGNED_MIN);
  for (k2_high = 1; k2_high < 2;) {
    --k2_high;
  }
  printf("unsigned long's computed highest value is: %lu\nunsigned long's actual highest value is: %lu\n\n", k2_high, ULONG_MAX);
  
  // prints the lowest and highest values of a float
  printf("float's actual lowest value is: %f\n", FLT_MIN);
  printf("float's actual highest value is: %f\n\n", FLT_MAX);

  // prints the lowest and highest values of a double
  printf("double's actual lowest value is: %lf\n", DBL_MIN);
  printf("double's actual highest value is: %lf\n\n", DBL_MAX);

  // prints the lowest and highest values of a long double
  printf("long double's actual lowest value is: %Lf\n", LDBL_MIN);
  printf("long double's actual highest value is: %Lf\n\n", LDBL_MAX);
  
  return 0;
}
