
#include <stdio.h>

int main()
{
    int n = 120;

    do {
        printf("%d\t", n % 10);
        n /= 10;
    } while (n > 0);

    

    return 0;
}