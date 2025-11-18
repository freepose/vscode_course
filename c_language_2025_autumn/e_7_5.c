
// Example 7-5: Selection Sort to arrange an array in descending order

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

    // Selection sort based on finding maximum value
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

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}