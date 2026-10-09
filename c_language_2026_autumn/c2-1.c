

#include <stdio.h>


int main()
{
    float celsius = 26, fahr = 0;

    scanf("%f", &fahr);

    celsius = 5.0 / 9 * (fahr - 32);

    printf("fahr %.2f = celsius %.2f\n", fahr, celsius);

    return 0;
}