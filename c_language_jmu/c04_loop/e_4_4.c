#include <stdio.h>
int main()
{
	char ch;	// 存二进制字符
	int number; // 存对应十进制数
	number = 0;
	printf("请输入二进制字符串：");
	while ((ch = getchar()) != '\n') // 即输入字符，又判断其是否为回车换行符
	{
		if (!(ch == '1' || ch == '0'))
		{
			printf("不合法的二进制字符");
			break; // 提前退出循环
		}
		number = number * 2 + ch - '0'; // 转成十进制数
	}
	printf("对应的十进制数=%d\n", number);
	return 0;
}
