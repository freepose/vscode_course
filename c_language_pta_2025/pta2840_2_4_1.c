
// 实验2-4-1

#include <stdio.h>

int is(int number);
void count_sum(int a, int b);

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    count_sum(a, b);
    return 0;
}

int is(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum == 5; 
}

void count_sum(int a, int b)
{
    int count = 0;
    int sum = 0;
    for (int i = a; i <= b; i++)  // 闭区间
    {
        if (is(i))
        {
            // printf("%d is counted.\n", i);  // 去掉中间输出
            sum += i;
            count++;
        }
    }
    printf("count = %d, sum = %d", count, sum);  // 格式严格匹配
}