#include <stdio.h>

int main()
{
    int h, n;
    scanf("%d %d", &h, &n);

    double distance = 0;
    double height = h;

    if (n == 0)
    {
        printf("0.0 0.0\n");
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        distance += height;
        height /= 2;
        if (i < n) {
            distance += height;
        }
    }

    printf("%.1f %.1f\n", distance, height);

    return 0;
}