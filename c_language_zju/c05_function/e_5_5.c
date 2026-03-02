
// Example 5-5: This program uses a function to determine whether a number is prime.
// The function prime(m) checks if m is prime, returning 1 if it is and 0 otherwise. A prime number is a positive integer greater than 1 that has no positive divisors other than 1 and itself.

#include <stdio.h>
#include <math.h>

int prime(int m);

int main(void)
{
    int m;

    printf("Enter a number: ");
    scanf("%d", &m);

    if (prime(m) != 0)
    {
        printf("%d is a prime number!\n", m);
    }
    else
    {
        printf("No!\n");
    }

    return 0;
}

int prime(int m)
{
    int i, limit;

    if (m <= 1)
    {
        return 0;
    }
    else if (m == 2)
    {
        return 1;
    }
    else
    {
        limit = sqrt(m) + 1;
        for (i = 2; i <= limit; i++)
        {
            if (m % i == 0)
            {
                return 0;
            }
        }

        return 1;
    }
}
