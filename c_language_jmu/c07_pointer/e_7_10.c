#include <stdio.h>
#include <string.h>
#define NAME "admin"
#define PASSWORD "admin"
int main()
{
	char userName[100], userPwd[20];
	char *namePoint = userName;
	int tryCount;
	for (tryCount = 1; tryCount <= 3; tryCount++)
	{
		printf("请输入用户名：");
		gets(namePoint);
		printf("请输入密码：");
		gets(userPwd);
		if (strcmp(namePoint, NAME) == 0 && strcmp(userPwd, PASSWORD) == 0)
		{
			printf("登录成功\n");
			break;
		}
		else if (tryCount < 3)
			printf("登录失败，请重输！\n");
		else
			printf("用户名密码错误3次，被锁定！\n");
	}
	return 0;
}
