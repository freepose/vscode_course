

#include <stdio.h>


float cylinder_volume(float r, float h)
{
    return 3.14 * r * r * h;
}

int main()
{
    float radius = 5.0;
    float height = 10.0;

    float volume = cylinder_volume(radius, height);

    printf("Volume of the cylinder: %.2f\n", volume);
    
    return 0;
}