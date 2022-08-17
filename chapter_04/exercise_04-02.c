#include <stdio.h>
#include <ctype.h>

/* Exercise 4-2: Extend atof to handle scientific notation of the form: 
    123.45e-6
where a floating-point number may be followed by e or E and an optionally 
signed exponent. */

double atof(char[]);

int main(void) {
    char s1[] = "101.55e-1";
    char s2[] = "-102.55e-2";
    char s3[] = "+103.56e-3";
    char s4[] = "104.55e4";
    char s5[] = "-105.54e+5";
    char s6[] = "+106.52e7";
    char s7[] = "100";
    char s8[] = "-100";

    printf("%f\n", atof(s1));
    printf("%f\n", atof(s2));
    printf("%f\n", atof(s3));
    printf("%f\n", atof(s4));
    printf("%f\n", atof(s5));
    printf("%f\n", atof(s6));
    printf("%f\n", atof(s7));
    printf("%f\n", atof(s8));

    return 0;
}

double atof(char s[]) {
    double val, power;
    unsigned i, power_2;
    char sign;

    for (i = 0; isspace(s[i]); i++)                             // skips whitespace
        ;
    sign = (s[i] == '-') ? -1 : 1;                              // gets the sign
    if (s[i] == '+' || s[i] == '-')                             // skips the sign character
        i++;
    for (val = 0.0; isdigit(s[i]); i++)                         // while character is a digit
        val = 10.0 * val + (s[i] - '0');                        // gets the value of the digits
    if (s[i] == '.')                                            // checks for decimal point and skips it
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {                     // for every digit after the decimal
        val = 10.0 * val + (s[i] - '0');                        // val is multiplied by 10 and the character is converted to a digit and added to val
        power *= 10.0;                                          // power is multiplied by 10
    }
    val = sign * val / power;                                   // val = value of string converted (without exponents)
    if (s[i] == 'e' || s[i] == 'E') {                           // checks for exponent and increments the iterator if there is one
        ++i;
        sign = (s[i] == '-') ? -1 : 1;                          // checks if positive or negative exponent
        if (s[i] == '+' || s[i] == '-')                         // increments the iterator if there's a sign character
            ++i;
        for (power_2 = 0; isdigit(s[i]); ++i)                   // converts exponent from string
            power_2 = 10 * power_2 + (s[i] - '0');
        if (sign == 1) {
            for (power = 10.0; 0 < power_2 - 1; --power_2)      // gets the positive value of 10 * 10epower
                power *= 10;
        }
        else {
            for (power = 10.0; 0 < power_2 + 1; --power_2)      // gets the negative value of 10 * 10epower
                power /= 10;
        }
    }    
    return val * power;                                         // returns the value of the string converted
}