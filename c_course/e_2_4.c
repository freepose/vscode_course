
// Example 2-4

#include <stdio.h>

int main()
{
    float volume = 0.0, charge = 0.0;

    scanf("%f", &volume);

    if (volume <= 5)
    {
        charge = 0.0;
    }
    else if (volume <= 15) 
    {
        charge = (volume - 5) * 3;
    }
    else if (volume <= 25)
    {
        charge = 30 + (volume - 15) * 3.5;
    }

    printf("charge = %.2f", charge);

    return 0;
}
