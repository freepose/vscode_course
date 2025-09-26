
// 今天是今年的第几天

#include <stdio.h>

int main()
{
    int year = 2025, month = 4, day = 21;

    int days_in_month[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30}, // 非闰年
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30}  // 闰年
    };

    int is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int day_of_year = 0;

    for (int i = 1; i < month; i++)
    {
        day_of_year += days_in_month[is_leap_year][i];
    }
    day_of_year += day;

    printf("%d-%d-%d is the %dth day of the year.\n", year, month, day, day_of_year);

    return 0;
}