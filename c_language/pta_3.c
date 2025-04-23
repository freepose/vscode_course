

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, area, perimeter, s;

    scanf("%f %f %f", &a, &b, &c);

    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        perimeter = a + b + c;
        s = perimeter / 2.;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
    }
    else
    {
        printf("These sides do not correspond to a valid triangle");
    }


    printf("area = %.2f; perimeter = %.2f", area, perimeter);

    return 0;
}