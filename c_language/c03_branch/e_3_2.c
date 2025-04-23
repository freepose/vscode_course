
// Example 3-2: Odd and even counter.

#include <stdio.h>
int main(void)
{
    int count_odd, count_even, i, n, number;

    count_odd = 0;
    count_even = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &number);
        if (number % 2 != 0)
        {
            count_odd++;
        }
        else
        {
            count_even++;
        }
    }
    printf("Odd: %d, Even: %d \n", count_odd, count_even);

    return 0;
}

// Enter n: 4
// Enter 4 numbers: 5 8 101 9
// Odd: 3, Even: 1