
// Example 7-10: day of year calculation

#include <stdio.h>

int main()
{
    int year = 2024, month = 11, day = 18;

    int days_in_month[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // Non-leap year
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // Leap year
    };

    int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int day_of_year = 0;
    for (int m = 1; m < month; m++)
    {
        day_of_year += days_in_month[is_leap][m];
    }
    day_of_year += day;

    printf("Date: %d-%02d-%02d is the %dth day of the year %d.\n", year, month, day, day_of_year, year);

    return 0;
}