#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 1000
#define NOMATCH -1

/* Exercise 5-6: Rewrite appropriate programs from earlier chapters and exercises 
with pointers instead of array indexing. Good possibilities include getline 
(Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), 
reverse (Chapter 3), and strindex and getop (Chapter 4). */

int get_line(char[], int);
int atoi(char[]);
void itoa(int, char[]);
void reverse(char[]);
int strindex(char[], char[]);

int main(void) {
    char s[MAXLEN] = "peepeepoopoo";
    char t[MAXLEN] = "peepeepoopoop";

    // testing get_line()
    //printf("TESTING get_line(): %d\n", get_line(s, MAXLEN));
    //printf("%s\n", s);
    // testing atoi()
    //printf("TESTING atoi(): %d\n", atoi(s));
    // testing itoa()
    //itoa(-555, s);
    //printf("TESTING itoa(): %s\n", s);
    // testing reverse
    //get_line(s, MAXLEN);
    //reverse(s);
    //printf("TESTING reverse(): %s\n", s);
    // testing strindex
    printf("INDEX OF STRING START: %d\n", strindex(s, t));


    return 0;
}

// getline: get line into s, return length
int get_line(char s[], int lim) {
    char *s_i = s;
    printf("INPUT: ");
    while (--lim > 0 && (*s_i = getchar()) != EOF && *s_i != '\n') {
        ++s_i;
    }
    if (*s_i == '\n') {
        ++s_i;
    }
    *s_i = '\0';
    return s_i - s;
}

// atoi: convert string s to integer
int atoi(char s[]) {
    int sign, n;
    char *s_i;

    for (s_i = s; isspace(*s_i); ++s_i) {
        ;
    }
    sign = (*s_i == '-') ? -1 : 1;
    if (*s_i == '+' || *s_i == '-') {
        ++s_i;
    }
    for (n = 0; isdigit(*s_i); ++s_i) {
        n = 10 * n + (*s_i - '0');
    }
    return sign * n;
}

// itoa: convert n to characters in s
void itoa(int n, char *s) {
    int sign;
    char *s_i = s;

    if ((sign = n) < 0) {
        n = -n;
    }    
    do {
        *s_i++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        *s_i++ = '-';
    }
    *s_i = '\0';
    reverse(s);
}

// reverse: reverse a string s in place
void reverse(char s[]) {
    int c;
    char *s_beg = s;
    char *s_end = s + strlen(s) - 1;

    for (; s_beg < s_end; ++s_beg, --s_end) {
        c = *s_beg;
        *s_beg = *s_end;
        *s_end = c;
    }
}

// strindex: return index of t in s, -1 if none
int strindex(char s[], char t[]) {
    for (char *s_i = s, *t_i = t, *s_marker; *s_i; ++s_i) {
        if (*s_i == *t_i) {
            s_marker = s_i;
            while (*s_i == *t_i && *s_i) {
                ++s_i;
                ++t_i;
            }
            if (!(*t_i)) {
                return s_marker - s;
            }
            else {
                s_i = s_marker;
                t_i = t;
            }
        }
    }
    return NOMATCH;
}
