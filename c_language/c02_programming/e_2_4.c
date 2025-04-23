
// Example 2-4: Water charge calculation using branch statements


#include <stdio.h>

int main()
{
    double x, y;

    printf("Enter x (x>=0):\n");

    scanf("%lf", &x);

    if (x < 15)
    {
        y = 2.5 * x - 10.5;
    }
    else
    {
        y = 2.5 * x - 7.5;
    }

    printf("y = f(%f) = %.2f\n", x, y);

    return 0;
}
