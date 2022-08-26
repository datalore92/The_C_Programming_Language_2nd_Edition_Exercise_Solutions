#include <stdio.h>
#define MATCH 1
#define NOMATCH 0

/* Exercise 5-4: Write the function strend(s, t) which returns 1 if the string 
t occurs at the end of the string s, and zero otherwise. */

int str_end(char*, char*);

int main(void) {
    char s1[] = "peepeepoopoo";
    char t1[] = "poopoo";
    char s2[] = "start";
    char t2[] = "star";

    printf("%d\n", str_end(s1, t1));
    printf("%d\n", str_end(s2, t2));

    return 0;
}

int str_end(char *s, char *t) {
    for (char *s_i = s, *t_i = t, *s_marker; *s_i; ++s_i) {
        if (*s_i == *t_i) {
            s_marker = s_i;
            while (*s_i == *t_i && *s_i) {
                ++s_i;
                ++t_i;
            }
            if (!(*s_i) && !(*t_i)) {
                return MATCH;
            }
            else {
                s_i = s_marker;
                t_i = t;
            }
        }
    }
    return NOMATCH;
}