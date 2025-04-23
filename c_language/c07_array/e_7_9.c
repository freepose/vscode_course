
// Example 7-9: Transpose a square matrix.
// Input a positive integer n (1<n≤6), generate an n*n matrix according to the formula, and then output the transposed matrix (row and column interchange).

#include <stdio.h>

#define MAXN 6

int main(void)
{
    int i, j, n, temp;
    int a[MAXN][MAXN];

    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = i * n + j + 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i <= j)
            {
                temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Enter n: 3
// 1   4   7
// 2   5   8
// 3   6   9