
// Example 2-11: given an integer n, print table of 1!, 2!, 3!, ..., n!

#include <stdio.h>

double fact(int n);

int main(void)
{
    int i, n;
    double result;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        result = fact(i); // result = i!
        printf("%d! = %.0lf\n", i, result);
    }

    return 0;
}

double fact(int n)
{
    int i;
    double product = 1.0; // product = n!

    for (i = 1; i <= n; i++)
    {
        product *= i; // product = product * i
    }

    return product;
}