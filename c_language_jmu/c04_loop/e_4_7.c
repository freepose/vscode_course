#include <stdio.h>
int main()
{
	char ch;		// 存放输入的字符
	int letter = 0; // 统计字母字符个数
	int digit = 0;	// 统计数字字符个数
	int space = 0;	// 统计空格个数
	printf("请输入一行字符:\n");
	do
	{
		ch = getchar();
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			letter++; // 统计英文字符;
			continue; // 提前结束本次循环，下面分支不进入。
		}
		if (ch >= '0' && ch <= '9')
		{
			digit++; // 统计数字字符;
			continue;
		}
		if (ch == ' ')
		{
			space++; // 统计空格字符;
		}
	} while (ch != '\n');
	printf("letter=%d,digit=%d,space=%d", letter, digit, space);
	return 0;
}
