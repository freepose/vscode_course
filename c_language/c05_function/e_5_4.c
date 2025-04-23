
// Example 5-4: This program uses a function to find the greatest common divisor of two integers.
// The function gcd(int m, int n) calculates the greatest common divisor of m and n.

#include <stdio.h>

int gcd(int x, int y);

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);
    printf("%d\n", gcd(x, y));

    return 0;
}

int gcd(int m, int n)
{
    int r, temp;

    if (m < n)
    {
        temp = m;
        m = n;
        n = temp;
    }
    r = m % n;
    while (r != 0)
    {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}
