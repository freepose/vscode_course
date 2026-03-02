
// Example 6-1: This program converts uppercase letters to lowercase and vice versa.
// It takes a line of characters as input and outputs the converted characters, leaving other characters unchanged.

#include <stdio.h>

int main(void)
{
    char ch;

    printf("Input characters: ");
    ch = getchar();

    while (ch != '\n')
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
        }
        putchar(ch);
        ch = getchar();
    }

    return 0;
}

// Input characters: Reold 123?
// rEOLD 123?