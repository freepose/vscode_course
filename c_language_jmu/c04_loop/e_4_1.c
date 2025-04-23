#include <stdio.h>
int main()
{
	char sex;		// 表示性别
	int height;		// 表示身高
	int weight;		// 表示体重
	int userNumber; // 表示用户数量
	int i;			// 循环变量
	userNumber = 5;
	for (i = 1; i <= userNumber; i++)
	{
		printf("请输入您的性别及身高：");
		scanf("%c %d", &sex, &height);
		if (sex == 'F') // 女性标准体重计算
		{
			weight = height - 105;
		}
		else // 男性标准体重计算
		{
			weight = height - 100;
		}
		printf("您的标准体重是：%d\n", weight);
	}
	return 0;
}
