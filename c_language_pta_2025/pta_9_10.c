

// Calculate cosine using Taylor series expansion

#include <stdio.h>
#include <math.h>

double funcos(double e, double x);

int main()
{
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

double funcos(double e, double x)
{
    double term = 1.0; // First term of the series
    double sum = term; // Initialize sum with the first term
    int n = 0;         // Term index

    while (fabs(term) >= e)
    {
        n++;
        term *= -x * x / (2 * n * (2 * n - 1)); // Calculate the next term
        sum += term;                            // Add the next term to the sum
    }

    return sum;
}