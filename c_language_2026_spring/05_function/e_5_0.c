
#include <stdio.h>
#include <math.h>

void print_hello()
{
    printf("Hello, world!\n"); // built-in function
}

double fact_iter(int n)
{
    double f = 1.0;

    for (int i = 2; i <= n; i++)
    {
        f *= i;
    }

    return f;
}

double fact_recur(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * fact_recur(n - 1);
}

int is_prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 10;

    printf("%d! = %.0lf\n", n, fact_iter(n));
    printf("%d! = %.0lf\n", n, fact_recur(n));

    // printf("%d is %s prime number\n", n, is_prime(n) == 1 ? "a" : "not a");

    return 0;
}