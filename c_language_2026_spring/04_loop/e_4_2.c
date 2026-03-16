
// Sum 1 to n using for loop
// 循环累计法

#include <stdio.h>

int main()
{
    int sum = 0;
    int start = 1, end = 100;

    for (int i = start; i <= end; i += 1)
    {
        sum += i; // sum = sum + i;
    }

    printf("The sum from %d to %d is: %d\n", start, end, sum);

    return 0;
}