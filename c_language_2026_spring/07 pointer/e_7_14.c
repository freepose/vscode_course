
#include <stdio.h>

void print_array2d(int a[][4], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[3][4] = {
        {0, 1, 2, 3},
        {10, 11, 12, 13},
        {20, 21, 22, 23},
    };

    print_array2d(a, 3, 4);

    return 0;
}