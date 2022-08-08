#include <stdio.h>
// Section 2.7 Page 43, the book says: "We will use the <ctype.h> functions from now on."
#include <ctype.h>

/* Exercise 2-5: Write the function any(s1, s2), which returns the first location 
in the string s1 where any character from the string s2 occurs, or -1 if s1 
contains no characters from s2. (The standard library function strpbrk does 
the same job but returns a pointer to the location.) */

int any(const char s1[], const char s2[]);

int main(void) {
    const char s1[] = "abcde2fghi3jk4l";
    const char s2[] = "zyxw";
    int idx = any(s1, s2);

    if (idx != -1) {
        printf("First location in the string: %d\nCharacter: '%c'\n", idx, s1[idx]);
    }
    else {
        printf("Character not found.\n");
    }

    return 0;
}

int any(const char s1[], const char s2[]) {
    int i1, i2;
    // loop through each char in s2
    for (i2 = 0; s2[i2] != '\0'; ++i2) {
        printf("Searching for '%c'...\n", s2[i2]);                                      // for testing and debugging
        // loop through each char in s1
        for (i1 = 0; s1[i1] !='\0'; ++i1) {
            // check if the chars match
            if (s1[i1] == s2[i2]) {
                printf("Found '%c' at index: %d\n", s2[i2], i1);                        // for testing and debugging
                return i1;
            }
        }
    }
    printf("No matching characters found.\n");
    return -1;
}