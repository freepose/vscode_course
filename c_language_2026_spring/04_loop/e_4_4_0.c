
#include <stdio.h>

int main()
{
    int n = 100;

    for (int i = 1; i <= 100; i++)
    {
        if (i % 4 == 0)
        {
            printf("%d\t", i);
        }
    }

    return 0;
}