
// Example 7-7-2: Binary Search Method.
// Input a positive integer n (1<n≤10), then input n integers. If they are sorted in ascending order, continue to input an integer x, and then search for x in the array. If found, output the corresponding index; otherwise, output "Not Found".

#include <stdio.h>

#define MAXN 10

int main(void)
{
    int i, low, high, mid, n, sorted, x;
    int a[MAXN];

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sorted = 1;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            sorted = 0;
            break;
        }
    }
    if (sorted == 0)
    {
        printf("Invalid Value\n");
    }
    else
    {
        printf("Enter x：");
        scanf("%d", &x);
        low = 0;
        high = n - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (x == a[mid])
                break;
            else if (x < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (low <= high)
        {
            printf("Index is %d \n", mid);
        }
        else
        {
            printf("Not Found\n");
        }
    }

    return 0;
}
