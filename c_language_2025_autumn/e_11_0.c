
// Example 11-0: array vs. pointer

#include <stdio.h>


void print_array_v1(int *arr, int size)
{
    /// @param arr: Delivery by pointer
    /// @param size: Number of elements
    /// The array elements are accessed via indexing

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void print_array_v2(int *arr, int size)
{
    /// @param arr: Delivery by pointer
    /// @param size: Number of elements
    /// The array elements are accessed via pointer arithmetic and offset
    
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    char color1[] = {'H', 'e', 'l', 'l', 'o', '\0'};    // 数组名就是数组首地址
    char color2[] = "Hello, World!";
    char *color3 = "Hello, World!";
    char *p_part = &color2[3];

    // print_array_v1(&arr[1], size - 1);
    // print_array_v2(arr, size);

    printf("%s\n", color1);
    printf("%s\n", color2);
    printf("%s\n", p_part);

    return 0;
}