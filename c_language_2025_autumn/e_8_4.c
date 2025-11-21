
// Example 8-4: return several values from a function using pointers

#include <stdio.h>

void month_day(int year, int day_of_year, int *pmonth, int *pday)
{
    int days_in_month[][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Non-leap year
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // Leap year
    };

    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int month = 1;
    while (day_of_year > days_in_month[leap][month]) {
        day_of_year -= days_in_month[leap][month];
        month++;
    }
    *pmonth = month;
    *pday = day_of_year;
}

int main()
{
    int year = 2025, day_of_year = 324;
    int month = 0, day = 0;

    month_day(year, day_of_year, &month, &day);
    printf("Year: %d, Day of year: %d => Month: %d, Day: %d\n", year, day_of_year, month, day);

    return 0;
}