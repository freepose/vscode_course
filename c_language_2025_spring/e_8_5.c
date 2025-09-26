
// Example 8-5: Bubble sort

#include <stdio.h>

void swap(int *first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void print_array(int *array, int size)
{
    // array is a pointer to the first element of the array

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    const int n = 10;
    int a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};

    print_array(a, n);

    // a pass of bubble sort
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1 - j; i++)
        {
            if (a[i] > a[i+1])
            {
                swap(&a[i], &a[i+1]);
            }
        }
    }

    print_array(a, n);

    return 0;
}