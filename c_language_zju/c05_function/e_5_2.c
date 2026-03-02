
// Example 5-2: Calculate the area of a pentagon. The pentagon is divided into three triangles (Figure 5.1).
// Input the lengths of these triangles' 7 sides and calculate the area of the pentagon. Define and call the function area(x,y,z) to calculate the area of a triangle with side lengths x, y, and z.

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a1, a2, a3, a4, a5, a6, a7, s;
    double area(double x, double y, double z);

    printf("Please input 7 side lengths in the order a1 to a7:\n");
    scanf("%lf%lf%lf%lf%lf%lf%lf", &a1, &a2, &a3, &a4, &a5, &a6, &a7);
    s = area(a1, a5, a6) + area(a4, a6, a7) + area(a2, a3, a7);
    printf("The area of the Pentagon is %.2f\n", s);

    return 0;
}

double area(double x, double y, double z)
{
    double p = (x + y + z) / 2;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}

// Please input 7 side lengths in the order a1 to a7:
// 2.5 2.5 2.5 2.5 2.5 3.6 3.6
// The area of the Pentagon is 10.47