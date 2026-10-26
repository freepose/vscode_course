
#include <stdio.h>
#include <math.h>

void print_upper(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // print spaces
        for (int k = 1; k <= n - i; k++)
        {
            printf(" ");
        }

        // print stars
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j == 1 || j == 2 * i - 1)
            {
                printf("%c", 'A' + i - 1);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n = 9;

    // print_upper(n);

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = n; j >= i; j--)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    int mid = n / 2 + 1;

    for (int i = 1; i <= n; i++)
    {
        // k_max + j_max = mid
        int k_max = abs(i - mid);
        for (int k = 1; k <= k_max; k++)
        {
            printf(" ");
        }

        int j_max = 2 * (mid - k_max) - 1;
        for (int j = 1; j <= j_max; j++)
        {
            if (j == 1 || j == j_max)
            {
                printf("%c", 'A' + i - 1);
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