
// Example 7-7: Binary Search in a Sorted Array

#include <stdio.h>

int binary_searh(int sorted_array[], int n, int x)
{
    /// Binary Search Algorithm 
    /// If found, return the index of x in sorted_array
    /// If not found, return -1 

    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (sorted_array[mid] == x)
        {
            return mid;
        }
        else if (sorted_array[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Not found
}

int main()
{
    int sorted_array[] = {1, 2, 3, 5, 8};
    int n = sizeof(sorted_array) / sizeof(int);

    int x = 5; // Element to search for

    int result = binary_searh(sorted_array, n, x);

    if (result != -1)
    {
        printf("Element %d found at index %d.\n", x, result);
    }
    else
    {
        printf("Element %d not found in the array.\n", x);
    }

    return 0;
}