
// Example 7-10: Define the function day_of_year(year, month, day) to calculate and return the corresponding day of the year for the given year, month, and day.

#include <stdio.h>

int day_of_year(int year, int month, int day)
{
    int k, leap;
    int tab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);

    for (k = 1; k < month; k++)
    {
        day = day + tab[leap][k];
    }

    return day;
}

int main(void)
{
    int day, month, year;

    printf("Enter year, month, day: ");
    scanf("%d%d%d", &year, &month, &day);
    printf("%d\n", day_of_year(year, month, day));

    return 0;
}
