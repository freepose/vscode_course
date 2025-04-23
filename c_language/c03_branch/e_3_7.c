
// Example 3-7: Count letters, digits, and other characters.
// Input a positive integer n, and then n characters.
// Count the number of letters, digits, and other characters.

#include <stdio.h>
int main(void)
{
    int digit, i, letter, n, other; 
    char ch;                       

    digit = letter = other = 0; 
    printf("Enter n:");         
    scanf("%d", &n);
    
    getchar();   // abandon the '\n'
    printf("Enter %d characters:", n); 
    for (i = 1; i <= n; i++)
    {                 
        ch = getchar(); 
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            letter++;
        }
        else if (ch >= '0' && ch <= '9')
        {
            digit++;
        }
        else
        {
            other++; 
        }
    }
    printf("letter=%d, digit=%d, other=%d\n", letter, digit, other);

    return 0;
}
