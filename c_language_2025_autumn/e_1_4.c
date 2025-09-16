
// 用程序计算1到100的和

#include <stdio.h>

int main()
{
    int start = 0;
    int end = 100;
    int sum = 0;

    for (int i = start; i <= end; i = i + 6)
    {
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}