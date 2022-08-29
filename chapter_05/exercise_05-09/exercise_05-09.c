#include <stdio.h>
#include <stdint.h>  // just learned about this header and wanted to use it, haha

/* Exercise 5-9: Rewrite the routines day_of_year and month_day with 
pointers instead of indexing. */

int_least16_t day_of_year(uint_least16_t, uint_least8_t, int_least16_t);
void month_day(uint_least16_t, uint_least16_t, int_least8_t*, int_least8_t*);

static const char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void) {
    uint_least8_t month = 8;  // august 
    int_least16_t day = 27;
    uint_least16_t year = 2022;
    int_least8_t pday;
    int_least8_t pmonth;
    uint_least16_t yearday;

    printf("Day of year is: %d\n", yearday = day_of_year(year, month, day));
    month_day(year, yearday, &pmonth, &pday);
    printf("Month: %d, Day: %d\n", pmonth, pday);

    return 0;
}

// day_of_year: set day of year from month & day. returns -1 if invalid date
int_least16_t day_of_year(uint_least16_t year, uint_least8_t month, int_least16_t day) {
    uint_least8_t i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    //if (month > 12 || month < 1 || day < 1 || day > daytab[leap][month]) {    // OLD
    if (month > 12 || month < 1 || day < 1 || day > *(*(daytab + leap) + month)) {
        return day = -1;  // invalid date
    }
    for (i = 1; i < month; i++) {
        //day += daytab[leap][i];   // OLD
        day += *(*(daytab + leap) + i);
    }
    return day;
}

// month_day: set month, day from day of year. stores -1 in *pmonth and *pday if invalid date.
void month_day(uint_least16_t year, uint_least16_t yearday, int_least8_t *pmonth, int_least8_t *pday) {
    uint_least8_t i, leap;


    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if ((leap && yearday > 366) || yearday < 1 || (!leap && yearday > 365)) {
        *pmonth = -1;   // invalid date
        *pday = -1;  // invalid date
    }
    else {
        //for (i = 1; yearday > daytab[leap][i]; i++) {     // OLD
        for (i = 1; yearday > *(*(daytab + leap) + i); i++) {
            //yearday -= daytab[leap][i];   // OLD
            yearday -= *(*(daytab + leap) + i);
        }
        *pmonth = i;
        *pday = yearday;
    }
}