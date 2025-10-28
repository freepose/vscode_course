
// Example 5-1: Cylinder Volume Calculation

#include <stdio.h>

double cylinder_volume(double radius, double height)
{
    const double PI = 3.141592653589793;
    return PI * radius * radius * height;
}

double cylinder_surface(double radius, double height)
{
    const double PI = 3.141592653589793;
    return 2 * PI * radius * (radius + height);
}

int main()
{
    double r = 2, h = 3, v = 0.0, s = 0.0;

    v = cylinder_volume(r, h);
    s = cylinder_surface(r, h);

    printf("V(r=%.2f, h=%.2f) = %.2f\n", r, h, v);
    printf("S(r=%.2f, h=%.2f) = %.2f\n", r, h, s);

    return 0;
}

