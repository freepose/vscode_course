#include <stdio.h>

double fact(int n)
{
    double product = 1.0;

    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }

    return product;
}

int main(void)
{
    int n;

    printf("n: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("error \n");
        return 1;
    }

    double result = fact(n);
    printf("%d! = %.0f\n", n, result);

    return 0;
}
