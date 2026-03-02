
// Example 10-8: Simple macro definition with parameters.

#include <stdio.h>

#define MAX(a, b) a > b ? a : b

#define SQR(x) x *x

int main(void)
{
    int x, y;

    scanf("%d%d", &x, &y);
    x = MAX(x, y);
    y = SQR(x);
    printf("%d  %d\n", x, y);

    return 0;
}
