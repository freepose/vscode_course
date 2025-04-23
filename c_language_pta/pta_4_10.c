
/*  */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, k;
    int n = 9;
    char ch = 'B';

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= abs(i - n / 2 - 1); j++)
        {
            printf(" ");
        }
        for (k = 1; k <= n/2+5-2 * abs(i - n/2-1); k++)
        {
            if (k == 1 || k == n/2+5-2 * abs(i -n/2-1))
            {
                printf("%c", ch - abs(i - n/2 - 1) + n / 2);
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
