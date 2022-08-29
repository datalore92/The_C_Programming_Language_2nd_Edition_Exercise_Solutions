#include <stdio.h>
#include <ctype.h>      // for isdigit()
#include <string.h>     // for strlen()

/* Exercise 5-10: Write the program expr, which evaluates a reverse Polish 
expression from the command line, where each operator or operand is a separate 
argument. For example, expr 2 3 4 + * evaluates 2 * (3 + 4). */

/* This took me like all day to write but I think I learned a lot and have a much 
better understanding of pointers */

// example arguments and their results for testing
// 4 3 2 - * == 4 * (3 - 2) == 4
// -2 -3 -4 + * == -2 * (-3 + -4) == 14
// -2 3 -4 - * == -2 * (3 - -4) == -14
// 154 33 -44 - / == 154 / (33 - -44) == 154 / 77 == 2

int strtoint(char[]);                 // converts a string to integer

int main(int argc, char *argv[]) {
    // create value stack and a pointer to it
    int value_stack[10];
    int *value_ptr = value_stack;
    int args = 1;
    int t1, t2;

    ++argv;
    // start iterating through argv and if it's a number, then add it to value stack
    for (; args < argc; ++argv, ++args, ++value_ptr) {
        if (isdigit(**argv)) {
            *value_ptr = strtoint(*argv);                                 // push
        }
        else {
            //--value_ptr;
            switch (**argv) {
                // if it's a '-', then see if the next char is a number
                case '-':
                    if (isdigit((*argv)[1])) {
                        *value_ptr = strtoint(*argv);                     // push
                    }
                    else {  // handle minus 'x - y'
                        t1 = *--value_ptr;
                        t2 = *--value_ptr;
                        *value_ptr = t2 - t1;                               // pop pop push
                    }
                    break;
                case '+':
                    t1 = *--value_ptr;
                    t2 = *--value_ptr;
                    *value_ptr = t1 + t2;                                   // pop pop push
                    break;
                case '*':
                    t1 = *--value_ptr;
                    t2 = *--value_ptr;
                    *value_ptr = t1 * t2;                                   // pop pop push
                    break;
                case '/':
                    if (*value_ptr != 0.0) {
                        t1 = *--value_ptr;
                        t2 = *--value_ptr;
                        *value_ptr = t2 / t1;                               // pop pop push
                    }
                    else {
                        printf("error: zero divisor\n");
                    }
                    break;            
                default:
                    printf("error: unknown command %s\n", *argv);
                    break;
            }
        }
    }
    printf("%d\n", *--value_ptr);

    return 0;
}

int strtoint(char s[]) {
    int num = 0, sign = 0;

    if (*s == '-') {
        --sign;
    }
    else {
        ++sign;
    }
    // say you get a string like "-34"
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