
#include <stdio.h>

int main()
{
    float money = 0., volume = 0.;

    scanf("%f", &volume);

    if (volume < 0)
    {
        printf("input error!");
        return 0;
    }
    else if (volume <= 15.0)
    {
        money = volume * 4.0 / 3.0;
    }
    else
    {
        money = (volume - 15) * 2.5 + 20;
    }

    
    printf("volume = %.2f, money = %.2f\n", volume, money);

    return 0;
}