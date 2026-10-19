
#include <stdio.h>

int main()
{
    int n = 15, flag = 1;    // flag = 1表述素数

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;  // 就近原则
        }
    }

    printf("%d is a %sprime number!\n", n, flag == 1 ? "": "NOT ");

    return 0;
}