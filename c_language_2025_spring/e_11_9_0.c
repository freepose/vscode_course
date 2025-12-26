
// Example 11-9-0 

#include <stdio.h>

void arithmetic(int a, char op, int b)
{
    switch (op)
    {
    case '+':
        printf("%d + %d = %d\n", a, b, a + b);
        break;
    case '-':
        printf("%d - %d = %d\n", a, b, a - b);
        break;
    case '*':
        printf("%d * %d = %d\n", a, b, a * b);
        break;
    case '/':
        if (b != 0)
            printf("%d / %d = %d\n", a, b, a / b);
        else
            printf("Error: Division by zero\n");
        break;
    default:
        printf("Error: Unknown operator '%c'\n", op);
        break;
    }
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    if (b != 0)
        return a / b;
    else
    {
        printf("Error: Division by zero\n");
        return 0; // Return 0 or handle error as needed
    }
}

void arithmetic_enhanced(int(*op)(int, int), int a, int b)
{
    int result = op(a, b);
    printf("Result: %d\n", result);
}

int main()
{
    // arithmetic(10, '+', 5);
    arithmetic_enhanced(add, 10, 5);
    arithmetic_enhanced(subtract, 10, 5);

    return 0;
}