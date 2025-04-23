
// Example 2-9: given an integer n, calculate n!

#include <stdio.h>

int main(void)
{
    int i, n;
    double product;

    printf("Enter n: ");
    scanf("%d", &n);

    product = 1.0; // product = n!
    for (i = 1; i <= n; i++)
    {
        product *= i; // product = product * i
    }

    printf("Product = %.0lf\n", product);

    return 0;
}