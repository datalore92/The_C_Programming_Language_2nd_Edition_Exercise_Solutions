#include <stdio.h>
#define STRSIZE 10000

/* Exercise 5-3: Write a pointer version of the function strcat that we showed 
in Chapter 2: strcat(s, t) copies the string t to the end of s. */

void str_cat(char*, const char*);

int main(void) {
    char s[STRSIZE] = "peepee";
    const char t[] = "poopoo";
    str_cat(s, t);
    printf("%s\n", s);

    return 0;
}

// str_cat: concatenate t to end of s
void str_cat(char *s, const char *t) {
    while (*s) {
        ++s;
    }
    while (*t) {
        *s++ = *t++;
    }
    *s = '\0';
}