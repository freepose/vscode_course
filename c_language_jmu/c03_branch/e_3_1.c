#include <stdio.h>
int main()
{
	char sex;
	int height;
	int weight;
	printf("请输入您的性别、身高：");
	scanf("%c %d", &sex, &height);
	if (sex == 'F') // 女性标准体重计算
	{
		weight = height - 105;
	}
	else // 男性标准体重计算
	{
		weight = height - 100;
	}
	printf("您的标准体重是：%d", weight);
	return 0;
}
