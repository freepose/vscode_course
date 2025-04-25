
// 7-3 Linear Search / Brute Force Search

#include <stdio.h>

int main()
{
    short a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};
    short x = 89;
    int is_found = 0;   // flag

    for (int i = 0; i < 10; i++)
    {
        if (a[i] == x) 
        {
            printf("Found %d at index %d\n", x, i);
            is_found = 1;
            break;
        }
    }

    if (is_found == 0)
    {
        printf("Not found %d\n", x);
    }

    return 0;
}