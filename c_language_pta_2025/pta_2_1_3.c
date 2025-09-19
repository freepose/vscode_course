
// 实验2-1-3-表达式 计算物体自由下落的距离

// 一个物体从100米的高空自由落下。编写程序，求它在前3秒内下落的垂直距离。设重力加速度为10米/秒的平方。结果保留2位小数。



#include <stdio.h>

int main()
{
    float height = 100;
    float g = 10;
    float t = 3;
    float distance;

    distance = g * t * t * 0.5;
    printf("height = %.2f", distance);

    return 0;
}