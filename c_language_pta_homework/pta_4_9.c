#include <stdio.h>
#include <math.h>

// 判断一个数是否为素数
int is_prime(int num)
{
    if (num < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int found = 0;
    for (int i = 2; i <= n; i++)
    {
        int mersenne = (1 << i) - 1; // 计算2^i - 1
        if (mersenne <= (1 << n) - 1 && is_prime(mersenne))
        {
            printf("%d\n", mersenne);
            found = 1;
        }
    }

    if (!found)
    {
        printf("None\n");
    }

    return 0;
}