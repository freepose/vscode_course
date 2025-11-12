
// Example 7-5-1: pass array to functions for sorting and printing

#include <stdio.h>

#define MAX_SIZE 100

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

void selection_sort_desc(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[max_index] < arr[j])
            {
                max_index = j;
            }
        }

        // Swap the found maximum element with the first element
        if (max_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
    }
}


int main()
{
    int arr1[] = {3, 5, 2, 8, 1};
    int arr2[] = {3, 5, 2, 8, 1};

    int buffer[MAX_SIZE] = {0}; // unused buffer

    int n = sizeof(arr1) / sizeof(int);


    print_array(arr1, n); printf("\n");
    selection_sort_asc(arr1, n);
    print_array(arr1, n); printf("\n");

    print_array(arr2, n); printf("\n");
    selection_sort_desc(arr2, n);
    print_array(arr2, n); printf("\n");

    return 0;
}