
// Example 11-2: two-level pointer

#include <stdio.h>
#include <string.h>

typedef char* string_pointer;   // for easy reading, define a type alias

void print_string_array(string_pointer arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%p -> %s\n", arr[i], arr[i]);
    }
}

int main()
{
    string_pointer colors[] = {
        "Red",
        "Green",
        "Blue",
        "Yellow",
        "Black"
    };
    int size = sizeof(colors) / sizeof(colors[0]);

    print_string_array(colors, size);

    string_pointer* pc = colors; // pointer to pointer to char

    printf("%c", *(*(pc + 2) + 1)); 

    return 0;
}