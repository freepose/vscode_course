
// char array

#include <stdio.h>

void print_char_array(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // printf("arr[%d] = %d\n", i, arr[i]);
        printf("%c", arr[i]);
    }
}

int main()
{
    char str[] = "Hello";
    char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    print_char_array(str, 5);
    printf("\n");
    print_char_array(str2, 5);
    printf("\n");

    printf("%s\n", str);
    printf("%s\n", str2);
    
    return 0;
}

