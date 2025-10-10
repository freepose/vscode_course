
#include <stdio.h>

int main()
{
    int lower, upper;
    scanf("%d %d", &lower, &upper);
    if (lower <= 0 || upper <= 0 || lower > upper || upper > 100)
    {
        printf("Invalid.\n");
        return 0;
    }

    printf("fahr celsius\n");

    for (int f = lower; f <= upper; f += 2)
    {
        double c = 5.0 * (f - 32) / 9.0;
        printf("%d%6.1f\n", f, c);
    }

    return 0;
}