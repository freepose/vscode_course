
// Sum 1 to n using while loop
// 循环累计法

#include <stdio.h>

int main()
{
    int sum = 0;
    int start = 1, end = 100;
    int i = start;

    while (i <= end)
    {
        sum += i; // sum = sum + i;
        i += 1; // Move to the next number
    }

    printf("The sum from %d to %d is: %d\n", start, end, sum);

    return 0;
}