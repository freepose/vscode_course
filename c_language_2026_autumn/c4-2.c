
#include <stdio.h>

int main()
{
    int score = 0, counter = -1;
    double sum = 0., average = 0;

    do {
        sum += score;
        counter++;
        scanf("%d", &score);
    } while (score >= 0);
    printf("%d scores, sum = %.2lf\n", counter, sum);

    if (counter > 0)
    {
        average = sum / counter;
        printf("average = %.2lf\n", average);
    }

    return 0;
}