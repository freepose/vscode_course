#include <stdio.h>
int main()
{
	int left;  // 左区间
	int right; // 右区间
	int digit; // 指定数字
	int count; // 统计次数
	int flag;  // 当前数是否包含指定数字
	int number;
	int i;
	count = 0; // 次数初值为0
	printf("请输入区间及要统计的数字:");
	scanf("%d%d%d", &left, &right, &digit);
	for (i = left; i <= right; i++) // 区间
	{
		number = i;
		flag = 0; // 初始为未包含数字
		do
		{
			if (number % 10 == digit) // 取个位数字
			{
				count++;
				flag = 1; // 当前数包含指定数字
			}
			number = number / 10; // 去掉个位数字
		} while (number != 0);
		if (flag == 1)
		{
			printf("number=%d\n", i); // 输出包含指定数字的数
		}
	}
	printf("%d出现的次数为%d\n", digit, count);
	return 0;
}
