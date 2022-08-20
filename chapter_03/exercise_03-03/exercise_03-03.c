#include <stdio.h>
#include <ctype.h>

/* Exercise 3-3: Write a function expand(s1, s2) that expands shorthand 
notations like a-z in the string s1 into the equivalent complete list abc...xyz in 
s2. Allow for letters of either case and digits, and be prepared to handle cases 
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally. */

int expand_pt2(char[], char[], int, int);
void expand_pt1(char[], char[]);

int main(void) {
    char s1[] = "The numbers 0-9. The letters a-z. The letters A-Z.\n Leading \
    and trailing hypens -a -b -c -1 -2 -3 4- 5- d- e-\n And the example tests\
    a-b-c a-z0-9 -a-z\n";
    char s2[100000];

    expand_pt1(s1, s2);
    printf("%s\n", s2);

    return 0;
}

int expand_pt2(char s1[], char s2[], int i1, int i2) {
    int beg_char = s1[i1 - 1] + 1;
    int end_char = s1[i1 + 1];
    
    for (; beg_char != end_char; ++beg_char) {
        s2[i2++] = beg_char;
    }
    return i2;
}

void expand_pt1(char s1[], char s2[]) {
    int end_char, beg_char;
    // iterate through s1
    for (int i1 = 0, i2 = 0; s1[i1] != '\0'; ++i1) {
        // check for '-' characters
        if (s1[i1] == '-') {
            // lower case check
            if (s1[i1 - 1] > 96 && s1[i1 - 1] < 123 && s1[i1 + 1] > s1[i1 - 1] && s1[i1 + 1] < 123) {
                i2 = expand_pt2(s1, s2, i1, i2);
            }
            // upper case check
            else if (s1[i1 - 1] > 64 && s1[i1 - 1] < 91 && s1[i1 + 1] > s1[i1 - 1] && s1[i1 + 1] < 91) {
                i2 = expand_pt2(s1, s2, i1, i2);
            }
            // number check
            else if (s1[i1 - 1] > 47 && s1[i1 - 1] < 58 && s1[i1 + 1] > s1[i1 - 1] && s1[i1 + 1] < 58) {
                i2 = expand_pt2(s1, s2, i1, i2);
            }
            else {
                s2[i2++] = s1[i1];
            }
        }
        // if not '-'
        else {
            s2[i2++] = s1[i1];
        }
    }
}