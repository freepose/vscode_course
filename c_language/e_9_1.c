
/***********************************
 *
 * Chapter 9-2: Structs
 *
 ***********************************/

// This is a simple program that demonstrates the initialization of a struct variable in C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vairable definition and function declaration

struct student
{
    char name[20];     // name: a string representing the student's name
    char number[20];   // number: a string representing the student's number
    char address[100]; // address: a string representing the student's address
    int english;       // english: an integer representing the student's English score
    int math;          // math: an integer representing the student's Math score
    int computer;      // computer: an integer representing the student's Computer score
    float average;     // average: a float representing the student's average score
};

int main()
{
    struct student s1; // s1: a variable of type struct student
    struct student s2;

    // memory set to initialize the student information
    memset(&s1, 0, sizeof(struct student));

    printf("Name: %s\tNumber: %s\tAddress: %s\tEnglish: %d\tMath: %d\tComputer: %d\tAverage: %.2f\n",
           s1.name, s1.number, s1.address, s1.english, s1.math, s1.computer, s1.average);

    // Initialize the student information
    strcpy(s1.name, "John");
    strcpy(s1.number, "123456");
    strcpy(s1.address, "1234 Main St, Apt 1, New York, NY 10001");
    s1.english = 90;
    s1.math = 85;
    s1.computer = 88;
    s1.average = (s1.english + s1.math + s1.computer) / 3.0;

    // Print the student information
    printf("Name: %s\tNumber: %s\tAddress: %s\tEnglish: %d\tMath: %d\tComputer: %d\tAverage: %.2f\n",
           s1.name, s1.number, s1.address, s1.english, s1.math, s1.computer, s1.average);

    // The third initialization method: initialization while declaring the variable
    struct student s3 = {"Alice", "654321", "5678 Elm St, Apt 2, Los Angeles, CA 90001", 95, 92, 98, 95.0};

    // One more thing, initialize the student array
    struct student students[3] = {
        {"Alice", "654321", "5678 Elm St, Apt 2, Los Angeles, CA 90001", 95, 92, 98, 95.0},
        {"Bob", "987654", "8765 Oak St, Apt 3, San Francisco, CA 80001", 88, 90, 85, 87.7},
        {"Cathy", "456789", "3456 Pine St, Apt 4, San Diego, CA 70001", 92, 94, 90, 92.0}};

    return 0;
}
