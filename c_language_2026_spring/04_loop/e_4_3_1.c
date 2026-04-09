
// 累计求和：1 - 1/2 + 1/3 - 1/4 + ... + 1/99 - 1/100

#include <stdio.h>

int main()
{
    int n = 10000, sign = 1;
    float sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += sign * 1.0 / i ;
        sign = -sign;
    }

    printf("%f\n", sum);

    return 0;
}