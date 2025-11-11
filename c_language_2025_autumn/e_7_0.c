
// Example 7-0: introduction to arrays

#include <stdio.h>

int main()
{
    int scores1[9];         // 声明但不初始化
    int scores2[9] = {};    // 声明并初始化为0
    int scores3[9] = {10, 20, 30, 40, 50}; // 声明并局部初始化

    // Arrays are zero-based indexed
    for (int i = 0; i < 9; i++)
    {
        printf("scores1[%d] = %d\n", i, scores1[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        printf("scores2[%d] = %d\n", i, scores2[i]);
    }

    for (int i = 0; i < 9; i++)
    {
        printf("scores3[%d] = %d\n", i, scores3[i]);
    }

    return 0;
}