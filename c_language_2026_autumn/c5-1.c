
#include <stdio.h>

double cylinder_volume(double, double);

int main()
{
    double radius, height, volume;

    radius = 2;
    height = 3;

    printf("%lf", cylinder_volume(height, radius));
    

    return 0;
}

double cylinder_volume(double r, double h)
{
    double pi = 3.14692653;
    return pi * r * r * h;
}