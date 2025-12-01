

#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[105] = {0};
    scanf("%s", s);

    for (char *p = s; *p; p++)
    {
        if (isdigit(*p))
        {
            int num = 0;
            while (isdigit(*p))
            {
                num = num * 10 + (*p - '0');
                p++;
            }
            for (int i = 0; i < num; i++)
            {
                putchar(*p);
            }
        }
        else
        {
            putchar(*p);
        }
    }

    return 0;
}