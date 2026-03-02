
// Example 10-7: In European and American countries, length is measured in imperial units such as miles, feet, and inches.
// The conversion rates are as follows: 1 mile = 1609 meters, 1 foot = 30.48 centimeters, and 1 inch = 2.54 centimeters. Please write a program to convert the input miles to meters and feet and inches to centimeters.

#include <stdio.h>

#define Mile_to_meter 1609

#define Foot_to_centimeter 30.48

#define Inch_to_centimeter 2.54

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

// Input mile,foot and inch:1.2 3 5.1
// 1.200000 miles = 1930.800049 meters
// 3.000000 feet = 91.440000 centimeters
// 5.100000 inches = 12.954000 centimeters