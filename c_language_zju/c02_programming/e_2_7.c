
// Example 2-8: given a integer n, sum of 1 to n.

// 1 + 2 + 3 + ... + n

#include <stdio.h>

int main()
{
    int i, n, sum;

    printf("Enter n: ");
    scanf("%d", &n);
    sum = 0;

    for (i = 1; i <= n; i++)
    {
        sum += i; // sum = sum + i
    }

    printf("Sum of numbers from 1 to %d = %d\n", n, sum);

    return 0;
}


// 1 + 2 + 3 + ... + n = n * (n + 1) / 2