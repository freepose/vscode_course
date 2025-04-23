
// Example 11-9: Write a function calc(f, a, b) to calculate the numerical integral of the function f(x) on [a, b] using the trapezoidal formula.

#include <stdio.h>

#include <math.h>

double calc(double (*funp)(double), double a, double b);

double f1(double x), f2(double x);

int main(void)
{
    double result;
    double (*funp)(double);

    result = calc(f1, 0.0, 1.0);
    printf("1: resule=%.4f\n", result);
    funp = f2;
    result = calc(funp, 1.0, 2.0);
    printf("2: resule=%.4f\n", result);

    return 0;
}

double calc(double (*funp)(double), double a, double b)
{
    double z;

    z = (b - a) / 2 * ((*funp)(a) + (*funp)(b));

    return (z);
}

double f1(double x)
{
    return (x * x);
}

double f2(double x)
{
    return (sin(x) / x);
}

// 1: resule=0.5000
// 2: resule=0.6481