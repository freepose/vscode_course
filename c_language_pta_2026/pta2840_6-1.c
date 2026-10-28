
// estimate pi

#include <stdio.h>

double fact(int n)
{
    double result = 1.0;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    double epsilon = 1e-6, term = 1., pi = 1.;
    int n = 1;

    scanf("%lf", &epsilon);
    while (term > epsilon)
    {
        double denominator = 1.0;
        for (int i = 1; i <= n; i++)
        {
            denominator *= 2 * i + 1;
        }

        term = fact(n) / denominator;

        pi += term;
        n++;
    }
    printf("PI = %.6lf\n", pi * 2);

    return 0;
}