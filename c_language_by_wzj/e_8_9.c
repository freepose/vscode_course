
// Example 8-9: Memory management in C

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // malloc() allocates memory dynamically
    // free() deallocates memory that was previously allocated by malloc()

    int *p = 0; // null pointer
    const int size = 1024 * 1024 * 512; // 1G elements

    int temp = 0;

    p = (int *)malloc(size * sizeof(int));

    if (p == 0)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    else
    {
        printf("Memory allocation succeeded\n");
        for (int i = 0; i < size; i++)
        {
            p[i] = i;
        }
    }

    free(p); 

    return 0;
}