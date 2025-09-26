
// Example 8-4: 跟定年月日，算今天是今年第几天，day of year

#include <stdio.h>

int day_of_year(int year, int month, int day)
{
    int month_days[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    int leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int day_of_year = 0;

    for (int i = 1; i < month; i++)
    {
        day_of_year += month_days[leap_year][i];
    }

    day_of_year += day;

    return day_of_year;
}

void get_month_day(int year, int day_of_year, int *p_month, int *p_day)
{
    int month_days[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    int leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int i = 1;
    while (day_of_year > month_days[leap_year][i])
    {
        i++;
        day_of_year -= month_days[leap_year][i];
    }

    *p_month = i;
    *p_day = day_of_year;
}

int main()
{
    // int year = 2025, month = 5, day = 7;

    int year = 2025, dayofyear = 127;
    int month = 0, day = 0;

    // printf("Year: %d, Month: %d, Day: %d\n", year, month, day);
    // printf("Day of year: %d\n", day_of_year(year, month, day));

    printf("%d %dth day\n", year, dayofyear);
    get_month_day(year, dayofyear, &month, &day);
    printf("Month: %d, Day: %d\n", month, day);

    return 0;
}