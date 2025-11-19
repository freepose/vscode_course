
// What is variable address in C?

#include <stdio.h>

int main()
{
    // memory size of data types
    printf("Size of char: %zu byte(s)\n", sizeof(char));
    printf("Size of int: %zu byte(s)\n", sizeof(int));
    printf("Size of float: %zu byte(s)\n", sizeof(float));
    printf("Size of double: %zu byte(s)\n", sizeof(double));

    // memory size of pointers of different data types
    printf("Size of char*: %zu byte(s)\n", sizeof(char*));
    printf("Size of int*: %zu byte(s)\n", sizeof(int*));
    printf("Size of float*: %zu byte(s)\n", sizeof(float*));
    printf("Size of double*: %zu byte(s)\n", sizeof(double*));

    int n = 5, *p;

    p = &n; // address of variable n is assigned to pointer p
    printf("%p\n", p);
    printf("%d\n", *p); // value of n through pointer p

    return 0;
}