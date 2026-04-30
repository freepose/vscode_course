

#include <stdio.h>

int day_of_year(int year, int month, int day)
{
    int leap = ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
    int days[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int sum = 0;

    for (int i = 1; i < month; i++)
    {
        sum += days[leap][i];
    }
    sum += day;

    return sum;
}

void month_day(int year, int day_of_year, int *pmonth, int *pday)
{
    int leap = ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0);
    int days[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    int k;
    for (k = 1; day_of_year > days[leap][k]; k++)
    {
        day_of_year -= days[leap][k];
    }

    *pmonth = k;
    *pday = day_of_year;
}

int main()
{
    int d = day_of_year(2026, 4, 30);
    int month, day;

    printf("2026-04-30 is the %d-th day of 2026\n", d);

    month_day(2026, 120, &month, &day);

    printf("2026 120th day is %d-%d-%d\n", 2026, month, day);

    return 0;
}