
// Example 10-2: Use a recursive function to calculate n!.

#include <stdio.h>

double fact(int n);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%f", fact(n));

    return 0;
}

double fact(int n)
{
    double result;

    if (n == 1 || n == 0)
    {
        result = 1;
    }
    else
    {
        result = n * fact(n - 1);
    }

    return result;
}
