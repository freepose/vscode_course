
// Example 4-4: Reverse the digits of an integer
// Input an integer and output its digits in reverse order

#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);
    do
    {
        printf("%d ", number % 10);
        number = number / 10;
    } while (number != 0);

    return 0;
}

// Enter a number: 12345
// 5 4 3 2 1