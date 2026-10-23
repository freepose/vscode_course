

#include <stdio.h>

int factorial(int n)
{
    int fact = 1;

    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{   
    int n = 6, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += factorial(i);
    }

    printf("1! + 2! + ... + %d! = %d\n", n, sum);

    return 0;
}