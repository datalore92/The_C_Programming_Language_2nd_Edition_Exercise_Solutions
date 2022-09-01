#include <stdio.h>
#include <stdlib.h>     // for atoi() and qsort()
#include <ctype.h>      // for isdigit()
#define MAXLEN 10000

/* Exercise 5-11: Modify the programs entab and detab (written as exercises in 
Chapter 1) to accept a list of tab stops as arguments. Use the default tab 
settings if there are no arguments. */

int isnum(char[]);                      // checks if a string is all numbers
int comp(const void*, const void*);     // compares two ints (for qsort)
void to_next(int blankn, int tabsize, char *op);
int blanks(char *ip, int tabsize);
int def_tabstops[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
char input[MAXLEN] = "a bunch of               spaces\n";
char output[MAXLEN];

int main(int argc, char *argv[]) {
    int tabstops[100];              // list of tabstops
    int *tabstopp = tabstops;       // tabstop pointer
    int tabstopsn;                  // number of tabstops
    int tabsize;                    // how many spaces per tab
    char **argp = ++argv;           // pointer to argv
    char *ip = input;               // input pointer
    char *op = output;              // output pointer

    // check if there are args, if not, then use the default tabstops
    if (argc == 1) {
        tabstopp = def_tabstops;
        tabstopsn = 4;
        tabsize = def_tabstops[0];
    }
    else {
        // add the arguments to the int array tabstops
        for (tabstopsn = 0; *argp; ++tabstopsn) {
            if (isnum(*argp)) {
                *tabstopp++ = atoi(*argp++);
            }
            else {
                printf("error: the argument you provided is not a number.");
                return -1;
            }
        }
        // sort the int array tabstops
        qsort(tabstops, argc - 1, sizeof(int), comp);
        tabsize = tabstops[0];
    }
    // while iterating through input
    for (int blankn; *ip; ++ip, ++op) {
        // if blank
        if (*ip == ' ' || *ip == '\t') {
            // count how many blanks there will be in a row
            blankn = blanks(ip, tabsize);
            // add the correct number of spaces to reach the proper tabstop
            to_next(blankn, tabsize, op);
        }
        else {
            *op = *ip;
        }
    }
    printf("%s\n", input);
    printf("%s\n", output);


    return 0;
}

/* takes what column youre on, the number of blanks you have, and the pointer to input and the pointer 
to output adds the appropriate number of '\t's and ' 's. */
void to_next(int blankn, int tabsize, char *op) {
    // add the spaces first
    for (int spaces = blankn % tabsize; spaces != 0; --spaces) {
        *op++ = ' ';
    }
    // add tabs
    for (int tabs = blankn / tabsize; tabs != 0; --tabs) {
        for (int i = 0; i < tabsize; ++i) {
            *op++ = ' ';
        }
    }
}

// compares the values of two elements
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

// checks if all of a string is a number
int isnum(char s[]) {
    while(*s) {
        if (!(isdigit(*s++))) {
            return 0;
        }
    }
    return 1;
}

// counts how many blank spaces there are in a row. args are current input pointer and how many blanks are in a tab
int blanks(char *ip, int tabsize) {
    int num;

    for (num = 0; *ip == ' ' || *ip == '\t'; ++ip) {
        if (*ip == '\t') {
            num += tabsize;
        }
        else {
            ++num;
        }
    }
    return num;
}
