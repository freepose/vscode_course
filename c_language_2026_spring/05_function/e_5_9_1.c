
#include <stdio.h>


void decomp(int n)
{
    if (n > 0)
    {
        decomp(n / 10);
        printf("%d\t", n % 10);
        
    }
}

int main()
{
    int n = 123;

    decomp(n);

    return 0;
}