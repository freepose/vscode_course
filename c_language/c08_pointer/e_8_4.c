
// Example 8-4: Input year and day, output corresponding year, month, and day.
// Define and call the function month_day(int year, int yearday, int *pmonth, int *pday), where year is the year, yearday is the day, and the variables pointed to by pmonth and pday save the calculated month and day.

#include <stdio.h>

int main(void)
{
    int day, month, year, yearday;
    void month_day(int year, int yearday, int *pmonth, int *pday);

    printf("input year and yearday: ");
    scanf("%d%d", &year, &yearday);
    month_day(year, yearday, &month, &day);
    printf("%d-%d-%d \n", year, month, day);

    return 0;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int k, leap;
    int tab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    };

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    for (k = 1; yearday > tab[leap][k]; k++)
    {
        yearday -= tab[leap][k];
    }
    *pmonth = k;
    *pday = yearday;
}

// input year and yearday: 2000 61
// 2000-3-1 