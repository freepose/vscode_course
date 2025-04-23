#include <stdio.h>
int main()
{
    int Guojia = 100;     // 郭嘉的智商
    int Zhugeliang = 100; // 诸葛亮的智商
    int Simayi;           // 司马懿的智商
    int *Caocao, *Liubei;
    Liubei = &Zhugeliang; // 刘备的谋士指向诸葛亮
    Caocao = &Guojia;     // 曹操的谋士指向郭嘉
    printf("曹操的谋士郭嘉的智商：%d\n", *Caocao);
    printf("刘备的谋士诸葛亮的智商：%d\n", *Liubei);
    Caocao = &Simayi; // 曹操的谋士变成司马懿
    *Caocao = 99;     // 将曹操的谋士指向的对象的智商赋为99 == 修改曹操的谋士的智商
    printf("郭嘉的智商：%d\n", Guojia);
    printf("诸葛亮的智商：%d\n", Zhugeliang);
    printf("司马懿的智商：%d\n", Simayi);
    printf("刘备的谋士的智商：%d\n", *Liubei);
    printf("曹操的谋士的智商：%d\n", *Caocao);
    return 0;
}
