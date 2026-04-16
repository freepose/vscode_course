
// Brute Force search

#include <stdio.h>

#define N 10

int main()
{
    int a[N] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};

    int x = 78;
    int index = -1;

    for (int i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (x == a[i])
        {
            index = i;
        }
    }

    if (index > -1)
    {
        printf("Find x = %d at a[%d]\n", x, index);
    }
    else
    {
        printf("Not found!\n");
    }

    return 0;
}