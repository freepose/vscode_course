
// Example 4-11-2: Brick moving problem.
// Input a positive integer n (1<=n<=100) and output all combinations.

#include <stdio.h>

int main(void)
{
    int children, cnt, limit_m, limit_w, men, n, women;

    printf("Enter n: ");
    scanf("%d", &n);
    limit_m = n / 3;
    limit_w = n / 2;
    cnt = 0;
    for (men = 0; men <= limit_m; men++)
    {
        for (women = 0; women <= limit_w; women++)
        {
            children = n - men - women;
            if ((men * 3 + women * 2 + children * 0.5 == n))
            {
                printf("men=%d, women=%d, children=%d\n", men, women, children);
                cnt++;
            }
        }
    }
    if (cnt == 0)
    {
        printf("None\n");
    }

    return 0;
}

// Enter n: 45
// men=0, women=15, children=30
// men=3, women=10, children=32
// men=6, women=5, children=34
// men=9, women=0, children=36