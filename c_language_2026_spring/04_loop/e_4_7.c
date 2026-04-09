
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

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j == 1 || j == 2 * i  -1)
            {
                printf("%c", 'A' + i - 1);
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
