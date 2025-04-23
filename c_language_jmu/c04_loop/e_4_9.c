#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	int userPassword; // 用户输入的密码
	int i, j, k;	  // 3个循环变量
	int flag = 0;	  // 找到标志
	printf("请输入密码：");
	scanf("%d", &userPassword);
	printf("开始暴力破解.....\n");
	Sleep(10);
	for (i = 0; i <= 9; i++) // 第一层循环
	{
		for (j = 0; j <= 9; j++) // 第二层循环
		{
			for (k = 0; k <= 9; k++) // 第三层循环
			{
				printf("破解密码：%d%d%d\n", i, j, k);
				Sleep(10);
				if (i == userPassword / 100 && k == userPassword % 10 && j == userPassword / 10 % 10) // 分解密码的各个位数
				{
					printf("！！！密码破解了：%d%d%d", i, j, k);
					flag = 1; // 找到标志
					break;
				}
			}
			if (flag == 1)
				break; // break只能退出当前循环。
		}
		if (flag == 1)
			break; // break只能退出当前循环。
	}
	return 0;
}
