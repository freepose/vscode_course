
// Pointer Introduction
                                     

#include <stdio.h>

int main()
{
    int n;
    int* p = 0;

    p = &n;

    scanf("%d", &n);    // 取地址运算符 vs. 取内容运算符
    printf("%p -> %d", p, *p);

    return 0;
}