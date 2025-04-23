
// Example 7-7-1: Binary Search Method.
// Given an integer array a with n (1≤n≤10) elements, sorted in ascending order. Input an integer x, and then search for x in the array. If found, output the corresponding index; otherwise, output "Not Found".

#include <stdio.h>

int main(void)
{
    int low, high, mid, n = 10, x;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Enter x: ");
    scanf("%d", &x);
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == a[mid])
        {
            break;
        }
        else if (x < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (low <= high)
    {
        printf("Index is %d \n", mid);
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}

// Enter x：8
// Index is 7

// Enter x：71
// Not Found