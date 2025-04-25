
// 循环标记法：判断素数

// 循环标记法：break 关键字

#include <stdio.h>

int main()
{
    int n = 6;
    int flag = 1; // 1: prime number, 0: not prime number

    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            flag = 0;   // not prime number
            break;
        }
    }

    if (0 == flag)
    {
        printf("%d is NOT a prime number.\n", n);
    }
    else
    {
        printf("%d is a prime number.\n", n);
    }

    return 0;
}