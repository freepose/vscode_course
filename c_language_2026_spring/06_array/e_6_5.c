
// find the max value in an array

#include <stdio.h>

#define N 10

int main()
{
    int a[N] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};
    int max_value, max_index;

    for (int i = 0; i < N ; i++)
    {
        printf("%p -> a[%d] -> %d\n", &a[i], i, a[i]);
    }

    max_index = 0;
    max_value = a[0];
    for (int i = 1; i < N ; i++)
    {
        if (max_value > a[i])
        {
            max_value = a[i];
            max_index = i;
        }
    }

    printf("The max value is: a[%d] = %d\n", max_index, max_value);

    return 0;
}