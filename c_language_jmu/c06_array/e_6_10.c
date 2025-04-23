#include <stdio.h>
int main()
{
	char myStr[100];
	printf("请输入字符串：");
	scanf("%s", myStr);
	printf("存入数组中的字符串为：");
	printf("%s\n", myStr);
	return 0;
}
