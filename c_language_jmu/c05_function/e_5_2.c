#include <stdio.h>

int LeapYear(int n) // LeapYear()函数判断n是否为闰年
{
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400) == 0)
		return 1; // 是闰年返回值1
	else
		return 0; // 不是闰年返回值0
}

int main()
{
	int x, y, i, count = 0; // count保存闰年数
	printf("请输入x年和y年：");
	scanf("%d %d", &x, &y);
	for (i = x; i <= y; i++)
		if (LeapYear(i))
			count++;
	printf("%d年和%d年之间的闰年数为%d", x, y, count);
	return 0;
}
