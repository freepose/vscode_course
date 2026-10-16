
#include <stdio.h>

int main()
{
    float f = 1, s = 2;
    char op = '+';

    scanf("%f%c%f", &f, &op, &s);

    switch (op)
    {
    case '+':
        printf("%f %c %f = %f\n", f, op, s, f + s);
        break;
    case '-':
        printf("%f %c %f = %f\n", f, op, s, f - s);
        break;
    case '*':
        printf("%f %c %f = %f\n", f, op, s, f * s);
        break;
    case '/':
        if (s == 0)
        {
            printf("error: division is 0.");
        }
        else
        {
            printf("%f %c %f = %f\n", f, op, s, f / s);
        }
        break;
    default:
        printf("Operator exception\n");
        break;
    }

    return 0;
}