
// Example 7-8-1: 2D array

#include <stdio.h>

void print_2d_array(int arr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("a[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

int main()
{
    int a[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_2d_array(a, 2, 3);

    // Demonstrating pointer arithmetic with 2D arrays
    printf("Using pointer arithmetic:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("a[%d][%d] = %d\n", i, j, *(*(a + i) + j));
        }
    }

    return 0;
}