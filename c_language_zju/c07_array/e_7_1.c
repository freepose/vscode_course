
// Example 7-1: Input n integers (1≤n≤10), calculate the average of these numbers, and then output all numbers greater than the average.

#include <stdio.h>

int main(void)
{
    int i, n;
    double average, sum;
    int a[10];

    printf("Enter n: ");
    scanf("%d", &n);
    if (n >= 1 && n <= 10)
    {
        printf("Enter %d integers: ", n);

        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sum = 0;
        for (i = 0; i < n; i++)
        {
            sum = sum + a[i];
        }
        average = sum / n;
        printf("average = %.2f\n", average);
        printf(">average:");
        for (i = 0; i < n; i++)
        {
            if (a[i] > average)
            {
                printf("%d ", a[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Invalid Value.\n");
    }

    return 0;
}

// Enter n: 10
// Enter 10 integers: 55 23 8 11 22 89 0 -1 78 186
// average = 47.10
// >average: 55 89 78 186