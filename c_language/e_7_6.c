
// 7-6 Binary Search

#include <stdio.h>

int main()
{
    const int n = 10;
    int a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};
    int x = 22; // target value
    int low = 0, high = n - 1, mid = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n;j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        // swap
        if (min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }

    // output sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // find the target x in sorted array
    while (low < high)
    {
        mid = (low + high) / 2;
        if (a[mid] == x)
        {
           printf("Found %d at index %d\n", x, mid);
           break;
        }
        else if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return 0;
}