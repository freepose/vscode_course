#include <stdio.h>
int main()
{
	int stuScore[10];
	int i, sumScore = 0, count = 0;
	float avgScore;
	printf("请输入10位同学的成绩：");
	for (i = 0; i < 10; i++) // 输入每位同学的成绩，并求和
	{
		scanf("%d", &stuScore[i]);
		sumScore += stuScore[i];
	}
	avgScore = sumScore / 10.0;
	printf("10位同学的平均分为：%f\n", avgScore);
	for (i = 0; i < 10; i++) // 判断每位同学的成绩是否大于平均分
		if (stuScore[i] > avgScore)
			count++;
	printf("10位同学中成绩大于平均分的人数为：%d\n", count);
	return 0;
}
