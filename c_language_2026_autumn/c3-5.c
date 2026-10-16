
#include <stdio.h>

int main()
{
    float f = 1, s = 2;
    char op = '+';

    scanf("%f%c%f", &f, &op, &s);

    if (op == '+')
    {
        printf("%f %c %f = %f\n", f, op, s, f + s);
    }
    else if (op == '-')
    {
        printf("%f %c %f = %f\n", f, op, s, f - s);
    }
    else if (op == '*')
    {
        printf("%f %c %f = %f\n", f, op, s, f * s);
    }
    else if (op == '/')
    {
        if (s == 0)
        {
            printf("error: division is 0.");
        }
        else
        {
            printf("%f %c %f = %f\n", f, op, s, f / s);
        }
    }

    return 0;
}