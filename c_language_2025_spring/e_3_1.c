
// Example 3-1 成绩转化为等级制

#include <stdio.h>

int main()
{
    int score = 0;

    scanf("%d", &score);    // reading range is 0-100

    if (score < 0 || score > 100)
    {
        printf("error\n");
    }
    else if (score < 60)
    {
        printf("E\n");
    }
    else if (score < 70)
    {
        printf("D\n");
    }
    else if (score < 80)
    {
        printf("C\n");
    }
    else if (score < 90)
    {
        printf("B\n");
    }
    else if (score <= 100)
    {
        printf("A\n");
    }

    return 0;
}