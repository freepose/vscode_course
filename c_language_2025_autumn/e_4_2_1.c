
// Example 4-2-1: 循环读数 -- do while 版本

// 67 88 73 54 82 -1

#include <stdio.h>

int main()
{
    int temp = 0, sum = 0, counter = 0, failure_counter = 0;
    double average = 0.0;

    do {
        scanf("%d", &temp);
        sum += temp;
        counter++;  
        if (temp < 60)
        {
            failure_counter++;
        }
    } while (temp != -1);

    sum += 1; // 去掉 -1 的影响
    counter--; // 去掉 -1 的影响
    failure_counter--; // 去掉 -1 的影响

    printf("Sum = %d\n", sum);
    if (counter > 0)
    {
        average = sum * 1.0 / counter; // 强制类型转换
        printf("Average = %.2lf\n", average);
    }
    else
    {
        printf("No numbers were entered.\n");
    }
    printf("Failure number = %d\n", failure_counter); // 去掉 -1 的影响

    return 0;
}