
// 交水费：多段
#include <stdio.h>

int main()
{
    int x = 0;
    float y = 0.0;

    scanf("%d", &x);

    if (x <= 50)
    {
        y = 3 * x;
    }
    else if (x <= 100)
    {
        y = 3 * 50 + 4 * (x - 50);
    }
    else
    {
        y = 3 * 50 + 4 * 50 + 5 * (x - 100);
    }

    printf("f(%d) = %.2f\n", x, y);

    return 0;
}