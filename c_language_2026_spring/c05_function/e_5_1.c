
// Example 5-1
// Input the height and radius of a cylinder, and calculate its volume.

#include <stdio.h>

double cylinder(double r, double h);

int main(void)
{
    double height, radius, volume;

    printf("Enter radius and height: ");
    scanf("%lf%lf", &radius, &height);
    volume = cylinder(radius, height);
    printf("Volume = %.3f\n", volume);

    return 0;
}

double cylinder(double r, double h)
{
    double result;
    result = 3.1415926 * r * r * h;
    return result;
}

// Enter radius and height: 3.0 10
// Volume = 282.743