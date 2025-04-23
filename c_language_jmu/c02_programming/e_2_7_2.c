#include <stdio.h>
int main()
{
	int numJan;	  // 1月份的销售量
	int numFeb;	  // 2月份的销售量
	int numMar;	  // 3月份的销售量
	float numAvg; // 第1季度的平均销售量，变量numAvg的类型为浮点型
	printf("请输入第1季度3个月的销售量：");
	scanf("%d %d %d", &numJan, &numFeb, &numMar); // 以空格分隔输入3个整数
	numAvg = (numJan + numFeb + numMar) / 3.0;
	printf("第1季度的平均销售量是：%f\n", numAvg); // 注意输出格式字符为%f
	return 0;
}
