
// Example 2-8: given an integer n, sum of 1 - 1 / 3 + 1 / 5 - 1 / 7 + ... + (-1)^(n-1) / (2n - 1)
// This is the Greygory formula for pi

#include <stdio.h>

int main(void)
{
    int denominator, flag, i, n;
    double item, sum;

    printf("Enter n: ");
    scanf("%d", &n);

    flag = 1; // flag = 1 means positive, flag = -1 means negative
    denominator = 1; // denominator = 2 * i - 1

    item = 1.0;
    sum = 0.0;

    for (i = 1; i <= n; i++)
    {
        item = flag * 1.0 / denominator;
        sum += item;
        flag = -flag; // change the sign
        denominator += 2; // denominator = 2 * i - 1
    }

    printf("Sum = %lf\n", sum);

    return 0;
}
