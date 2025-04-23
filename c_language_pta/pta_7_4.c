
// pintia

// 7-4

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int x;
    scanf("%d", &x);

    int b[11];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (x < a[i])
        {
            break;
        }
        b[i] = a[i];
    }
    b[i] = x;
    for (int j = i; j < n; j++)
    {
        b[j + 1] = a[j];
    }

    for (int i = 0; i < n + 1; i++)
    {
        printf("%d", b[i]);
        if (i < n)
        {
            printf(" ");
        }
    }
    return 0;
}