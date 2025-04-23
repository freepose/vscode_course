#include <stdio.h>
int main()
{
	int num;
	printf("请输入num的值：");
	scanf("%d", &num);
	num += num -= num *= num;
	printf("运算后num的值为：%d", num);
	return 0;
}
