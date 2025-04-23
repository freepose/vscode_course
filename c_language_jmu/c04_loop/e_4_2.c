#include <stdio.h>
int main()
{
	int i;	 // 循环变量
	int sum; // 累加值
	int n;	 // 累加次数
	scanf("%d", &n);
	sum = 0; // sum要有初值0
	for (i = 1; i <= n; i++)
	{
		sum = sum + i;
	}
	printf("sum=%d", sum);
	return 0;
}
