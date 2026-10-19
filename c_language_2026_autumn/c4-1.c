
#include <stdio.h>
#include <math.h>

int main()
{
    double sum = 0., item = 1;
    int n = 1, sign = 1;

    while (fabs(item) > 1e-9)
    {
        item = sign * 1.0 / (2 * n - 1);
        sum += item;
        n += 1;
        sign *= -1;
    }

    printf("Pi = %.10lf", sum * 4.0);

    return 0;
}