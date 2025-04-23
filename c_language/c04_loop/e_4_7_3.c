
// Example 4-7-3: Calculate 1! + 2! + 3! + ... + n! using a single loop.
// It is required to use a single loop to calculate the factorial of n and accumulate the sum.

#include <stdio.h>

int main(void)
{
    int i, n;
    double item, sum;

    printf("Enter n: ");
    scanf("%d", &n);
    sum = 0;
    item = 1;
    for (i = 1; i <= n; i++)
    {
        item = item * i;
        sum = sum + item;
    }
    printf("1! + 2! + ... + %d! = %.0f\n", n, sum);

    return 0;
}

// Enter n: 15
// 1! + 2! + ... + 15! = 1401602636313