
// Example 8-10: Input a positive integer n, then input any n integers, calculate and output the sum of these n integers.
// It is required to use dynamic memory allocation method to allocate space for these n integers.

#include <stdio.h>

#include <stdlib.h>

int main()
{
    int n, sum, i, *p;

    printf("Enter n: ");
    scanf("%d", &n);

    if ((p = (int *)calloc(n, sizeof(int))) == NULL)
    {
        printf("Not able to allocate memory. \n");
        exit(1);
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", p + i);

    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + *(p + i);
    }
    printf("The sum is %d \n", sum);
    free(p);

    return 0;
}

// Enter n: 10
// Enter 10 integers: 3 7 12 54 2 -19 8 -1 0 15
// The sum is 81