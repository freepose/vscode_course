
// Example 7-13: Convert a string of digits to an integer.
// Input a string terminated by a newline character (less than 10 characters), extract all digit characters ('0'...'9') from it, convert them to a decimal integer, and output the result.

#include <stdio.h>

int main(void)
{
    int i, number;
    char str[10];

    printf("Enter a string: ");
    i = 0;
    while ((str[i] = getchar()) != '\n')
    {
        i++;
    }
    str[i] = '\0';

    number = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            number = number * 10 + str[i] - '0';
        }
    }

    printf("digit = %d\n", number);

    return 0;
}

// Enter a string: a12d3
// digit = 123