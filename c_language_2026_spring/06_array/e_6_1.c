
#include <stdio.h>

int main()
{

    int score1, score2, score3, score4, score5, score6, score7, score8, score9, score10;

    int count = 0;
    float avg = 0.;

    scanf("%d %d %d %d %d %d %d %d %d %d", &score1, &score2, &score3, &score4, &score5, &score6, &score7, &score8, &score9, &score10);

    avg = (score1 + score2 + score3 + score4 + score5 + score6 + score7 + score8 + score9 + score10) * 1. / 10.;

    if (score1 > avg)
    {
        count++;
    }

    if (score2 > avg)
    {
        count++;
    }

    if (score3 > avg)
    {
        count++;
    }

    if (score4 > avg)
    {
        count++;
    }

    if (score5 > avg)
    {
        count++;
    }

    if (score6 > avg)
    {
        count++;
    }

    if (score7 > avg)
    {
        count++;
    }

    if (score8 > avg)
    {
        count++;
    }

    if (score9 > avg)
    {
        count++;
    }

    if (score10 > avg)
    {
        count++;
    }

    printf("%d", count);

    return 0;
}