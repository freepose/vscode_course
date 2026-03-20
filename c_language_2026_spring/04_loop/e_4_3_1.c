
// 累计求和：1 - 1/2 + 1/3 - 1/4 + ... + 1/99 - 1/100

#include <stdio.h>

int main()
{
    int n = 100, sign = 1;
    double sum = 0.0, item = 0;

    for (int i = 1; i <= n; i++)
    {
        item = 1.0 * sign / i;
        sum = sum + item;
        sign = -sign;
    }

    printf("Sum = %f\n", sum);

    return 0;
}