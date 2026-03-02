
// Example 8-9: Find the smallest string. Input n strings and output the smallest string among them.
// Program B: Compare numbers

#include <stdio.h>

int main()
{
    int i, n;
    int x, min;

    scanf("%d", &n);
    scanf("%d", &x);

    min = x;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &x);
        if (x < min)
        {
            min = x;
        }
    }
    printf("min is %d\n", min);

    return 0;
}

// 5
// 2 8 -1 99 0
// min is -1