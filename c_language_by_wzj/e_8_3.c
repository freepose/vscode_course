
// Example 8-3: Swap function, using selection sort as an example

#include <stdio.h>

void swap(int *first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main()
{
    int a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        int index = i;
        for (int j = i + 1; j < 10; j++)
        {
            if (a[j] < a[index])
            {
                index = j;
            }
        }
        if (index != i)
        {
            swap(&a[i], &a[index]);       
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}