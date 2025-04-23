
// Example 10-1: switch between three functions.

#include <stdio.h>

double cyliner_volume(double r, double h)
{
    // ¦Ð * r^2 * h
    return 3.14159 * r * r * h;
}

double cone_volume(double r, double h)
{
    // 1/3 * ¦Ð * r^2 * h
    return 3.14159 * r * r * h / 3;
}

double sphere_volume(double r)
{
    // 4/3 * ¦Ð * r^3
    return 3.14159 * r * r * r * 4 / 3;
}

int main()
{
    double r = 3.0, h = 4.0;
    int choice;

    scanf("%d", &choice);

    // This is an example of a switch statement.
    switch (choice)
    {
    case 1:
        printf("The volume of the cylinder is %f\n", cyliner_volume(r, h));
        break;
    case 2:
        printf("The volume of the cone is %f\n", cone_volume(r, h));
        break;
    case 3:
        printf("The volume of the sphere is %f\n", sphere_volume(r));
        break;
    default:
        printf("Invalid choice\n");
    }

    // Summarize this example:
    // 1. The switch statement is used to select one of the three functions.
    // 2. The switch statement is followed by a list of cases.
    // 3. The case keyword is followed by a constant expression.
    // 4. The break statement is used to exit the switch statement.
    // 5. The default case is executed if no other case matches.
    

    return 0;
}