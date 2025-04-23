#include <stdio.h>
int main()
{
	int score;		 // 学生成绩
	int maxScore;	 // 最高分
	int minScore;	 // 最低分
	double avgScore; // 平均分
	int count = 0;	 // 统计人数
	maxScore = -1;
	minScore = 999;
	avgScore = 0;
	while (1)
	{
		printf("请输入成绩：");
		scanf("%d", &score);
		if (score < 0)
		{
			break; // 输入负值，提前结束循环
		}
		if (score > 100)
		{
			printf("成绩只能是0--100，请重输！\n");
			continue; // 成绩超过100，提示重输，结束本次循环
		}
		if (score > maxScore) // maxScore变量一直存最大值
		{
			maxScore = score;
		}
		if (score < minScore) // maxScore变量一直存最小值
		{
			minScore = score;
		}
		avgScore = avgScore + score; // 累加求和
		count++;
	}
	if (count != 0) // 平均分涉及除法运算，要判断分母是否为0
	{
		printf("最高分=%d，最低分=%d\n共有%d个学生，平均分=%.2f\n", maxScore, minScore, count, avgScore / count);
	}
	else
	{
		printf("没有成绩！！！\n");
	}
	return 0;
}
