
// selection sort

#include <stdio.h>

int main()
{
    int scores[10] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", scores[i]);
    }
    printf("\n");

    for (int j = 0; j < 10; j++)
    {
        int index = j;
        for (int i = j + 1; i < 10; i++)
        {
            if (scores[index] < scores[i])
            {
                index = i;
            }
        }

        if (index != j)
        {
            int temp = scores[index];
            scores[index] = scores[j];
            scores[j] = temp;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", scores[i]);
    }

    return 0;
}