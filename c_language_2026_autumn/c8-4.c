
#include <stdio.h>

void month_day(int year, int day_of_year, int *p_month, int *p_day)
{
    int tab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    int leap = (leap % 4 == 0 && leap % 100 != 0) || (year % 400 == 0);

    int k;
    for (k = 1; day_of_year > tab[leap][k]; k++)
    {
        day_of_year -= tab[leap][k];
    }

    *p_month = k;
    *p_day = day_of_year;

}

int main()
{
    int year = 2026, day_of_year = 280, month, day;
    char *str_month[13] = {
        "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    month_day(year, day_of_year, &month, &day);
    printf("%d - %d is %s %d", year, day_of_year, str_month[month], day);

    return 0;
}