#include <stdio.h>
int main()
{
	float radius, height, areaBottom, areaSide, volume;
	printf("请输入圆柱体的底面半径和高度：");
	scanf("%f, %f", &radius, &height);
	areaBottom = 3.1415926 * radius * radius;	// 此处出现了圆周率
	areaSide = 2 * 3.1415926 * radius * height; // 此处出现了圆周率
	volume = areaBottom * height;
	printf("圆柱体的底面积为：%f\n", areaBottom);
	printf("圆柱体的侧面积为：%f\n", areaSide);
	printf("圆柱体的体积为：%f\n", volume);
	return 0;
}
