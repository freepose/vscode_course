
// operations: +-*/ using switch statement

#include <stdio.h>

int main()
{
    float first, second, result;
    char op;

    scanf("%f %c %f", &first, &op, &second);

    switch (op)
    {
    case '+':
        result = first + second;
        break;
    case '-':
        result = first - second;
        break;
    case '*':
        result = first * second;
        break;
    case '/':
        if (second == 0)
        {
            printf("Error: Division by zero is not allowed!\n");
            return 1;
        }
        result = first / second;
        break;
    default:
        printf("Invalid operator!\n");
        return 1;
    }
    printf("%.2f %c %.2f = %.2f\n", first, op, second, result);


    return 0;
}