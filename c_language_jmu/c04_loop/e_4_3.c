#include <stdio.h>
int main()
{
	int i;		  // 循环变量
	double sum;	  // 累加值
	int n;		  // 累加次数
	double item;  // 累加每一项数据
	int flag = 1; // 正负标志变量
	scanf("%d", &n);
	sum = 0; // sum要有初值0
	for (i = 1; i <= n; i++)
	{
		item = flag * 1.0 / i; // 求每个数据项
		sum = sum + item;	   // 求累加和
		if (flag == 1)
		{
			printf("+1/%d", i);
		}
		else
		{
			printf("-1/%d", i);
		}
		flag = -flag; // 实现正负交替
	}
	printf("\nsum=%.3f", sum);
	return 0;
}
