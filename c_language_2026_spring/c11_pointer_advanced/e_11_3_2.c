// Example 11-3-2: Use a two-level pointer to rewrite Example 11-1. A word list stores five English words representing colors.

#include <stdio.h>

int main(void)
{
    int i, flag = 0;
    char ch;
    const char *color[5] = {"red", "blue", "yellow", "green", "black"};
    const char **pc;

    pc = color;
    printf("%x\t%x\n", color, pc);

    for (i = 0; i < 5; i++)
    {
        printf("%x %s %c\t", color[i], color[i], *color[i]);
        printf("%x %s %c\n", *(pc + i), *(pc + i), **(pc + i));
    }

    for (i = 0; i < 5; i++)
    {
        printf("%x %s %c\t", color[i] + 1, color[i] + 1, *color[i] + 1);
        printf("%x %s %c\n", *(pc + i) + 1, *(pc + i) + 1, **(pc + i) + 1);
    }

    return 0;
}
