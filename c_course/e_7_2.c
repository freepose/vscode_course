
// 7-2 Fibonacci using array. The previous version used iteration.

#include<stdio.h>

int main()
{
    const int len = 100;
    double fib[100] = {1, 1};

    for (int i = 2; i < len; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < len; i++)
    {
        printf("fib[%d] = %.0lf\n", i, fib[i]);
    }

    return 0;
}