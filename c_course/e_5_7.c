
// Fibonacci sequence 

#include <stdio.h>

int main()
{
    int a1 = 1, a2 = 1, an = 0;
    int n = 20;

    for (int i = 2; i <= n; i++)
    {
        an = a1 + a2;
        a1 = a2;
        a2 = an;
    }

    printf("a(%d): %d\n", n, an);
 
    return 0;
}