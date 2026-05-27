
// 杨辉三角形

#include <stdio.h>

int main()
{
    int N = 0;
    int yanghui[11][11] = {0};

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        yanghui[i][1] = 1;
        yanghui[i][i] = 1;

        for (int j = 2; j <= i - 1; j++)
        {
            yanghui[i][j] = yanghui[i - 1][j - 1] + yanghui[i - 1][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= N - i; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%4d", yanghui[i][j]);
        }
        printf("\n");
    }

    return 0;
}

