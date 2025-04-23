
// Example 3-4: Continue discussing the piecewise calculation of water fees proposed in Example 2-4.

#include <stdio.h>

int main(void)
{
    double x, y;

    printf("Enter x:"); 
    scanf("%lf", &x);   
    if (x < 0)
    {
        y = 0;
    }
    else if (x <= 15)
    {
        y = 4 * x / 3; 
    }
    else
    {
        y = 2.5 * x - 10.5;
    }

    printf("f(%.2f) = %.2f\n", x, y);

    return 0;
}

// Enter x: -0.5
// f(-0.50) = 0.00

// Enter x: 9.5
// f(9.50) = 12.67

// Enter x: 21.3
// f(21.30) = 42.75