#include <stdio.h>
#include <string.h>
#include <time.h>   // for measuring the speed of the program
#define MAXLINES 5000   // max #lines to be sorted
#define MAXLEN 1000     // max length of any input line
#define ALLOCSIZE 10000 // size of available space

/* Exercise 5-7: Rewrite readlines to store lines in an array supplied by main, 
rather than calling alloc to maintain storage. How much faster is the program? */

/* The program's speed appears to be about the same after completing the exercise. */

char *lineptr[MAXLINES];    // an array of pointers to text lines
char allocbuf[ALLOCSIZE];    // storage for alloc
char *allocp = allocbuf;     // next free position
// for speed testing = next two lines
char strngs[] = "hello world\nthis is a line\nand here is another line\nfinal line\njk, one more line\nthen one final last line\n"; 

int readlines1(char*[], int);
int readlines2(char*[], int, char[]);
void writelines(char*[], int);
void qsort(char*[], int, int);
int get_line(char*, int);
char* alloc(int);

/* sort input lines */
int main(void) {
    int nlines;     // number of input lines read
    double time_spent = 0.0;    // for speed testing
    clock_t begin;
    clock_t end;

    //testing old book version
    
    begin = clock();
    if ((nlines = readlines1(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        //return 0;
    }
    else {
        printf("error: input too big to sort\n");
        //return 1;
    }
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    
    //testing my version
/*
    begin = clock();
    if ((nlines = readlines2(lineptr, MAXLINES, allocbuf)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        //return 0;
    }
    else {
        printf("error: input too big to sort\n");
        //return 1;
    }
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
*/
    printf("readlines1: %lf\n", time_spent);

    return 0;
}

/* OLD readlines: read input lines */
int readlines1(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }
        else {
            line[len - 1] = '\0';   // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* MY readlines: read input lines */
int readlines2(char *lineptr[], int maxlines, char allocbuf[]) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (allocbuf + ALLOCSIZE - allocp < len)) {
            return -1;
        }
        else {
            allocp += len;
            p = allocp - len;
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

char *alloc(int n) {    // return pointer to n characters
    if (allocbuf + ALLOCSIZE - allocp >= n) {   // it fits
        allocp += n;
        return allocp - n;  // old p
    }
    else {      // not enough room
        return 0;
    }
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

/* qsort: sort v[left]... v[right] into increasing order */
void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) {    // do nothing if array contains fewer than 2 elements
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* getline: read a line into s, return length */
int get_line(char *s, int lim) {
    int c, i;
    static int i2 = 0;

    if (strngs[i2] == '\0') {
        strngs[i2] = EOF;
    }

    for (i = 0; i < lim - 1 && (c = strngs[i2]) != EOF && c != '\n'; ++i, ++i2) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
        ++i2;
    }
    s[i] = '\0';
    return i;
}

