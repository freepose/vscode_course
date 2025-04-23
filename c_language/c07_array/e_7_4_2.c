
// Example 7-4-2: Input a positive integer n (1≤n≤10), then input n integers, and store them in an array a.
// ① Output the minimum value and its corresponding index. ② Swap the minimum value with the first number and output the n numbers after swapping.

#include <stdio.h>

#define MAXN 10

int main(void)
{
    int i, index, n;
    int a[MAXN];

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    index = 0;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[index])
        {
            index = i;
        }
    }

    printf("min is %d\tsub is %d\n", a[index], index);
    {
        int temp;
        temp = a[index];
        a[index] = a[0];
        a[0] = temp;
        for (i = 0; i < n; i++)
        {
            printf(" %d ", a[i]);
        }
    }

    return 0;
}

// Enter n: 6
// Enter 6 integers: 2 9 -1 8 1 6
// min is -1       sub is 2
//  -1  9  2  8  1  6 