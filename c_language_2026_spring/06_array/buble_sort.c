
#include <stdio.h>

int main()
{
    int scores[10] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", scores[i]);
    }
    printf("\n");

    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (scores[j] < scores[j + 1])
            {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", scores[i]);
    }
    printf("\n");

    return 0;
}