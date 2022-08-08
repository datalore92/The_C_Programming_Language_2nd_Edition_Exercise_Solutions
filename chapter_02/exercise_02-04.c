#include <stdio.h>
// Section 2.7 Page 43, the book says: "We will use the <ctype.h> functions from now on."
#include <ctype.h>

/* squeeze: delete all c from s 
void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

/* Exercise 2-4: Write an alternative version of squeeze(s1, s2) that deletes 
each character in s1 that matches any character in the string s2. */

void squeeze(char s1[], char s2[]) {
    int i1, i2, i3;
    // loop through each character in s2
    for (i1 = 0; s2[i1] != '\0'; ++i1) {
        // loop through each character in s1
        for (i2 = 0, i3 = 0; s1[i2] != '\0'; ++i2) {
            if (s1[i2] != s2[i1]) {
                s1[i3++] = s1[i2];
            }
        }
        s1[i3] = '\0';
    }
}

int main(void) {
    char s1[] = "a1 b2 a1 c3 b2 d4 c3 e5 d4 f6 e5 g7 f6 h8 g7 i9 h8 i9";
    char s2[] = "ab cdefghi";

    printf("s1: %s\ns2: %s\nSQUEEZE\n", s1, s2);
    squeeze(s1, s2);
    printf("s1: %s\n", s1);

    return 0;
}