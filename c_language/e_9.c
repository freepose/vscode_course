
// �ṹ�壺�������һ��ѧ��
#include <stdio.h>
#include <memory.h>

struct student
{
    char number[10];            // ѧ��
    char name[10];              // ����
    int chinese, math, english; // �ɼ�
    float average;
};

typedef struct student Student;

void print_a_student(Student *ps)
{
    // �ṹ��ָ�������ȡ������ ->����ȻҲ����*ps֮����ѡ��
    // ��ӡ�ṹ���е�ѧ����Ϣ��ÿ���ֶ�֮����'\t'�ָ��������'\n'����
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

    // memset(&s1, 0, sizeof(s1)); // ֱ��ͨ���ڴ�ĳ�ʼ��

    // update the student's average score
    s1.average = (s1.chinese + s1.math + s1.english) / 3.0;

    // print a student's information
    print_a_student(&s1);

    return 0;
}