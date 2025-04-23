#include <stdio.h>
int main()
{
	int numJan;									  // 1月份的销售量
	int numFeb;									  // 2月份的销售量
	int numMar;									  // 3月份的销售量
	float numAvg;								  // 第1季度的平均销售量
	printf("请输入第1季度3个月的销售量：");		  // 输出提示性语句
	scanf("%d %d %d", &numJan, &numFeb, &numMar); // 以空格分隔输入3个整数
	numAvg = (float)(numJan + numFeb + numMar) / 3;
	printf("第一季度平均销售量是：%f\n", numAvg);
	return 0;
}
