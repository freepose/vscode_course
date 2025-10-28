
// Example 5-6

#include <stdio.h>
#include <math.h>

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

int main()
{
    int n = 10;
    int mid = n / 2 + 1;

    for (int i = 1; i <= n; i++)
    {
        int spaces = abs(mid - i);

        for (int j = 1; j <= spaces; j++)
        {
            printf(" ");
        }

        int stars = 2 * (n - spaces - 3) - 1;
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

    return 0;
}