
// Example 7-4-1: Find the minimum value and its index in an array.
// This program prompts the user to input a positive integer n (1≤n≤10), then inputs n integers and stores them in an array a. It outputs the minimum value and its corresponding index.

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

    return 0;
}

// Enter n: 6
// Enter 6 integers: 2 9 -1 8 1 6
// min is -1	sub is 2