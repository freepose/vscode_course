
// Example 7-14: Convert a hexadecimal string to a decimal non-negative integer.
// Input a string terminated by '#' (less than 10 characters), filter out all non-hexadecimal characters (case insensitive), form a new string representing hexadecimal digits, output the string, and convert it to a decimal number for output.

#include <stdio.h>

#define MAXLINE 80

int main(void)
{
    int i, k, number;
    char hexad[MAXLINE], str[MAXLINE];

    printf("Enter a string: ");
    i = 0;
    while ((str[i] = getchar()) != '#')
    {
        i++;
    }
    str[i] = '\0';

    i = 0;
    k = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
        {
            hexad[k] = str[i];
            k++;
        }
        i++;
    }
    hexad[k] = '\0';

    printf("New string: ");
    for (i = 0; hexad[i] != '\0'; i++)
    {
        putchar(hexad[i]);
    }
    printf("\n");

    number = 0;
    for (i = 0; hexad[i] != '\0'; i++)
    {
        if (hexad[i] >= '0' && hexad[i] <= '9')
        {
            number = number * 16 + hexad[i] - '0';
        }
        else if (hexad[i] >= 'A' && hexad[i] <= 'F')
        {
            number = number * 16 + hexad[i] - 'A' + 10;
        }
        else if (hexad[i] >= 'a' && hexad[i] <= 'f')
        {
            number = number * 16 + hexad[i] - 'a' + 10;
        }
    }
    printf("Number = %d\n", number);

    return 0;
}

// Enter a string: -zy1+Ak0-bq?#
// New string: 1A0b
// Number = 6667