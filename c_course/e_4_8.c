
#include<stdio.h>

int main()
{
    int score, max = -1, min = 10000;

    do
    {
        scanf("%d", &score);
        if (max < score)
        {
            max = score;
        }
        if (score > 0 && min > score)
        {
            min = score;
        }

    } while (score > 0);
    
    printf("max = %d, min = %d\n", max, min);

    return 0;
}