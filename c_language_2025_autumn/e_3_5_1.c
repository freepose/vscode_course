

// 例3-5-1：四则运算 switch 版本

#include <stdio.h>

int main()
{
    float first = 1, second = 2, result = 0;
    char op;

    scanf("%f %c %f", &first, &op, &second);

    switch (op)
    {
        case '+': result = first + second; break;
        case '-': result = first - second; break;
        case '*': result = first * second; break;
        case '/':
            if (second == 0)
            {
                printf("Error: division by zero\n");
                return 0;
            }
            else
            {
                result = first / second;
            }
        
        break;
        default:
            printf("Error: unknown operator '%c'\n", op);
            return 0;
        
    }

    printf("%.2f %c %.2f = %0.2f", first, op, second, result);
    return 0;
}
