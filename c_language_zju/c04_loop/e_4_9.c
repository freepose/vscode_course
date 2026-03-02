
// Example 4-9: Fibonacci sequence problem.
// Input a positive integer n (1<=n<=46) and output the first n terms of the Fibonacci sequence: 1, 1, 2, 3, 5, 8, 13,..., with 5 terms per line. The Fibonacci sequence is defined such that any term is the sum of the previous two terms (the first two terms are both defined as 1).

#include <stdio.h>

int main(void)
{
    int i, n, x1, x2, x;

    printf("Enter n: ");
    scanf("%d", &n);
    if (n < 1 || n > 46)
    {
        printf("Invalid.\n");
    }
    else if (n == 1)
    {
        printf("%10d", 1);
    }
    else
    {
        x1 = 1;
        x2 = 1;
        printf("%10d%10d", x1, x2);
        for (i = 3; i <= n; i++)
        {
            x = x1 + x2;
            printf("%10d", x);
            if (i % 5 == 0)
            {
                printf("\n");
            }
            x1 = x2;
            x2 = x;
        }
    }

    return 0;
}

// Enter n: 10
// 1         1        2         3        5
// 8        13       21        34       55