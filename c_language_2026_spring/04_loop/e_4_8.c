
#include <stdio.h>

int main()
{
    int n = 9;

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d * %d = %d", j, i, j * i);

            if (j < i)
            {
                printf("\t");
            }
        }
        printf("\n");
    }

    return 0;
}