
// Example 5-7: This program calculates the sum and product of two complex numbers.
// It takes the real and imaginary parts of two complex numbers as input and uses functions to compute their sum and product.
// The two complex numbers are represented as c1 = x1 + (y1)i and c2 = x2 + (y2)i, where:
// c1 + c2 = (x1+x2) + (y1+y2)i
// c1 * c2 = (x1*x2 - y1*y2) + (x1*y2 + x2*y1)i

#include <stdio.h>

void complex_prod(double real1, double imag1, double real2, double imag2);

void complex_add(double real1, double imag1, double real2, double imag2);

double result_real, result_imag;

int main(void)
{
    double imag1, imag2, real1, real2;

    printf("Enter 1st complex number(real and imaginary): ");
    scanf("%lf%lf", &real1, &imag1);
    printf("Enter 2nd complex number(real and imaginary): ");
    scanf("%lf%lf", &real2, &imag2);
    complex_add(real1, imag1, real2, imag2);
    printf("addition of complex is %f+%fi\n", result_real, result_imag);
    complex_prod(real1, imag1, real2, imag2);
    printf("product of complex is %f+%fi\n", result_real, result_imag);

    return 0;
}

void complex_add(double real1, double imag1, double real2, double imag2)
{
    result_real = real1 + real2;
    result_imag = imag1 + imag2;

    return;
}

void complex_prod(double real1, double imag1, double real2, double imag2)
{
    result_real = real1 * real2 - imag1 * imag2;
    result_imag = real1 * imag2 + real2 * imag1;

    return;
}

// Enter 1st complex number(real and imaginary): 1 1
// Enter 2nd complex number(real and imaginary): -2 3
// addition of complex is -1.000000+4.000000i
// product of complex is -5.000000+1.000000i