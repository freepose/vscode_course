

// Example 5-4: GCD, greatest common divisor calculation using Euclidean algorithm

#include <stdio.h>

int gcd(int m, int n)
{
    // Ensure m >= n
    if (m < n) // 交换两个数的核心原则是什么：先存值后覆盖
    {
        int temp = m;
        m = n;
        n = temp;
    }

    int temp;
    while (n != 0)
    {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

int main()
{
    int a = 60, b = 40;

    printf("The GCD of %d and %d is %d\n", a, b, gcd(a, b));

    return 0;
}