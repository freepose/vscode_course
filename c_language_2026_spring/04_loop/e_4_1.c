

// Sum from 1 to 100，循环累计法

#include <stdio.h>

int main()
{
    int n = 100;
    int sum = 0;

    for (int i = 1; i <= n;)
    {
        sum += i;
        i = i + 1;
    }

    printf("The sum from 1 to %d is %d\n", n, sum);

    return 0;
}