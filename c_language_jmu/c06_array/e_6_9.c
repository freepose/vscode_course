#include <stdio.h>
int main()
{
	char c, myStr[100];
	int i = 0;
	printf("请输入字符串：");
	// 从键盘输入一个字符串存入数组myStr中
	while ((c = getchar()) != '\n')
	{
		myStr[i] = c;
		i++;
	}
	myStr[i] = '\0'; // 字符串结束标志
	printf("输入的字符串为：");
	// 遍历字符串并输出
	i = 0;
	while (myStr[i] != '\0')
		printf("%c", myStr[i++]);
	printf("\n");
	return 0;
}
