
// 7-4 Linear traverse for Minimum Value

#include <stdio.h>

int main()
{
    short a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};
    short min = a[0];
    int min_index = 0;

    for (int i = 1; i < 10; i++)
    {
        if (a[i] < min) 
        {
            min = a[i];
            min_index = i;
        }
    }

    printf("Minimum value is %d, index is %d\n", min, min_index);

    return 0;
}
