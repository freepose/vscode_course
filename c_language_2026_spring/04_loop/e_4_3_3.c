
#include <stdio.h>

int main()
{
    int a1 = 1, a2 = 1, ai;
    int n = 7;

    for (int i = 3; i <= n; i++)
    {
        ai = a2 + a1;
        a1 = a2;
        a2 = ai;
    }

    printf("a_%d = %d", n, ai);

    return 0;
}
