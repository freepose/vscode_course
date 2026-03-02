
// Example 4-5-3: Determine whether an integer is a prime number.
// Input an integer m and determine whether it is a prime number. A prime number is a positive integer that can only be divided by 1 and itself. 1 is not a prime number, and 2 is a prime number.

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, is_prime, limit, m;

    printf("Enter a number: ");
    scanf("%d", &m);
    if (m <= 1)
    {
        is_prime = 0;
    }
    else if (m == 2)
    {
        is_prime = 1;
    }
    else if (m % 2 == 0)
    {
        is_prime = 0;
    }
    else
    {
        is_prime = 1;
        limit = sqrt(m) + 1;
        for (i = 3; i <= limit; i += 2)
        {
            if (m % i == 0)
            {
                is_prime = 0;
                break;
            }
        }
    }

    if (is_prime == 1)
    {
        printf("%d is a prime number!\n", m);
    }
    else
    {
        printf("No!\n");
    }

    return 0;
}

// Enter a number: 9
// No!
// Enter a number: 11
// 11 is a prime number!