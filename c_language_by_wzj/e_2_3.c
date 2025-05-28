
#include <stdio.h>

int main()
{
    int volume = -1;
    float charge = 0.0;

    scanf("%d", &volume);

    if (volume < 0)
    {
        charge = 0.0;
    }
    else if (volume <= 25)
    {
        charge = volume * 2.5;
    }

    printf("charge = %.2f", charge);

    return 0;
}