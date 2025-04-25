
// pitia.cn, https://pintia.cn/problem-sets/1838054583869140992/problems/type/7?problemSetProblemId=1838054584081469440

// 编程题：7-1房号的玄机

#include <stdio.h>

int main()
{
    char num[9];
    int k;
    scanf("%s %d", num, &k);
    printf("level=");
    for (int i = 0; i < k; i++)
    {
        printf("%c", num[i]);
    }
    printf(",room=");
    for (int i = k; i < 8; i++)
    {
        printf("%c", num[i]);
    }
    return 0;
}