
#include <stdio.h>

int gcd(int f, int s)
{
    if (f < s)
    {
        int t = f;
        f = s;
        s = t;
    }
    
    int mod;
    do {
        mod = f % s;
        f = s;
        s = mod;
    } while (mod > 0);

    return f;
}

int main()
{
    int m = 125, n = 75;

    printf("GCD(%d, %d) = %d\n", m, n, gcd(m, n));

    return 0;
}
