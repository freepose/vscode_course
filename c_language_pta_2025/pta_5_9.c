

#include <stdio.h>

int main()
{
    int year = 2024, month = 1, day = 1, current_day_of_year = 0;

    scanf("%d/%2d/%2d", &year, &month, &day);
    int is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    for (int i = 1; i < month; i++)
    {
        int days_of_month = 0;
        switch(i)
        {
            case 1: days_of_month = 31;   break;
            case 2: days_of_month = 28 + (int)is_leap_year; break;
            case 3: days_of_month = 31;   break;
            case 4: days_of_month = 30;   break;
            case 5: days_of_month = 31;   break;
            case 6: days_of_month = 30;   break;
            case 7: days_of_month = 31;   break;
            case 8: days_of_month = 31;   break;
            case 9: days_of_month = 30;   break;
            case 10: days_of_month = 31;  break;
            case 11: days_of_month = 30;  break;
            // case 12: days_of_month = 31; break;
        }
        current_day_of_year += days_of_month;
    }

    current_day_of_year += day;
    printf("Today is the %dth day of year %d.\n", current_day_of_year, year);
    return 0;
}
