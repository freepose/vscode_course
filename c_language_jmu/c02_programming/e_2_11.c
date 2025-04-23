#include <stdio.h>
#include <math.h>
int main()
{
	float x, y;
	printf("请输入x的值：");
	scanf("%f", &x);
	y = (pow(x, 3) - sqrt(fabs(x))) / (2 * x);
	printf("y的值为：%f", y);
	return 0;
}
