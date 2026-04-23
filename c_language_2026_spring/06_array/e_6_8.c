
// Example 6-8: 字符数组

#include <stdio.h>
#include <string.h>

#define N 200


int main()
{
    char a[N] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char b[N] = {0};

    int length = strlen(a);

    for (int i = 0; i < length; i++)
    {
        // printf("%c", a[i]);
        b[i] = a[length - 1 - i];
    }
    b[length] = '\0';

    printf("%s", b);

    return 0;
}