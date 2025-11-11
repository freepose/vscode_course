
// 越界求余：回绕字母表

#include <stdio.h>

int main()
{
    char c, data[81];
    int i = 0, x;

    // 读一行，最多80字符，遇到换行停止
    while (scanf("%c", &c) == 1 && c != '\n' && i < 80)
    {
        data[i++] = c;
    }
    data[i] = '\0';

    if (scanf("%d", &x) != 1) return 0;

    x %= 26; // 归一化到 [-25, 25]

    for (int j = 0; j < i; j++)
    {
        if (data[j] >= 'a' && data[j] <= 'z')
        {
            data[j] = 'a' + (data[j] - 'a' + x + 26) % 26;
        }
        else if (data[j] >= 'A' && data[j] <= 'Z')
        {
            data[j] = 'A' + (data[j] - 'A' + x + 26) % 26;
        }
        // 非字母保持不变
    }

    for (int j = 0; j < i; j++)
    {
        printf("%c", data[j]);
    }
    printf("\n");
    return 0;
}