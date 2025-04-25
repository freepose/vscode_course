
// 字符数组

#include <stdio.h>
#include <string.h> 

int main()
{
    // char buffer[20] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'}; 
    // for (int i = 0; i < 20; i++)
    // {
    //     printf("%c", buffer[i]);
    // }

    char *buffer2 = "Hello World"; // 字符串常量
    printf("%s\n", buffer2);

    char s1[] = "hello"; // 字符串常量
    char s2[] = "world"; // 字符数组

    printf("%d", strcmp(s1, s2));

    return 0;
}
