
// Example 4-2: 循环如数 -- 用输入的标识数字，结束输入

// 67 88 73 54 82 -1

#include <stdio.h>

int main()
{
    int temp = 0, sum = 0, counter = 0, failure_counter = 0;
    double average = 0.0;

    while (1)
    {
        scanf("%d", &temp);
        if (temp == -1)
        {
            break;  
        }

        if (temp < 60)
        {
            failure_counter++;
        }

        sum += temp;
        counter++;  // counter = counter + 1; // counter += 1;
    }

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
    printf("Failure number = %d\n", failure_counter);

    return 0;
}