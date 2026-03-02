
// Example 7-11: Palindrome String.
// Input a string terminated by a newline character (not exceeding 80 characters), and determine whether the string is a palindrome.

#include <stdio.h>

#define MAXN 80

int main(void)
{
    int i, k;
    char line[MAXN];

    printf("Entera string: ");
    k = 0;
    while ((line[k] = getchar()) != '\n')
    {
        k++;
    }
    line[k] = '\0';

    i = 0;
    k = k - 1;

    while (i < k)
    {
        if (line[i] != line[k])
        {
            break;
        }
        i++;
        k--;
    }
    if (i >= k)
    {
        printf("It is a plalindrome\n");
    }
    else
    {
        printf("It is not a plalindrome\n");
    }

    return 0;
}

// Enter a string: radar
// It is a plalindrome

// Enter a string: reader
// It is not a plalindrome