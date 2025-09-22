

#include <stdio.h>

int main()
{
    // 利用组合数公式的对称性 (C(n, m) = C(n, n-m)) 来减少计算量。
    // 以下是一个不使用用户定义函数的C程序，用于计算组合数 (C(n, m)) 并输出结果：
    int m, n;
    scanf("%d %d", &m, &n);

    // 确保 m <= n - m 以减少计算量
    if (m > n - m)
    {
        m = n - m;
    }

    double result = 1.0;
    for (int i = 0; i < m; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }

    printf("result = %.0lf\n", result);

    return 0;
}