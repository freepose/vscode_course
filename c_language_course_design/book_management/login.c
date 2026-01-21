#include <stdio.h>
#include <string.h>
#include "login.h"

/* 系统登录密码 */
#define PASSWORD "123456"

/* 登录函数 */
int login(void)
{
    char input[20];
    int attempts = 3;

    while (attempts--)
    {
        printf("请输入登录密码（剩余 %d 次）：", attempts + 1);
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0)
        {
            printf("登录成功！\n");
            return 1;
        }
        else
        {
            printf("密码错误！\n");
        }
    }

    printf("三次密码均输入错误，系统退出。\n");
    return 0;
}
