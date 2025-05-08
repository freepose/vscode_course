
// Example 8-8: Binary search in a sorted array

#include <stdio.h>

void print_array(int *array, int size)
{
    // array is a pointer to the first element of the array

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int binary_search(int *array, int size, int target)
{
    // array is a pointer to the first element of the array
    // size is the number of elements in the array
    // target is the value to search for in the array

    int index = -1;
    int low = 0, high = size - 1, mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == target)
        {
            index = mid;
            break;
        }
        else if (array[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    const int n = 10;
    int a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};
    int target = 22;
    int index = -1;

    printf("Before sorting: ");
    print_array(a, n);

    bubble_sort(a, n);

    printf("After sorting: ");
    print_array(a, n);

    printf("Enter the number to search: ");

    index = binary_search(a, n, target);
    if (index != -1)
    {
        printf("The index of value %d is %d\n", target, index);
    }
    else
    {
        printf("The value %d is not found in the array\n", target);
    }

    return 0;
}