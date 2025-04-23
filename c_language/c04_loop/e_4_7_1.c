
// Example 4-7-1: Using functions to calculate the sum of factorials. Calculate 1! + 2! + 3! + ... + n!.
// It is required to define and call the function fact(n) to calculate the factorial of n.
// If n is a non-negative integer, the function returns the factorial of n; otherwise, it returns 0.

#include <stdio.h>

double fact(int n);

int main(void)
{
    int i, n;
    double sum;

    printf("Enter n: ");
    scanf("%d", &n);
    sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum = sum + fact(i);
    }
    printf("1! + 2! + ... + %d! = %.0f\n", n, sum);

    return 0;
}

double fact(int n)
{
    int i;
    double result;

    if (n < 0)
    {
        return 0;
    }
    result = 1;
    for (i = 1; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}

// Enter n: 15
// 1! + 2! + ... + 15! = 1401602636313