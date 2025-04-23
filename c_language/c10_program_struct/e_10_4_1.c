
// Example 10-4-1: Write a recursive function reverse(int n) to output the integer n in reverse order.

#include <stdio.h>

void reverse(int n);

int main(void)
{
    int n;

    scanf("%d", &n);
    reverse(n);
    printf("\n");

    return 0;
}

void reverse(int num)
{
    if (num < 10)
    {
        printf("%d", num);
    }
    else
    {
        printf("%d", num % 10);
        reverse(num / 10);
    }
}
