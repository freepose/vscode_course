
// Loops in loops
// 也叫循环标记控制法

#include <stdio.h>

int main()
{
    int n = 5;

    for (int i = 1; i <= n; i++)
    {

        for (int k = 1; k <= n - i; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
