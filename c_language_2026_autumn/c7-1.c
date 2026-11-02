
// 55 23 8 11 22 89 0 -1 78 186
#include <stdio.h>

#define N 10

int main()
{
    int scores[N + 10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};
    double sum = 0., average;

    for (int i = 0; i < N; i++)
    {
        //scanf("%d", &scores[i]);  // 存数值到数组的第i个变量
        sum += scores[i];   // 从数组的第i个变量取数值加到sun变量
    }
    average = sum / N;

    for (int i = 0; i < N; i++)
    {
        if (scores[i] > average)
        {
            printf("average = %.2lf, a[%d] = %d\n", average, i, scores[i]);
        }
    }

    return 0;
}