
// pointer type array

#include <stdio.h>
#include <string.h>

void print_string_array(char *arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%p -> %s\n", arr[i], arr[i]);
    }
}

void sort_string_array_asc(char *arr[], int size)
{
    /// @param arr: Array of string pointers
    /// @param size: Number of elements
    /// You should note that the array elements are points, and the swapping is for pointers (not string content)

    // Bubble Sort

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char* colors[] = {
        "Red",
        "Green",
        "Blue",
        "Yellow",
        "Black"
    };

    int size = sizeof(colors) / sizeof(colors[0]);

    print_string_array(colors, size);
    sort_string_array_asc(colors, size);
    print_string_array(colors, size);

    return  0;
}