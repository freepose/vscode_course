#include <stdio.h>
int main()
{
	float radius, height, areaBottom, areaSide, volume;
	printf("请输入圆柱体的底面半径和高度：");	  // 输出提示性语句
	scanf("%f, %f", &radius, &height);			  // 以逗号分隔输入的两个浮点数
	areaBottom = 3.14 * radius * radius;		  // 计算圆柱体的底面积
	areaSide = 2 * 3.14 * radius * height;		  // 计算圆柱体的侧面积
	volume = areaBottom * height;				  // 计算圆柱的体体积
	printf("圆柱体的底面积为：%f\n", areaBottom); // 输出圆柱体的底面积
	printf("圆柱体的侧面积为：%f\n", areaSide);	  // 输出圆柱体的侧面积
	printf("圆柱体的体积为：%f\n", volume);		  // 输出圆柱体的体积
	return 0;
}
