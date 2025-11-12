
// Example 7-4: Find the maximum value in an array (Brute Force)


#include <stdio.h>

int main()
{
    int arr[] = {3, 5, 2, 8, 1};
    int n = sizeof(arr) / sizeof(int);

    int max_value = arr[0]; // initialize max_value with the first element
    int max_index = 0;      // 下标

    // print array elements
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // find the maximum value using brute force
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
            max_index = i;
        }       
    }

    printf("Maximum value is %d at index %d\n", max_value, max_index);


    return 0;
}