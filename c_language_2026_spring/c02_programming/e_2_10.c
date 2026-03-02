
// Example 2-10：given an integer n, print pow() table of 2^i, i = 0, 1, ..., n

#include <stdio.h>
#include <math.h> 

int main()
{
    int i, n;
    double power;

    printf("Enter n: ");
    scanf("%d", &n);

    for (i = 0; i <= n; i++)
    {
        power = pow(2, i);

        printf("pow(2, %d) = %.0lf\n", i, power);
    }

    return 0;
}