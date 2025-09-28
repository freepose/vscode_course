
// 例2-7：整数求和，简洁的试下，也可以参考书本上的

#include <stdio.h>

int main()
{
    int n, i, sign = 1;
    float sum = 0.0;

    scanf("%d", &n);

    // 循环累加
    for (i = 1; i <= n; i = i + 1)
    {
        sum = sum + sign / (2.0 * i - 1);
        sign = -sign;
    }
    printf("sum = %f\n", sum);

    return 0;
}