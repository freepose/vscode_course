
// 例2-6：温度转化表

#include <stdio.h>

int main()
{
    int lower = 30, upper = 35, fahr; // the boundary of fahr -> celsius table

    scanf("%d %d", &lower, &upper);

    for (fahr = lower; fahr <= upper; fahr = fahr + 1)
    {
        printf("%d %.1f\n", fahr, 5.0 / 9 * (fahr - 32));
    }

    return 0;
}
