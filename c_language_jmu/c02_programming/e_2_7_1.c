#include <stdio.h>
int main()
{
	float numJan, numFeb, numMar, numAvg; // 变量的类型均为浮点型
	printf("请输入第1季度3个月的销售量：");
	scanf("%f %f %f", &numJan, &numFeb, &numMar);
	numAvg = (numJan + numFeb + numMar) / 3;
	printf("第1季度的平均销售量是：%f\n", numAvg);
	return 0;
}
