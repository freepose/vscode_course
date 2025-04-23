#include <stdio.h>
int main()
{
	int number;
	printf("请输入一个整数：");
	scanf("%d", &number);
	if (number % 3 == 0) // 判断整数是否为3的倍数
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
