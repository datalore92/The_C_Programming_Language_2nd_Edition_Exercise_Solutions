#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

/* Exercise 5-5: Write versions of the library functions strncpy, strncat, and 
strncmp, which operate on at most the first n characters of their argument 
strings. For example, strncpy(s, t, n) copies at most n characters of t to s. 
Full descriptions are in Appendix B. */

char* strn_cpy(char*, char*, int);
char* strn_cat(char*, char*, int);
int strn_cmp(char*, char*, int);

int main(void) {
    char s1[MAXLEN] = "peepee";
    char s2[MAXLEN] = "peepeenow mommy has to change you";
    char s3[MAXLEN] = "peepee";
    char s4[MAXLEN] = "peepeenow mommy has to change you";
    int n1 = 7;
    // testing strn_cpy
    //printf("%s\n", strn_cpy(s2, s1, n1));  // testing with my version
    //printf("%s\n\n", strncpy(s4, s3, n1));  // testing with the string.h version

    // testing strn_cat
    //printf("%s\n", strn_cat(s2, s1, n1));  // testing with my version
    //printf("%s\n\n", strncat(s4, s3, n1));  // testing with the string.h version

    // testing strn_cmp
    printf("%d\n", strn_cmp(s2, s1, n1));  // testing with my version
    printf("%d\n\n", strncmp(s4, s3, n1));  // testing with the string.h version

    return 0;
}

/* Copy at most n characters of string ct to s; return s. Pad with '\0's if 
ct has fewer than n characters. */
char* strn_cpy(char *s, char *ct, int n) {
    unsigned i;
    char *s_i, *ct_i;

    for (i = 0, s_i = s, ct_i = ct; i < n; ++i) {
        // if *ct == '\0' && *s_i != '\0', then stop incrementing ct and just copy '\0' to s
        if (!(*ct_i) && *s_i) {
            *s_i++ = '\0';
        }
        else {
            *s_i++ = *ct_i++;
        }
    }
    return s;
}

/* Concatenate at most n characters of string ct to string s, terminate s with 
'\0'; return s. */
char* strn_cat(char *s, char *ct, int n) {
    unsigned i;
    char *s_i = s, *ct_i;

    // go to end of s
    while (*s_i) {
        ++s_i;
    }
    // concatenate
    for (i = 0, ct_i = ct; i < n; ++i) {
        // if ct_i is a character, then copy it to s_i
        if (*ct_i) {
            *s_i++ = *ct_i++;
        }
        // else, just terminate s_i
        else {
            *s_i == '\0';
        }
    }
    return s;
}

/* Compare at most n characters of string cs to string ct; return <0 if cs<ct, 
0 if cs==ct, or >0 if cs>ct. */
int strn_cmp(char *cs, char *ct, int n) {
    unsigned i;

    for (char *ct_i = ct, *cs_i = cs, i = 0; i < n; ++i, ++ct_i, ++cs_i) {
        if (*cs_i < *ct_i) {
            return -1;
        }
        else if (!(*cs_i) && !(*ct_i)) {
            return 0;
        }
        else if (*cs_i > *ct_i) {
            return 1;
        }
    }
    return 0;
}