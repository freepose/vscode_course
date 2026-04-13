
#include <stdio.h>
#include <string.h>

#define N 11

int main()
{
    int scores[N] = {0}, count = 0;
    float avg = .0;

    // memset(scores, 0, sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &scores[i]);
        avg += scores[i];
    }
    avg /= N;

    for (int i = 0; i < N; i++)
    {
        if (scores[i] > avg)
        {
            count++;
        }
    }

    printf("average = %f\n", avg);
    printf("count = %d\n", count);

    return 0;
}

