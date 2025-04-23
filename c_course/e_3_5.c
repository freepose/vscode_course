#include<stdio.h>

int main()
{   
    int f = 0, s = 0, r = 0;
    char op = '+';   
    scanf("%d%c%d", &f, &op, &s);
    switch (op)
    {
    case '+': r = f + s; //break;
    case '-': r = f - s; //break;
    case '*': r = f * s; //break;
    case '/': r = f / s; //break;
    default:
        break;
    }
    printf("%d %c %d = %d", f, op, s, r);

    printf("\nhello world!");
    return 0;
}