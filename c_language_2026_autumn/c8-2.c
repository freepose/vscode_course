

#include <stdio.h>

int main()
{
    int a = 1;
    short b = 2;
    double c = 3.;

    int *pa = &a;
    short *pb = &b;
    double *pc = &c;

    printf("lenght of int is %d bytes\n", sizeof(int));
    printf("lenght of short is %d bytes\n", sizeof(short));
    printf("lenght of double is %d bytes\n", sizeof(double));

    printf("lenght of int* is %d bytes\n", sizeof(int *));
    printf("lenght of short* is %d bytes\n", sizeof(short *));
    printf("lenght of double* is %d bytes\n", sizeof(double *));

    return 0;
}