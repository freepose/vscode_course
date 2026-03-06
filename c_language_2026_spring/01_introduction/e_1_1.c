
#include <stdio.h>

int main()
{
    int first, second, sum;

    printf("Enter the first number: ");
    scanf("%d %d", &first, &second);

    if (first > second)
    {
        printf("The larger number is: %d\n", first);
    }
    else if (first == second)
    {
        printf("Both numbers are equal.\n");
    }
    else
    { 
        printf("The larger number is: %d\n", second);
    }

    return 0;
}