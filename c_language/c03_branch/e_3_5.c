
// Example 3-5: Solving simple arithmetic expressions.
// Input a simple arithmetic expression and output the result. Special handling is required for division by zero.

#include <stdio.h>
int main(void)
{
    double value1, value2;
    char op;

    printf("Type in an expression: ");        
    scanf("%lf%c%lf", &value1, &op, &value2);

    if (op == '+')
    {                                      
        printf("=%.2f\n", value1 + value2);
    }
    else if (op == '-')
    { 
        printf("=%.2f\n", value1 - value2);
    }
    else if (op == '*')
    {
        printf("=%.2f\n", value1 * value2);
    }
    else if (op == '/')
    {
        if (value2 != 0)
        {
            printf("=%.2f\n", value1 / value2);
        }
        else
        {
            printf("Divisor can not be 0!\n");
        }
    }
    else
    { 
        printf("Unknown operator!\n");
    }

    return 0;
}

// Type in an expression: 3.1+4.8
// =7.90