
// Example 10-4-3: Write a recursive function reverse(int n) to output the integer n in reverse order.

#include <stdio.h>

int reverse(int n);

int mypow(int num);

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", mypow(n));
    printf("%d", reverse(n));
    printf("\n");

    return 0;
}

int reverse(int num)
{
    int result;

    if (num < 10)
    {
        result = num;
    }
    else
    {
        result = (num % 10) * mypow(num) + reverse(num / 10);
    }

    return result;
}

int mypow(int num)
{
    int result;

    if (num < 10)
    {
        result = 1;
    }
    else
    {
        result = 10 * mypow(num / 10);
    }

    return result;
}
