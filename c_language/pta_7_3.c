
// pintia.cn
// Example 7-3 删除重复字符

#include <stdio.h>

int main()
{
    char str[80];
    int count[128] = {0};
    int i = 0;
    char c;

    while ((c = getchar()) != '\n')
    {
        str[i++] = c;
    }
    str[i] = '\0';

    for (i = 0; str[i] != '\0'; i++)
    {
        count[str[i]]++;
    }

    for (i = 0; i < 128; i++)
    {
        if (count[i] > 0)
        {
            printf("%c", i);
        }
    }

    return 0;
}