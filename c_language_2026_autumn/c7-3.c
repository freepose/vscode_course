
// fibonacci using array

#include <stdio.h>

#define N 5

int main()
{
    int a[100] = {2, 9, 8, 1, 9};
    int x = 9, i_mark = -1;

    for (int i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (x == a[i])
        {
            i_mark = i;
            break;
        }
    }

    if (i_mark == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("\na[%d] = %d\n", i_mark, a[i_mark]);
    }

    return 0;
}