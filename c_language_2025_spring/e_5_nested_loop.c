
// Nest loops 循环标记控制法

#include <stdio.h>
#include <math.h>

void print_left_triangle(int n)
{
    /// @brief Print a left triangle pattern.
    /// @param n : the number of rows in the triangle.

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void print_right_triangle(int n)
{
    /// @brief Print a right triangle pattern.
    /// @param n : the number of rows in the triangle.

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
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

void print_isosceles_triangle(int n)
{
    /// @brief Print an isosceles triangle pattern. 等腰三角形
    /// @param n : the number of rows in the triangle.

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
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

void print_down_left_triangle(int n)
{
    /// @brief Print a down left triangle pattern.
    /// @param n : the number of rows in the triangle.

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void print_down_right_triangle(int n)
{
    /// @brief Print a down right triangle pattern.
    /// @param n : the number of rows in the triangle.
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i - 1; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= n - i + 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

// down isosceles triangle
void print_down_isosceles_triangle(int n)
{
    /// @brief Print a down isosceles triangle pattern.
    /// @param n : the number of rows in the triangle.

    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i - 1; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= (n - i + 1) * 2 - 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void print_diamond(int n)
{
    /// @brief Print a diamond pattern.
    /// @param n : the number of rows in the triangle.

    for (int i = 1; i <= n; i++)
    {
        int mid = (n / 2) + 1; 

        for (int j = 1; j <= abs(mid - i); j++)
        {
            printf(" ");
        }
        
        int k_max = 2 * (mid - abs(i - mid)) - 1;
        for (int k = 1; k <= k_max; k++)
        {
            if (k == 1 || k == k_max)
            {
                printf("%c", mid - abs(i - mid) + 'A' - 1);
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

    // print_left_triangle(n);
    // print_right_triangle(n);
    // print_isosceles_triangle(n);
    // print_down_left_triangle(n);
    // print_down_right_triangle(n);
    // print_down_isosceles_triangle(n);

    print_diamond(n);

    return 0;
}