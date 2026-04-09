
#include <stdio.h>

int main()
{
    int n = 123;
    int reverse = 0;

    while (n > 0)
    {
        reverse = reverse * 10 + n % 10;
        printf("%d\t", n % 10);
        n /= 10;
    }

    printf("%d", reverse);

    return 0;
}