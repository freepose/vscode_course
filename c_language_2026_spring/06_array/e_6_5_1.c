

// Now， I can find the max value/index in an array. Then, if swap the max value with first value of the array, and iteratively.
// This is also known as seletion sort.
// 数组中找最大值


#include <stdio.h>

#define N 10

int main()
{
    int a[N] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};

    int index, temp;

    for (int i = 0; i < N; i++)
    {
        printf("%p -> a[%d] -> %d\n", &a[i], i, a[i]);
    }

    for (int j = 0; j < N - 1; j++)
    {
        index = j;
        for (int i = j + 1; i < N; i++)
        {
            if (a[index] > a[i])    // ascending
            {
                index = i;
            }
        }

        // swap
        temp = a[j];
        a[j] = a[index];
        a[index] = temp;
    }

    printf("After sort\n");
    for (int i = 0; i < N; i++)
    {
        printf("%p -> a[%d] -> %d\n", &a[i], i, a[i]);
    }

    return 0;
}