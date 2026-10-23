
#include <stdio.h>

int is_prime(int n)
{
    if (n == 1)
    {
        return 0;
    }

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
    int n = 100;

    for (int i = 1; i <= n; ++i)
    {
        // printf("%d is %sa prime number!\n", i, is_prime(i) == 1 ? "" : "NOT ");
        if (is_prime(i))
        {
            printf("%d\t", i);
        }
    }


    return 0;
}