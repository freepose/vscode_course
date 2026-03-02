
// Example 7-12: Caesar Cipher Encryption (Right Shift).
// To prevent information from being easily stolen, the plaintext of the code needs to be transformed into ciphertext through encryption. Input a string terminated by a newline character (less than 80 characters), and then input a positive integer offset. Use the Caesar cipher to encrypt it and output the result. The encryption rule of the Caesar cipher is to shift all letters in the plaintext backward by offset positions in the alphabet to generate ciphertext.

#include <stdio.h>

#define MAXN 80

#define M 26

int main(void)
{
    int i, offset;
    char str[MAXN];

    printf("Enter a string: ");
    i = 0;
    while ((str[i] = getchar()) != '\n')
    {
        i++;
    }
    str[i] = '\0';

    printf("Enter offset: ");
    scanf("%d", &offset);
    if (offset > M)
    {
        offset = offset % M;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if ((str[i] - 'A' + offset) < M)
            {
                str[i] = str[i] + offset;
            }
            else
            {
                str[i] = str[i] - (M - offset);
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            if ((str[i] - 'a' + offset) < M)
            {
                str[i] = str[i] + offset;
            }
            else
            {
                str[i] = str[i] - (M - offset);
            }
        }
    }

    printf("After being encrypted: ");
    for (i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
    }

    return 0;
}

// Enter a string: Hello Hangzhou
// Enter offset: 2
// After being encrypted: Jgnnq Jcpibjqw