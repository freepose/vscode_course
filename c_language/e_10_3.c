
// Example 10-3: decompose a number to digits, use reverse order

// 123 -> 1 2 3 or 3 2 1

#include <stdio.h>

void decompose(int n)
{
    if (n > 0)
    {
        printf("%d ", n % 10);
        decompose(n / 10);
    }
}

int main()
{
    int n = 100;

    decompose(n);

    return 0;
}
