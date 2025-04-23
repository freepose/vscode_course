#include <stdio.h>
#include <string.h>
int main()
{
	char myStr[100];
	int i, myLength;
	printf("请输入字符串：");
	gets(myStr);
	printf("输入的字符串为：");
	myLength = strlen(myStr); // myLength为输入的字符串的长度
	for (i = 0; i < myLength; i++)
		printf("%c", myStr[i]);
	return 0;
}
