
#include <stdio.h>

int main()
{
    int score = 0;

    scanf("%d", &score);

    if (score < 0 || score > 100)
    {
        printf("error input\n");
        return 0;
    }

    if (score >= 90)
    {
        printf("A\n");
    }
    else if (score >= 80)
    {
        printf("B\n");
    }
    else if (score >= 70)
    {
        printf("C\n");
    }
    else if (score >= 60)
    {
        printf("D\n");
    }
    else
    {
        printf("E\n");
    }

    return 0;
}