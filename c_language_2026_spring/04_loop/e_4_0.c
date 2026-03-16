
#include <stdio.h>

int main()
{
    int volume = 0;

    scanf("%d", &volume);

    while (volume > 0)
    {
        volume = volume - 1;
    }

    printf("%d\n", volume);

    return 0;
}