
// Bubble sort： 相邻两数交换



#include <stdio.h>

#define N 10

int main()
{
    int a[N] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};

    int index, temp;

    for (int i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");


    // make the minimum value in the last place
    for (int j = 0; j < N - 1;j++)
    {
        for (int i = 0; i < N - 1 - j; i++)
        {
            if (a[i] < a[i + 1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i + 1] = temp;
            }
        }
    }


    for (int i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}

