#include <stdio.h>
int main()
{
	char myStr[15];
	printf("请输入字符串：");
	gets(myStr);
	printf("输入的字符串为：");
	puts(myStr);
	return 0;
}
