
// Example 4-3: Input an integer n, count the number of digits in an integer

#include <stdio.h>
int main(void)
{
    int count, number, t_number;

    count = 0;
    printf("Enter n: ");
    scanf("%d", &number);
    t_number = number;

    if (t_number < 0)
    {
        t_number = -t_number;
    }

    do
    {
        count++;
        t_number = t_number / 10;
    } while (t_number != 0);

    printf("It contains %d digits.\n", count);

    return 0;
}

// Enter n: 12534
// It contains 5 digits.
