
// Example 4-5-1: Determine whether an integer is a prime number.
// Input an integer m and determine whether it is a prime number. A prime number is a positive integer that can only be divided by 1 and itself. 1 is not a prime number, and 2 is a prime number.

#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, limit, m;

    printf("Enter a number: ");
    scanf("%d", &m);
    if (m <= 1)
    {
        printf("No!\n");
    }
    else if (m == 2)
    {
        printf("%d is a prime number!\n", m);
    }
    else
    {
        limit = sqrt(m) + 1;
        for (i = 2; i <= limit; i++)
        {
            if (m % i == 0)
            {
                break;
            }
        }
        if (i > limit)
        {
            printf("%d is a prime number!\n", m);
        }
        else
        {
            printf("No!\n");
        }
    }

    return 0;
}

// Enter a number: 9
// No!
// Enter a number: 11
// 11 is a prime number!