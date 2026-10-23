
#include <stdio.h>

int main()
{
    int a1 = 1, a2 = 1, an = 2;
    int n = 3;

    for (int i = 3; i <= n; ++i)
    {
        an = a2 + a1;
        a1 = a2;
        a2 = an;
    }

    printf("a%d = %d\n", n, an);
    
    return 0;
}