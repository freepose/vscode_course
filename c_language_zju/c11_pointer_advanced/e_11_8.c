
// Example 11-8: Input a string and a character.
// If the character is in the string, output the characters in the string starting from the first occurrence of that character. For example, if you input the character 'r' and the string "program", output "rogram". Define a function match(char *s, char ch) to find the position (address) of the first occurrence of character ch in string s. If found, return that address; otherwise, return NULL.

#include <stdio.h>

char *match(char *s, char ch);

int main(void)
{
    char ch, str[80], *p = NULL;

    printf("Input the string: ");
    scanf("%s", str);
    getchar();
    printf("Input a characters: ");
    ch = getchar();
    if ((p = match(str, ch)) != NULL)
    {
        printf("%s\n", p);
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}

char *match(char *s, char ch)
{
    while (*s != '\0')
    {
        if (*s == ch)
        {
            return (s);
        }
        s++;
    }

    return (NULL);
}

// Input the string: University
// Input a characters: v
// versity

// Input the string: School
// Input a characters: a
// Not Found