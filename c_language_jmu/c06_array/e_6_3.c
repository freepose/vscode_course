#include <stdio.h>
int main()
{
	int a[10];
	int i;
	printf("请输入10个整数：");
	for (i = 0; i < 10; i++) // 输入10个整数存入数组中
		scanf("%d", &a[i]);
	printf("存入数组的10个整数如下：\n");
	for (i = 0; i < 10; i++) // 依次输出10个数组元素
		printf("%d  ", a[i]);
	return 0;
}
