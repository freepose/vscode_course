// 测量一个人的体积是很难的，但猫就不一样了。因为猫是液体，所以可以很容易地通过测量一个长方体容器的容积来得到容器里猫的体积。本题就请你完成这个计算。

// 输入格式：
// 输入在第一行中给出 3 个不超过 100 的正整数，分别对应容器的长、宽、高。

// 输出格式：
// 在一行中输出猫的体积。

// 输入样例：
// 23 15 20
// 输出样例：
// 6900

#include <stdio.h>

int main()
{
    int length, width, height;
    scanf("%d %d %d", &length, &width, &height);
    printf("%d", length * width * height);
    return 0;
}