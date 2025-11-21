
// Example 9-1: Structure definition and usage

#include <stdio.h>
#include <string.h>

typedef struct _student
{
    char number[20];
    char name[20];
    char gender;
    int age;
    char address[50];
    char phone[15];
} Student;

void print_student_info(Student *p_student, int is_line)
{
    if (is_line)
    {
        printf("%-15s %-15s %-6c %-4d %-30s %-15s\n",
               p_student->number,
               p_student->name,
               p_student->gender,
               p_student->age,
               p_student->address,
               p_student->phone);
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
        "555-1234"};

    // memset(&stu1, 0, sizeof(Student));

    print_student_info(&stu1, 1);

    return 0;
}