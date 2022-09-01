#include <stdio.h>
#include <ctype.h>      // for isdigit()
#include <string.h>     // for strlen()
#define MAXARRSIZE  50000
#define MAXLINESIZE  1000
#define DEFAULTNUM     10

/* Exercise 5-13: Write the program tail, which prints the last n lines of its 
input. By default, n is 10, let us say, but it can be changed by an optional 
argument, so that "tail -n" prints the last n lines. The program should behave 
rationally no matter how unreasonable the input or the value of n. Write the 
program so it makes the best use of available storage; lines should be stored as 
in the sorting program of Section 5.6, not in a two-dimensional array of fixed size. */

void linereader(void);
void printer(int n);
int strtoint(char[]);
int isnum(char[]);

char line_storage[MAXARRSIZE];      // character array for storing multiple lines
char *stor_p = line_storage;        // pointer for iteration through line_storage
char *line_starts[MAXLINESIZE];     // array of pointer to characters of line_storage
char **line_p = line_starts;        // pointer to pointer to char for iteration of line_starts
char **line_endp;                   // pointer to pointer to char at the end of line_starts

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (!isnum(*(argv + 1))) {
            printf("tail: invalid number of lines: %s\n", *(argv + 1));
            return -1;
        }
        linereader();
        printer(strtoint(*(argv + 1)));
    }
    else {
        linereader();
        printer(DEFAULTNUM);
    }

    return 0;
}

// print last n lines of line_storage
void printer(int n) {
    if (n < 0) {
        n *= -1;
    }
    while (line_endp != line_starts && n > 0) {
        --line_endp;
        --n;
    }
    printf("%s\n", *line_endp);
}

// read lines from input and store them
void linereader(void) {
    *line_p++ = stor_p;
    while ((*stor_p = getchar()) != EOF) {
        if (*stor_p == '\n') {    
            *line_p++ = ++stor_p;   
        }
        else {
            stor_p++;
        }
    }
    line_endp = --line_p;
    *stor_p = '\0';       
}

// converts a string of numbers to int
int strtoint(char s[]) {
    int num = 0, sign = 0;

    if (*s == '-') {
        --sign;
    }
    else {
        ++sign;
    }
    for (size_t i = 0; i < strlen(s); ++i) {
        while (isdigit(s[i])) {
            num += s[i++] - 48;
            num *= 10;
        }
    }
    num /= 10;
    num *= sign;
    return num;
}

// checks if a string is all numbers
int isnum(char s[]) {
    while(*s) {
        if (!(isdigit(*s)) && *s != '-') {
            return 0;
        }
        else {
            ++s;
        }
    }
    return 1;
}