
// Example 8-5: Bubble Sort using pointers

#include <stdio.h>


void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // printf("arr[%d] = %d\n", i, arr[i]);
        printf("%d", arr[i]);
        if (i != n - 1)
        {
            printf("\t");
        }
    }
}

void selection_sort_asc(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

void swap(int *x, int *y)
{
    // from real parameters to formal parameters: copy the address
    // printf("Inside swap function before swap: *x = %d, *y = %d\n", *x, *y);
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort_asc(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

int main()
{
    int arr[] = {7, 33, 66, 3, -5, 22, -77, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, n); printf("\n");

    bubble_sort_asc(arr, n);

    print_array(arr, n); printf("\n");

    return 0;
}