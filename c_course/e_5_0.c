
// 1! + 2! + 3! + ... + n! 

#include <stdio.h>

int factorial(int n)
{
    // int result = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     result *= i;
    // }
    // return result;
    if (n == 0 || n == 1)
    {
        return 1.0;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n = 4;
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += factorial(i);
    }

    printf("Sum of factorials from 1 to %d is %d\n", n, sum);

    return 0;
}
