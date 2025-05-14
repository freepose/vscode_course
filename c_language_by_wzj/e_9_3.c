

// Example 9-3: Structure pointers, dyanamic memory allocation (malloc), and structure initialization (memset)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _student
{
    char clbum[20];   // �༶
    char number[20];  // ѧ��
    char name[20];    // ����
    char gender[3];   //
    char birth[20];   // ��������
    char phone[20];   // �绰����
    char address[50]; // ��ͥ��ַ
    char hobby[50];   // ����
    char skill[50];   // �ó�
}Student;

void print_a_student(Student* p_student)
{
	/// @brief print the information of a given student.
	/// @param p : the pointer of a given student.

    printf("�༶: %s\t", p_student->clbum);
    printf("ѧ��: %s\t", p_student->number);
    printf("����: %s\t", p_student->name);
    printf("�Ա�: %s\t", p_student->gender);
    printf("��������: %s\t", p_student->birth);
    printf("�绰����: %s\t", p_student->phone);
    printf("��ͥ��ַ: %s\t", p_student->address);
    printf("����: %s\t", p_student->hobby);
    printf("�ó�: %s\n", p_student->skill);
}


int main()
{
    int num = 10; // Number of students
    Student *p = 0;

    scanf("%d", &num); 
    p = malloc(sizeof(Student) * num);

    memset(p, 0, sizeof(Student) * num); // Initialize the structure to zero

    print_a_student(&p[0]);

    return 0;
}