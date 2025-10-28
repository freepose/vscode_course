
// Example 5-6

#include <stdio.h>
#include <stdlib.h>

void print_up_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int k = 1; k <= n - i; k++)
        {
            printf(" ");
        }

        // stars
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void print_down_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int k = 1; k <= i; k++)
        {
            printf(" ");
        }

        // stars
        for (int j = 1; j <= 2 * (n - i + 1) - 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void print_diamond(int n)
{
    // Ensure n is odd for a symmetric diamond
    int mid = n / 2 + 1;

    print_up_triangle(mid);
    print_down_triangle(mid - 1);
}


void print_hollow_diamond(int n)
{
    int mid = n / 2 + 1;

    for (int i = 1; i <= n; i++)
    {
        int spaces = abs(mid - i);

        for (int j = 1; j <= spaces; j++)
        {
            printf(" ");
        }

        int stars = 2 * (mid - spaces) - 1; // 修改：用mid计算星号数量
        for (int k = 1; k <= stars; k++)
        {
            if (k == 1 || k == stars)
            {
                printf("*");
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
    int n = 9; // Must be an odd number
    
    print_diamond(n);
    printf("\n");

    print_hollow_diamond(n);
    printf("\n");

    return 0;
}