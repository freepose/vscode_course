
#include <stdio.h>

int main()
{
    int score;

    scanf("%d", &score);

    if (score >= 90)
    {
        printf("A");
    }
    else if (score >= 80) // 80 <= score < 90
    {
        printf("B");
    }
    else if (score >= 70)
    {
        printf("C");
    }
    else if (score >= 60)
    {
        printf("D");
    }
    else
    {
        printf("E");
    }


    return 0;
}