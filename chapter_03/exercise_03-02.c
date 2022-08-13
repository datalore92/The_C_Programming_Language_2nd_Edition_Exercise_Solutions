#include <stdio.h>
#include <ctype.h>

/* Exercise 3-2: Write a function escape(s, t) that converts characters like 
newline and tab into visible escape sequences like \n and \t as it copies the 
string t to s. Use a switch. Write a function for the other direction as well, 
converting escape sequences into the real characters. */

#define MAX 10000

void real(char[], char[]);
void escape(char[], char[]);

int main(void) {
    char t[MAX];
    char s[MAX];
    int c, i = 0;
    printf("INPUT: \n");
    while ((c = getchar()) != EOF) {
        t[i++] = c;
    }

    //escape(t, s);
    real(t, s);
    printf("%s\n", s);

    return 0;
}

/* copies characters from string t to string s and converts 
the escape sequences into regular */
void real(char t[], char s[]) {
    int i1, i2;

    for (i1 = i2 = 0; t[i1] != '\0'; ++i1) {
        switch (t[i1]) {
            case '\\':
                switch (t[i1 + 1]) {
                    case 't':
                        s[i2++] = '\t';
                        ++i1;
                        break;
                    case 'n':
                        s[i2++] = '\n';
                        ++i1;
                        break;
                    case 'b':
                        s[i2++] = '\b';
                        ++i1;
                        break;
                    case '\\':
                        s[i2++] = '\\';
                        ++i1;
                        break;
                    case '\'':
                        s[i2++] = '\'';
                        ++i1;
                        break;
                    case '\"':
                        s[i2++] = '\"';
                        ++i1;
                        break;
                    default:
                        s[i2++] = t[i1];
                        break;
                }
                break;
            default:
                s[i2++] = t[i1];
                break;
        }
    }
    s[i2] = '\0';
}

/* copies characters from string t to string s and converts 
the characters like newline and tab into visible escape sequences */
void escape(char t[], char s[]) {
    int i1, i2;

    for (i1 = i2 = 0; t[i1] != '\0'; ++i1) {
        switch (t[i1]) {
            case '\t':
                s[i2++] = '\\';
                s[i2++] = 't';
                break;
            case '\n':
                s[i2++] = '\\';
                s[i2++] = 'n';
                break;
            case '\b':
                s[i2++] = '\\';
                s[i2++] = '\b';
                break;
            case '\\':
                s[i2++] = '\\';
                s[i2++] = '\\';
                break;
            case '\'':
                s[i2++] = '\\';
                s[i2++] = '\'';
                break;
            case '\"':
                s[i2++] = '\\';
                s[i2++] = '\"';
                break;
            default:
                s[i2++] = t[i1];
                break;
        }
    }
    s[i2] = 0;
}