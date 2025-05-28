
// symbol pymarid

#include <stdio.h>

int main()
{
    int h = 5;


    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= h - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j == 1 || j == 2 * i - 1)
            {
                printf("%c", i + 'A' - 1);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}