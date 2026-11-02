
// fibonacci using array

#include <stdio.h>

#define N 46

int main()
{
    int fib[100] = {0, 1, 1, 2};

    for (int i = 3; i < N; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 1; i < N; i++)
    {
        printf("%d\t", fib[i]);
    }

    return 0;
}