
// Example 7-1: output array elements which are greater than average value of the array.

#include <stdio.h>

int main()
{
    int numbers[10] = {0};
    int n;
    int sum = 0;
    float average = 0.0;

    printf("Enter n (how many numbers, 1 <= n <= 10): \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // sum of elements
    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }

    average = sum * 1.0 / n;

    printf("Average value = %.2f\n", average);

    // print the array
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > average)
        {
            printf("scores[%d] = %d\n", i, numbers[i]);
        }
    }


    return 0;
}

// 10
// 55 23 8 11 22 89 0 -1 78 186