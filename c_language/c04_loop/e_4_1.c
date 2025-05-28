

// Example 4-1: James Gregory for Pi estimation

#include <stdio.h>
#include <math.h>   // for `fabs()`

int main()
{
    double sum = 0, denumerator = -1;
    double epsilon = 1e-10;
    double item = 1;
    int sign = -1, i = 1;

    while (fabs(item) > epsilon)
    {
        sign *= -1;               // (-1)^n
        denumerator = denumerator + 2;  // 2 * i - 1
        item = sign * 1. / denumerator;
        sum += item;    // sum = sum + item;
    }

    printf("Pi = %lf\n", sum * 4);

    return 0;
}