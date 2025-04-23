
// Example 4-7-2: Calculate 1! + 2! + 3! + ... + n!.
// It is required to use nested loops.

#include <stdio.h>

int main(void)
{
    int i, j, n;
    double item, sum;

    printf("Enter n: ");
    scanf("%d", &n);
    sum = 0;
    for (i = 1; i <= n; i++)
    {
        item = 1;
        for (j = 1; j <= i; j++)
        {
            item = item * j;
        }
        sum = sum + item;
    }
    printf("1! + 2! + ... + %d! = %.0f\n", n, sum);

    return 0;
}

// Enter n: 15
// 1! + 2! + ... + 15! = 1401602636313