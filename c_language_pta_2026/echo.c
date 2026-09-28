#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, temp;
    printf("Please input three numbers:\n");
    scanf("%f%f%f", &a, &b, &c);
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (a < c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (a * a == b * b + c * c)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}