
#include <stdio.h>

int main()
{
    float scores[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        scanf("%f", &scores[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("scores[%d] = %.2f\n", i, scores[i]);
    }

    return 0;
}