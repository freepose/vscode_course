
// Example 7-8: Find the maximum value in a matrix and its row and column indices.
// Input two positive integers m and n (1≤m,n≤6), then input an m×n matrix, and find the maximum value as well as its row and column indices. Assume that the maximum value is unique.

#include <stdio.h>

#define MAXM 6

#define MAXN 6

int main(void)
{
    int col, i, j, m, n, row;
    int a[MAXM][MAXN];

    printf("Enter m, n: ");
    scanf("%d %d", &m, &n);

    printf("Enter %d integers: \n", m * n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    row = col = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > a[row][col])
            {
                row = i;
                col = j;
            }
        }
    }
    printf("max = a[%d][%d] = %d\n", row, col, a[row][col]);

    return 0;
}

// Enter m, n: 3 2
// Enter 6 integers:
// 6 3
// 10 -9
// 5 -1
// max = a[1][0] = 10