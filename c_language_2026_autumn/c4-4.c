
#include <stdio.h>

int main()
{
    int n = 123, mod = 8;

    do {
        printf("%d\t", n % mod);
        n /= mod;
    } while (n > 0);

    return 0;
}