#include <stdio.h>
int main()
{
    int a, b, h, c, j;
    double s;

    scanf("%d %d", &a, &b);
    h = a + b;
    c = a - b;
    j = a * b;

    printf("%d + %d = %d\n", a, b, h);
    printf("%d - %d = %d\n", a, b, c);
    printf("%d * %d = %d\n", a, b, j);
    
    if (a % b == 0)
    {
        s = a / b;
        printf("%d / %d = %d\n", a, b, s);
    }
    else
    {
        s = (double)a / b;
        printf("%d / %d = %.2f\n", a, b, (double)s);
    }
    return 0;
}
