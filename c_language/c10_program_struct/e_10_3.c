
// Example 10-3: Use recursion to find the greatest common divisor (GCD).
// Define the function gcd(int m, int n) to calculate the GCD of m and n.

#include <stdio.h>

int gcd(int m, int n);

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    printf("%d\n", gcd(m, n));

    return 0;
}

int gcd(int m, int n)
{
    if (m % n == 0)
    {
        return n;
    }
    else
    {
        return gcd(n, m % n);
    }
}
