
// 

#include <stdio.h>

int main()
{
    int a = 48, b = 72;
    int t;

    int m = a > b ? a : b;
    int n = a > b ? b : a;

    while (n > 0)
    {
        t = m % n;
        m = n;
        n = t;
    }

    printf("GCD = %d", m);

    return 0;
}