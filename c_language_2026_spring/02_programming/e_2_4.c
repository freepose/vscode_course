
// Example 2-4: float data type

#include <stdio.h>

int main()
{
    float radius, circle_length, circle_area;

    printf("Radius = ");
    scanf("%f", &radius);

    circle_length = 2 * 3.14159 * radius;
    circle_area = 3.14159 * radius * radius;

    printf("Circle length = %.2f\n", circle_length);
    printf("Circle area = %.2f\n", circle_area);

    return 0;
}