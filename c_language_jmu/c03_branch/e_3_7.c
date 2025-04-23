#include <stdio.h>
int main()
{
	char option;  // 指令
	int user;	  // 账号
	int password; // 密码

	printf("请输入操作指令及用户账号、密码（空格隔开）：\n");
	scanf("%c %d %d", &option, &user, &password);

	if (option == 'L')
	{
		if (user == 123 && password == 369) // 账号密码正确
		{
			printf("登录成功！\n");
		}
		else
		{
			if (user != 123) // 用户名不正确
			{
				printf("用户名错误！\n");
			}
			else // 密码错误
			{
				printf("密码错误！\n");
			}
		}
	}
	if (option == 'N')
	{
		if (user == 123)
		{
			printf("用户已存在！\n");
		}
		else
		{
			printf("用户注册成功！\n");
		}
	}
	return 0;
}
