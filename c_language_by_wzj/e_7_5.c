
// 7-5 Selection sort

#include <stdio.h>

int main()
{
    const int n = 10;
    int a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};
    
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n;j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        // swap
        if (min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }

    // output
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}