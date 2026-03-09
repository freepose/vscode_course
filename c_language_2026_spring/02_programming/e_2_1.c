#include <stdio.h>

int main()
{
    int a, b, c;

    float avg;

    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    avg = (a + b + c) / 3.0;
    printf("The average is: %f\n", avg);

    return 0;
}