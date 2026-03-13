
// operations: +-*/

#include <stdio.h>

int main()
{
    float first, second, result;
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
            printf("Error: Division by zero is not allowed!\n");
            return 1; // Exit with an error code
        }
        result = first / second;
    }
    else
    {
        printf("Invalid operator!\n");
        return 1; // Exit with an error code
    }

    printf("%.2f %c %.2f = %.2f\n", first, op, second, result);
    

    return 0;
}