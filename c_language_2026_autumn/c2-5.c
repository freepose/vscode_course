
#include <stdio.h>

int main()
{

    float money = 1., init = 100., rate = 0.03;
    int year = 5;

    for (int i = 1; i <= year; i++)
    {
        money = money * (1 + rate);
    }
    money = money * init;

    printf("money = %.2f", money);

    return 0;
}