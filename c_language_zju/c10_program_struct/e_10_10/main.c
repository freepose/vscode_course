
// Example 10-10: Student information management system.
// The system includes functions such as establishing and outputting basic student information, calculating average scores, sorting students by average scores, and querying and modifying student scores.

#include <stdio.h>

#include <string.h>

struct student
{
    int num;
    char name[10];
    int computer, english, math;
    double average;
};
int Count = 0;

#define MaxSize 50
#include "input_output.c"
#include "computing.c"
#include "update.c"
#include "search.c"

int main(void)
{
    struct student students[MaxSize];

    new_student(students);
    average(students);
    sort(students);
    output_student(students);
    modify(students);
    output_student(students);

    return 0;
}
