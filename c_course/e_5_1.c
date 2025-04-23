
#include <stdio.h>

float cylinder_volume(float r, float h)
{
    return 3.14159 * r * r * h;
}

float cylinder_surface(float r, float h)
{
    return 2 * 3.14159 * r * (r + h);
}

int main()
{
    float r = 3.0, h = 4.0;
    float volume = 0.0, surface = 0.0;

    volume = cylinder_volume(r, h);
    surface = cylinder_surface(r, h);

    printf("volume = %.2f\nsurface = %.2f\n", volume, surface);

    return 0;
}