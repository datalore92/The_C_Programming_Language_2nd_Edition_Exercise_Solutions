#include <stdio.h>

/* Exercise 5-14: Modify the sort program to handle a -r flag, which indicates 
sorting in reverse (decreasing) order. Be sure that -r works with -n. */

#include <string.h>
#define MAXLINES 5000   // max #lines to be sorted
char *lineptr[MAXLINES];    // pointers to text lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
void reverse(void *lineptr[], int left, int right);
int numcmp(char *, char *);

// sort input lines
int main(int argc, char *argv[]) {
    int nlines;     // number of input lines read
    int numeric = 0;    // 1 if numeric sort
    int reversal = 0;   // 1 if sort in decreasing order

    /*if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }*/
    // need to deal with "-r", "r", "-n", "n", "-rn", "rn", "-nr", "nr" possibilities
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {    // for every string in argv
            if (!strcmp(argv[i], "-n") || !strcmp(argv[i], "n")) {
                numeric = 1;
            }
            else if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "r")) {
                reversal = 1;
            }
            else if (!strcmp(argv[i], "-rn") || !strcmp(argv[i], "-nr") || !strcmp(argv[i], "rn") || !strcmp(argv[i], "nr")) {
                reversal = 1;
                numeric = 1;
            }
            else {
                printf("Invalid Argument: %s\n", argv[i]);
                return -1;
            }
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        q_sort((void **) lineptr, 0, nlines - 1, (int (*)(void*, void*)) (numeric ? numcmp : strcmp));
        if (reversal) {
            reverse((void **) lineptr, 0, nlines - 1);
        }
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("input too big to sort\n");
        return 1;
    }
}

// reverse: reverses the order of all the elements in the array
void reverse(void *v[], int left, int right) {
    void swap(void *v[], int, int);

    if (left >= right) {    // do nothing if array contains fewer than two elements
        return;
    }
    swap(v, left, right);
    reverse(v, left + 1, right - 1);
}

// qsort: sort v[left]... v[right] into increasing order
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) {      // do nothing if array contains fewer than two elements
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    q_sort(v, left, last - 1, comp);
    q_sort(v, last + 1, right, comp);
}

#include <stdlib.h>

// numcmp: compare s1 and s2 numerically
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    }
    else if (v1 > v2) {
        return 1;
    }
    else {
        return 0;
    }
}

// swaps two elements
void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXLEN 1000     // max length of any input line
int get_line(char *, int);
char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {
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

// writelines: write output lines
void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

// getline: read a line into s, return length
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000     // size of available space

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;     // next free position

// return pointer to n characters
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {       // it fits
        allocp += n;
        return allocp - n;      // old p
    }
    else {      // not enough room
        return 0;
    }
}