
// Example 8-2: Struct array

#include <stdio.h>
#include <string.h>

typedef struct _student
{
    char name[50];   // name
    char number[20]; // number
    short age;       // age
    char phone[20];  // telephone number
    float average;
} Student;

void initial_students(Student *p, int *n)
{
    // Read from file / console
    Student temp = {"test123", "testtest12", 25, "testtest12", 88};
    p[3] = temp;
    (*n)++;
}

void print_a_student(Student *p)
{
    printf("%s, %s, %d, %s, %.2f\n", p->name, p->number, p->age, p->phone, p->average);
}

void print_students(Student *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        print_a_student(p + i);
    }
}

void sort_by_average_ascend(Student *p, int n)
{
    // bubble sort

}

int find_student_by_name(Student *p, int n, char *name)
{
    return -1; 
}

int main()
{
    int n = 3;
    Student ss[100] = {
        {"张三", "1008610086", 30, "001001001001", 108},
        {"李四", "1008510085", 31, "002002002002", 95},
        {"test", "testtest", 31, "testtest", 99}
    };

    initial_students(ss, &n);
    sort_by_average_ascend(ss, n);
    print_students(ss, n);

    return 0;
}
