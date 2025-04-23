
// Example 8-6: Input n integers as array elements, and calculate and output their sum using both arrays and pointers.

#include <stdio.h>

int main(void)
{
    int i, n, a[10], *p;
    long sum = 0;

    printf("Enter n(n≤10): ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        sum = sum + *(a + i);
    }
    printf("calculated by array, sum = %ld \n", sum);

    sum = 0;
    for (p = a; p < a + n; p++)
    {
        sum = sum + *p;
    }
    printf("calculated by pointer, sum = %ld \n", sum);

    return 0;
}

// Enter n(n≤10): 10
// Enter 10 integers: 10 9 8 7 6 5 4 3 2 1
// calculated by array, sum = 55 
// calculated by pointer, sum = 55 