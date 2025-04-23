
// Example 8-8: Input a string with a length less than 80, compress the string according to the rules, and output the compressed string.
// The compression rule is: if a character x appears continuously n (n>1) times, replace these n characters with "nx"; otherwise, keep it unchanged.

#include <stdio.h>

#define MAXLINE 80

void zip(char *p);

int main(void)
{
    char line[MAXLINE];

    printf("Input the string: ");
    gets(line);
    zip(line);
    puts(line);

    return 0;
}

void zip(char *p)
{
    char *q = p;
    int n;

    while (*p != '\0')
    {
        n = 1;
        while (*p == *(p + n))
        {
            n++;
        }
        if (n >= 10)
        {
            *q++ = (n / 10) + '0';
            *q++ = (n % 10) + '0';
        }
        else if (n >= 2)
        {
            *q++ = n + '0';
        }
        *q++ = *(p + n - 1);
        p = p + n;
    }
    *q = '\0';
}

// Input the string: Mississippi
// Mi2si2si2pi