
#include <stdio.h>

void print_upper_left_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_upper_right_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n - i; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void print_upper_equicrural_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n - i; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void print_lower_left_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_lower_right_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i - 1; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= n - i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void print_lower_equicrural_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i - 1; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= 2 * (n - i) + 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

int main()
{
    int n = 5;

    // print_upper_left_triangle(n);
    // print_upper_right_triangle(n);
    // print_upper_equicrural_triangle(n);

    // print_lower_left_triangle(n);
    // print_lower_right_triangle(n);
    // print_lower_equicrural_triangle(n);

    print_upper_equicrural_triangle(n);
    print_lower_equicrural_triangle(n);

    return 0;
}