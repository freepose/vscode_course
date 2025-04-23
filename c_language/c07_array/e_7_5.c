
// Example 7-5: Selection Sort Method.
// Input a positive integer n (1<n≤10), then input n integers, and sort them in ascending order using the selection sort method before outputting.

#include <stdio.h>

#define MAXN 10

int main(void)
{
    int i, index, k, n, temp;
    int a[MAXN];

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (k = 0; k < n - 1; k++)
    {
        index = k;
        for (i = k + 1; i < n; i++)
        {
            if (a[i] < a[index])
            {
                index = i;
            }
        }
        temp = a[index];
        a[index] = a[k];
        a[k] = temp;
    }

    printf("After sorted: ", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

// Enter n: 5
// Enter 5 integers: 3 5 2 8 1
// After sorted: 1 2 3 5 8