
// 例7-1 输出大于平均值的数

#include <stdio.h>
#include <string.h>

int main()
{
    const int n = 10;
    int a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};    // as buffer

    int sum = 0;
    float avg = 0.0f;

    // calculate the average value
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    avg = sum * 1.0 / n;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > avg)
        {
            printf("%d ", a[i]);
        }
    }
   
    return 0;
}