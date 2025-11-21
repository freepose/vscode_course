

// Example 9-1: Structure definition and usage

#include <stdio.h>
#include <string.h>

typedef struct _score
{
    float math;
    float english;
    float science;
    float history;

    float average;
} Score;

typedef struct _student
{
    char number[20];
    char name[20];
    char gender;
    int age;
    char address[50];
    char phone[15];
    Score scores;   // member variable of structure type Score
} Student;

void print_student_info(Student *p_student, int is_line)
{
    if (is_line)
    {
        printf("%-30s", p_student->number);
        printf("%-15s", p_student->name);
        printf("%-6c", p_student->gender);
        printf("%-4d", p_student->age);
        printf("%-30s", p_student->address);
        printf("%-15s", p_student->phone);
        printf("%-6.2f %-8.2f %-8.2f %-8.2f %-8.2f\n",
               p_student->scores.math,
               p_student->scores.english,
               p_student->scores.science,
               p_student->scores.history,
               p_student->scores.average);
    }
    else
    {
        printf("Student Number: %s\n", p_student->number);
        printf("Name: %s\n", p_student->name);
        printf("Gender: %c\n", p_student->gender);
        printf("Age: %d\n", p_student->age);
        printf("Address: %s\n", p_student->address);
        printf("Phone: %s\n", p_student->phone);
    }
}

int main()
{
    Student stu1 = {
        "2025001",
        "Alice Smith",
        'F',
        20,
        "123 Main St, Anytown",
        "555-1234",
        {90, 95, 100}};

    // memset(&stu1, 0, sizeof(Student));

    print_student_info(&stu1, 1);

    return 0;
}