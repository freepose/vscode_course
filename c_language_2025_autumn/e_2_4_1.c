

// 例2-4-1：格式化输入/输出

#include <stdio.h>

int main()
{
    int first = 1, second = 2; 
    char ch;
    float result = 0;

    scanf("%d %c %d", &first, &ch, &second);

    if (ch == '+')
    {
        result = first + second;
    }
    else if (ch == '-')
    {
        result = first - second;
    }
    else if (ch == '*')
    {
        result = first * second;
    }
    else if (ch == '/')
    {
        if (second == 0)
        {
            printf("Error: division by zero\n");
            result = 0;
        }
        else
        {
            result = first / second;
        }
        
    }

    printf("%d %c %d = %0.2f", first, ch, second, result);

    return 0;
}
