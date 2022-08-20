#include <stdio.h>
#include <string.h>         // for strlen()  NOTE: doesn't include the '\0' character
#define NOTFOUND -1

/* Exercise 4-1: Write the function strrindex(s, t), which returns the 
position of the rightmost occurrence of t in s, or -1 if there is none. */

/* NOTE: been kinda working on my comments on this exercise */

int strrindex(const char[], const char[]);

int main(void) {
    const char s[] = "daaaa ";
    const char pattern[] = "a";

    printf("RIGHTMOST OCCURRENCE INDEX OF \"%s\" in \"%s\": %d\n", pattern, s, strrindex(s, pattern));

    return 0;
}

int strrindex(const char s[], const char t[]) {
    unsigned ctr = 1;                       // ctr is used to count how many times in a row the chars in t match s
    const unsigned s_len = strlen(s);       // length of string s
    const unsigned t_len = strlen(t);       // length of string t
    int s_i1, s_i2, t_i1;                   // iterators for s and t, s_i2 will be used for resetting the index of s in case of failed match

    for (s_i1 = s_i2 = s_len - 1, t_i1 = t_len -1; s_i1 >= 0; --s_i1, --s_i2) {               // iterate backwards from s until the beginning of the string
        if (s[s_i1] == t[t_i1]) {                                                             // if the last char from t matches the current char from s
            for (; ctr < t_len && s[s_i1] == t[t_i1] && t_i1 != 0; ++ctr, --s_i1, --t_i1) {}  // while the chars match
            if (ctr == t_len && s[s_i1] == t[t_i1]) {                                         // if ctr equals length of t and the last chars match
                return s_i1;                                                                  // return the current index of s
            }
            else {                                                                            // doesn't match
                t_i1 = t_len - 1;                                                             // reset the t iterator
                s_i1 = s_i2;                                                                  // reset the s iterator back to when it started comparing chars with t
                ctr = 1;                                                                      // reset ctr so it can start the count over again next time
            }
        }
    }
    return NOTFOUND;                                                                          // no match found
}