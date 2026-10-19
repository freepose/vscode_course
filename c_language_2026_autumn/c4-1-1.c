
#include <stdio.h>

int main()
{
    int i = 1, n = 100, sum = 0;

    while (i <= n)
    {
        sum += i;
        i ++;
    }
    printf("%d\n", sum);

    return 0;
}