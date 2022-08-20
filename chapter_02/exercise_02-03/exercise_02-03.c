#include <stdio.h>
// Section 2.7 Page 43, the book says: "We will use the <ctype.h> functions from now on."
// although i didn't use it for this program
#include <ctype.h>

/* Exercise 2-3: Write the function htoi(s), which converts a string of 
hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. 
The allowable digits are 0 through 9, a through f, and A through F. */ 

int htoi(char[]);

int main(void) {
  // test strings
  char s1[]  = "7E6";    // DEC = 2022
  char s2[]  = "0x7E6";  // DEC = 2022
  char s3[]  = "0X7E6";  // DEC = 2022
  char s4[]  = "7C8";    // DEC = 1992
  char s5[]  = "0x7C8";  // DEC = 1992
  char s6[]  = "0X7C8";  // DEC = 1992
  char s7[]  = "D";      // DEC = 13
  char s8[]  = "0xD";    // DEC = 13
  char s9[]  = "0XD";    // DEC = 13
  char s10[] = "10";     // DEC = 16
  char s11[] = "0x10";   // DEC = 16
  char s12[] = "0X10";   // DEC = 16
  char s13[] = "2";      // DEC = 2   
  char s14[] = "0x2";    // DEC = 2
  char s15[] = "0X2";    // DEC = 2
  char s16[] = "a";      // DEC = 10

  printf("%s = %d\n", s1, htoi(s1));  
  printf("%s = %d\n", s2, htoi(s2));  
  printf("%s = %d\n", s3, htoi(s3));  
  printf("%s = %d\n", s4, htoi(s4));  
  printf("%s = %d\n", s5, htoi(s5));  
  printf("%s = %d\n", s6, htoi(s6));  
  printf("%s = %d\n", s7, htoi(s7));  
  printf("%s = %d\n", s8, htoi(s8));  
  printf("%s = %d\n", s9, htoi(s9));  
  printf("%s = %d\n", s10, htoi(s10));  
  printf("%s = %d\n", s11, htoi(s11));  
  printf("%s = %d\n", s12, htoi(s12));  
  printf("%s = %d\n", s13, htoi(s13));  
  printf("%s = %d\n", s14, htoi(s14));  
  printf("%s = %d\n", s15, htoi(s15));  
  printf("%s = %d\n", s16, htoi(s16));  


  return 0;
}

int htoi(char s[]) {
  // formula for hex to dec is the following:
  // (7E6) = (7 * 16^2) + (14 * 16^1) + (6 * 16^0) = 2022
  int exp_num = 0, res_num = 0, pow_num = 16;
  
  // check to see if the first 2 characters of the string are "0x" or "0X"
  // if so, then remove them
  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    int i1 = 0, i2 = 2;
    for (; s[i2] != '\0'; ++i1, ++i2) {
      s[i1] = s[i2];
    }
    s[i1] = '\0';
  }
  
  // count the number of characters in the hex number string
  // the number of characters will be your exponent
  for (exp_num = 0; s[exp_num] != '\0'; ++exp_num) {
  }

  // loops through all the characters
  for (int i = 0, num_chars = exp_num; i < num_chars; ++i) {
    // check if uppercase
    if (s[i] > 64 && s[i] < 71) {
      // get 16 to the power of (exp_num - 1)
      // if exp_num - 1 == 0, then 16 to the power of 0 is 1
      if (exp_num - 1 == 0) {
        pow_num = 1;
      }
      else {
        for (int j = 1; j < exp_num - 1; ++j) {
          pow_num *= 16;
        }
      }
      // final result equals final result + ((16^(exp_num - 1)) * the 
      // current character converted to decimal)
      res_num += pow_num * (s[i] - 55);
      // reset pow_num to 16
      pow_num = 16;
      // decrease exp_num because of the way the formula works
      --exp_num;
    }
    // check if lowercase
    if (s[i] > 96 && s[i] < 103) {
      // get 16 to the power of (exp_num - 1)
      // if exp_num - 1 == 0, then 16 to the power of 0 is 1
      if (exp_num - 1 == 0) {
        pow_num = 1;
      }
      else {
        for (int j = 1; j < exp_num - 1; ++j) {
          pow_num *= 16;
        }
      }
      // final result equals final result + ((16^(exp_num - 1)) * the 
      // current character converted to decimal)
      res_num += pow_num * (s[i] - 87);
      // reset pow_num to 16
      pow_num = 16;
      // decrease exp_num because of the way the formula works
      --exp_num;
    }
    // check if number
    if (s[i] > 47 && s[i] < 58) {
      // get 16 to the power of (exp_num - 1)
      // if exp_num - 1 == 0, then 16 to the power of 0 is 1
      if (exp_num - 1 == 0) {
        pow_num = 1;
      }
      else {
        for (int j = 1; j < exp_num - 1; ++j) {
          pow_num *= 16;
        }
      }
      // final result equals final result + ((16^(exp_num - 1)) * the 
      // current character converted to decimal)
      res_num += pow_num * (s[i] - 48);
      // reset pow_num to 16
      pow_num = 16;
      // decrease exp_num because of the way the formula works
      --exp_num;
    }
  }
  return res_num;
}