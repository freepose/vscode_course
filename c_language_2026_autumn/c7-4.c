
// fibonacci using array

#include <stdio.h>

#define N 10

int main()
{
    int a[N + 10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};
    int i_max = 0;

    for (int i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }

    for (int i = 1; i < N; i++)
    {
        if (a[i_max] < a[i])
        {
            i_max = i;
        }
    }

    printf("\nmax value is a[%d] = %d\n", i_max, a[i_max]);

    return 0;
}