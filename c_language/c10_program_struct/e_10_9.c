
// Example 10-9: Convert the length conversion macros in Example 10-7 into a header file length.h, and write the main function file.

#include <stdio.h>

#include "length.h"

int main(void)
{
    float foot, inch, mile;

    printf("Input mile,foot and inch:");
    scanf("%f%f%f", &mile, &foot, &inch);
    printf("%f miles = %f meters\n", mile, mile * Mile_to_meter);
    printf("%f feet = %f centimeters\n", foot, foot * Foot_to_centimeter);
    printf("%f inches = %f centimeters\n", inch, inch * Inch_to_centimeter);

    return 0;
}
