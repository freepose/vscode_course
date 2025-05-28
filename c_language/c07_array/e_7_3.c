
// Example 7-3: Sequential search method.
// Store n integers entered into array a, then enter an integer x, and search for the given x in array a. If the elements in array a are equal to x, output all indices (starting from 0) that satisfy the condition; if not found, output "Not Found".

#include <stdio.h>

#define MAXN 10

int main(void)
{
    int i, flag, n, x;
    int a[MAXN];

    printf("Enter n, x: ");
    scanf("%d%d", &n, &x);
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    flag = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            printf("Index is %d\n", i);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Not Found\n");
    }

    return 0;
}

// Enter n, x: 5 9
// Enter 5 integers: 2 9 8 1 9
// Index is 1
// Index is 4

// Enter n, x: 4 101
// Enter 4 integers: 9 8 -101 10
// Not Found