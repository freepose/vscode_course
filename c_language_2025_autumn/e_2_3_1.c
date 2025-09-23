

// 例2-4：分段函数。 异常值处理 -> 分支设计 -> 分段水费

#include <stdio.h>

int main()
{
    float fahr = 25, celsius;

    if (fahr > -273)    // 如果温度是正常，则进行温度转换
    {
        celsius = 5. * (fahr - 32) / 9;
        printf("%.2f°F -> %.2f°C ", fahr, celsius);
    }
    else                // 否则，输出错误信息
    {    
        printf("Error: Temperature below absolute zero.\n");
    }

    return 0;
}
