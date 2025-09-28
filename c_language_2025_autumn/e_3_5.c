

// 例3-5：四则运算

#include <stdio.h>

int main()
{
    float first = 1, second = 2, result = 0;
    char op;

    scanf("%f %c %f", &first, &op, &second);

    if (op == '+')
    {
        result = first + second;
    }
    else if (op == '-')
    {
        result = first - second;
    }
    else if (op == '*')
    {
        result = first * second;
    }
    else if (op == '/')
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
    else
    {
        printf("Error: unknown operator '%c'\n", op);
        return 0;
    }

    printf("%.2f %c %.2f = %0.2f", first, op, second, result);
    return 0;
}
