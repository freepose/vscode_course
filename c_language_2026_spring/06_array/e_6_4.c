
// 26个小写字母存入数组

#include <stdio.h>

int main()
{
    char alphabet[26] = {0};

    for (int i = 0; i < 26 ; i++)
    {
        alphabet[i] = 'A' + i;
    }

    for (int i = 0; i < 26 ; i++)
    {
        printf("%c(%d)\t", alphabet[i], (int)alphabet[i]);
    }


    return 0;
}