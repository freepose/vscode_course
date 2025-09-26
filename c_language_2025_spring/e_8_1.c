
// Chapter 8: Pointer

// Example 8-1: Pointer as variable, using pointer type variable to store address of another variable

#include <stdio.h>

int main()
{
    char ch = 'a';
    char *p1 = &ch;

    int n = 5;
    int *p2 = &n;

    double d = 5.0;
    double *p3 = &d;

    printf("ch = %c, p1 = %p\n", ch, p1);
    printf("n = %d, p2 = %p\n", n, p2);
    printf("d = %f, p3 = %p\n", d, p3);

    printf("sizeof char = %zu, sizeof char* = %zu\n", sizeof(char), sizeof(char*));
    printf("sizeof int = %zu, sizeof int* = %zu\n", sizeof(int), sizeof(int*));
    printf("sizeof double = %zu, sizeof double* = %zu\n", sizeof(double), sizeof(double*));

    int x = 55;
    int *px = &x;

    printf("x = %d, *px = %d\n", x, *px);
    *px += 23;
    printf("x = %d, *px = %d\n", x, *px);
    
    return 0;
}