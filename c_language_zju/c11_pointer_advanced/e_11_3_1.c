
// Example 11-3-1: Use a two-level pointer to rewrite Example 11-1. A word list stores five English words representing colors.
// Input a letter, search for and output all the words that start with this letter in the word list. If not found, output "Not Found". The requirement is to use a pointer array and a two-level pointer to implement it.

#include <stdio.h>

int main(void)
{
    int i, flag = 0;
    char ch;
    const char *color[5] = {"red", "blue", "yellow", "green", "black"};
    const char **pc;

    pc = color;
    printf("Input a letter:");
    ch = getchar();
    for (i = 0; i < 5; i++)
    {
        if (**(pc + i) == ch)
        {
            flag = 1;
            puts(*(pc + i));
        }
    }

    if (flag == 0)
    {
        printf("Not Found\n");
    }

    return 0;
}
