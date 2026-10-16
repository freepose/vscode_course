
#include <stdio.h>
#include <math.h>

int main()
{

    float money = 1., init = 100., rate = 0.03;
    int year = 5;

    money = init * pow(1 + rate, year);

    printf("money = %.2f", money);

    return 0;
}