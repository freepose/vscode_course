
// 结构体：如何描述一个学生
#include <stdio.h>
#include <memory.h>

struct student
{
    char number[10];            // 学号
    char name[10];              // 姓名
    int chinese, math, english; // 成绩
    float average;
};

typedef struct student Student;

void print_a_student(Student *ps)
{
    // 结构体指针变量，取内容用 ->，当然也可以*ps之后再选择
    // 打印结构体中的学生信息，每个字段之间用'\t'分隔，最后用'\n'结束
    printf("%s\t", ps->number);
    printf("%s\t", ps->name);
    printf("%d\t", ps->chinese);
    printf("%d\t", ps->math);
    printf("%d\t", ps->english);
    printf("%.2f\n", ps->average);
}

int main()
{
    Student s1 = {"0001", "Wang", 20, 20, 20, 0};

    // memset(&s1, 0, sizeof(s1)); // 直接通过内存的初始化

    // update the student's average score
    s1.average = (s1.chinese + s1.math + s1.english) / 3.0;

    // print a student's information
    print_a_student(&s1);

    return 0;
}