
// Example 11-1: A word list stores five English words representing colors.
// Input a letter, search for and output all the words that start with this letter in the word list. If not found, output "Not Found".

#include <stdio.h>

int main(void)
{
    int i, flag = 0;
    char ch;
    const char *color[5] = {"red", "blue", "yellow", "green", "black"};

    printf("Input a letter: ");
    ch = getchar();
    for (i = 0; i < 5; i++)
    {
        if (*color[i] == ch)
        {
            flag = 1;
            puts(color[i]);
        }
    }
    if (flag == 0)
    {
        printf("Not Found\n");
    }

    return 0;
}

// Input a letter: y
// yellow

// Input a letter: a
// Not Found