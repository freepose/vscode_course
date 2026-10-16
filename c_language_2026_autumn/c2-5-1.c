
#include <stdio.h>

int main()
{
    int year = 2000;

    // while (year <= 2026)
    for ( ; year <= 2026; )
    {
        year = year + 5;
    }

    printf("year = %d\n", year);

    return 0;
}