
// Example 3-9: Simple calculator for two numbers.

#include <stdio.h>

int main(void)
{
    int value1, value2;
    char op;

    printf("Type in an expression: ");
    scanf("%d%c%d", &value1, &op, &value2);
    switch (op)
    {
    case '+': printf("=%d\n", value1 + value2); break;
    case '-': printf("=%d\n", value1 - value2); break;
    case '*': printf("=%d\n", value1 * value2); break;
    case '/':
        if (value2 != 0)
        {
            printf("=%d\n", value1 / value2);
        }
        else
        {
            printf("Divisor can not be 0!\n");
        }
        break;
    case '%':
        if (value2 != 0)
        {
            printf("=%d\n", value1 % value2);
        }
        else
        {
            printf("Divisor can not be 0!\n");
        }
        break;
    default:
        printf("Unknown operator\n");
        break;
    }

    return 0;
}
