
#include <stdio.h>

int is_prime(int n)
{
    if (n <= 1)
    {
        return 0; // Not prime
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0; // Not prime
        }
    }

    return 1; // Prime
}

int main()
{
    int counter = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (is_prime(i))
        {
            counter++;
            if (counter % 10 == 0)
            {
                printf("%d\n", i);
            }
            else
            {
                printf("%d\t", i);
            }
        }
    }

    return 0;
}