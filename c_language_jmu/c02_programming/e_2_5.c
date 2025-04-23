#include <stdio.h>
#define PI 3.14 // 定义了一个宏名PI，表示的值为3.14
int main()
{
	float radius, height, areaBottom, areaSide, volume;
	printf("请输入圆柱体的底面半径和高度：");
	scanf("%f, %f", &radius, &height);
	areaBottom = PI * radius * radius;	 // 此处出现了宏名PI
	areaSide = 2 * PI * radius * height; // 此处出现了宏名PI
	volume = areaBottom * height;
	printf("圆柱体的底面积为：%f\n", areaBottom);
	printf("圆柱体的侧面积为：%f\n", areaSide);
	printf("圆柱体的体积为：%f\n", volume);
	return 0;
}
