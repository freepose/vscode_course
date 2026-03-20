

// continue

#include <stdio.h>

int main()
{
    int n = 10;
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            break;
        }
        sum = sum + i;
    }

    printf("Sum = %d\n", sum);

    return 0;
}