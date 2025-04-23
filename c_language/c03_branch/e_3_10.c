
// Example 3-10: Input a integer n, and then input n characters. Count the number of blanks, digits, and other characters in a string.

#include <stdio.h>

int main(void)
{
    int blank, digit, i, n, other; 
    char ch;

    blank = digit = other = 0; 
    printf("Enter n:");       
    scanf("%d", &n);
    getchar();                       
    printf("Enter %d characters:", n); 
    for (i = 1; i <= n; i++)
    {                  
        ch = getchar();

        switch (ch)
        {
        case ' ':
        case '\n': blank++;  break;  
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            digit++;
            break;  
        default:
            other++; 
            break;  
        }
    }
    printf("blank = %d, digit = %d, other = %d\n", blank, digit, other);

    return 0;
}

// 