#include <stdio.h>
#define FLAG 1
int main()
{
    int a, b, max, min;
    scanf("%d%d", &a, &b);
    if (a >= b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
#if FLAG
    printf("%d", max);
#else
    printf("%d", min);
#endif
    return 0;
}
