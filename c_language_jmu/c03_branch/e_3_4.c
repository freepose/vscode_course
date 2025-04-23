#include <stdio.h>
int main()
{
	double height; // 表示身高
	double weight; // 表示体重
	double BMI;	   // 表示BMI值
	printf("请输入您的身高(m)、体重(kg):");
	scanf("%lf,%lf", &height, &weight);
	BMI = weight / (height * height); // 计算BMI值
	printf("您的BMI值为%.2f\n", BMI);
	if (BMI < 18.5)
	{
		printf("轻体重");
	}
	else if (BMI <= 23.9)
	{
		printf("体重正常");
	}
	else if (BMI <= 27.9)
	{
		printf("超重");
	}
	else if (BMI <= 32)
	{
		printf("肥胖");
	}
	else
	{
		printf("重度肥胖");
	}
	return 0;
}
