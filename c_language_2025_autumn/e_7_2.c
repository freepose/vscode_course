
// Example 7-2: Fibonacci sequence using array

#include <stdio.h>

int main()
{
    int fib[100] = {0, 1, 1, 2};
    int n = 40;

    // compute fibonacci sequence
    for (int i = 3; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // print the fibonacci sequence
    for (int i = 0; i < n; i++) 
    {
        printf("fib[%d] = %d\n", i, fib[i]);
    }

    return 0;
}