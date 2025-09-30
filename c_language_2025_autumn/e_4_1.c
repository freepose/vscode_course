
// Example 4-1: while, gregory for pi estimation

#include <stdio.h>
#include <math.h>

int main()
{
    double item = 1.0, sum = 0.0;
    double pi = 0.0;
    double sign = 1, i = 1;

    while (fabs(item) > 1e-10)
    {
        item = sign * 1.0 / i;
        sum += item; //sum = sum + item;
        i = i + 2;
        sign = -sign;
    }

    pi = sum * 4; 
    printf("pi = %.10lf\n", pi);

    return 0;
}