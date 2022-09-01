#include <stdio.h>
#include <stdlib.h>     // for atoi() and qsort()
#include <ctype.h>      // for isdigit()
#define MAXLEN 10000    // max string length

/* Exercise 5-11: Modify the programs entab and detab (written as exercises in 
Chapter 1) to accept a list of tab stops as arguments. Use the default tab 
settings if there are no arguments. */

int isnum(char[]);                      // checks if a string is all numbers
int comp(const void*, const void*);     // compares two ints (for qsort)
int def_tabstops[] = {10, 20, 30, 40};  // default tabstops if no arguments provided
char s[MAXLEN] = "\
12\t34567890123456\t7890123\n\
";
char o[MAXLEN];

/* so if the args are like 3, 6, 9, 12, 15, those are the tabstops and if a 
tab is pressed on column 9, then it will jump to column 12 to continue */
int main(int argc, char *argv[]) {
    int tabstops[100];
    int *tabstop = tabstops;
    int ntabstops;
    int col = 1;
    char **argp = ++argv;
    char *s_char = s;
    char *o_char = o;

    // check if there are args, if not, then use the default tabstops
    if (argc == 1) {
        tabstop = def_tabstops;
        ntabstops = 4;
    }
    else {
        // add the arguments to the int array tabstops
        for (ntabstops = 0; *argp; ++ntabstops) {
            if (isnum(*argp)) {
                *tabstop++ = atoi(*argp++);
            }
            else {
                printf("error: the argument you provided is not a number.");
                return -1;
            }
        }
        // sort the int array tabstops
        qsort(tabstops, argc - 1, sizeof(int), comp);
    }
    // start iterating through the string and if you see a \t, then add spaces until you reach a tabstop
    for (tabstop = tabstops; *s_char; ++col, ++s_char) {
        // if newline, then reset columns and tabstops
        if (*s_char == '\n') {
            col = 0;
            tabstop = tabstops;
        }
        else if (*s_char == '\t') {
            // iterate through tabstops until you find a tabstop that's higher than cols
            while (*tabstop <= col && tabstop != &tabstops[ntabstops]) {
                ++tabstop;
            }
            // if tabstop is greater than the column number and tabstop isn't at the last tabstop
            if (*tabstop > col && tabstop != &tabstops[ntabstops]) {
                for (; col < *tabstop; ++col) {
                    *o_char++ = ' ';
                }
            }
            // if tabstop is at the last tabstop, then make a new line and reset columns and tabstops
            else {
                *o_char++ = '\n';
                col = 0;
                tabstop = tabstops;
            }
        }
        else {
            *o_char++ = *s_char;
        }
    }
    printf("%s\n", o);

    return 0;
}

int comp(const void *elem1, const void *elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    
    if (f > s) {
        return 1;
    }
    if (s < f) {
        return -1;
    }
    return 0;
}

int isnum(char s[]) {
    while(*s) {
        if (!(isdigit(*s++))) {
            return 0;
        }
    }
    return 1;
}