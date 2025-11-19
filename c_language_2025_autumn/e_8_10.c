
// Example 8-10: malloc() and free()

#include <stdio.h>
#include <stdlib.h> // for malloc() and free()

#define MAX_SIZE 1024 * 1024

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // printf("arr[%d] = %d\n", i, arr[i]);
        printf("%d", arr[i]);
        if (i != n - 1)
        {
            printf("\t");
        }
    }
}

int main()
{
    // int a[MAX_SIZE] = {0};

    int *p = (int *)malloc(MAX_SIZE * sizeof(int)); // dynamic memory allocation

    print_array(p, MAX_SIZE);

    free(p);    // free the allocated memory

    return 0;
}