
// 一门课：一个数组，两门课两个组？那三门课？
// 引入：二维数组

#include <stdio.h>

#define M 3 // 课程
#define N 5 // 学生

int main()
{
    int a[M][N] = {
        {77, 80, 66, 50, 92},
        {72, 86, 70, 60, 95},
        {80, 78, 56, 67, 88},
    };

    float b[N] = {0.}, c[M] = {0};

    // print scores

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // printf("a[%d][%d] = %d \n", i, j, a[i][j]);
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    // average scores of each course
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c[i] += a[i][j];
        }
        c[i]  /= 5.0;
    }

     for (int i = 0; i < M; i++)
     {
        printf("%.2f\t", c[i]);
     }

    // average scores of each student

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {

            b[j] += a[i][j];
        }
        b[j] /= 3.0;
    }

    for (int j = 0; j < N; j++)
    {
        printf("%.2f\t", b[j]);
    }


    return 0;
}