
// find max value
#include <stdio.h>

#define N 11

int main()
{
    int scores[N] = {95, 67, 88, 76, 90, 56, 72, 83, 80, 92, 99};

    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        // scanf("%d", &scores[i]);
       sum += scores[i];
    }
 
    float avg = sum * 1.0 / N;
    printf("average score = %.2f\n", avg);

    for (int i = 0; i < N; i++)
    {
        if (scores[i] > avg)
        {
            printf("scores[%d] = %d\n", i, scores[i]);
        }
    }

    return 0;
}

