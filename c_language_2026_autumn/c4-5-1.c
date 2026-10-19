
#include <stdio.h>

int main()
{
    int n = 100, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);

    return 0;
}