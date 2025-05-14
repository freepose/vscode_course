

// Example 9-3: Structure pointers, dyanamic memory allocation (malloc), and structure initialization (memset)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _student
{
    char clbum[20];   // 班级
    char number[20];  // 学号
    char name[20];    // 姓名
    char gender[3];   //
    char birth[20];   // 出生年月
    char phone[20];   // 电话号码
    char address[50]; // 家庭地址
    char hobby[50];   // 爱好
    char skill[50];   // 擅长
}Student;

void print_a_student(Student* p_student)
{
	/// @brief print the information of a given student.
	/// @param p : the pointer of a given student.

    printf("班级: %s\t", p_student->clbum);
    printf("学号: %s\t", p_student->number);
    printf("姓名: %s\t", p_student->name);
    printf("性别: %s\t", p_student->gender);
    printf("出生年月: %s\t", p_student->birth);
    printf("电话号码: %s\t", p_student->phone);
    printf("家庭地址: %s\t", p_student->address);
    printf("爱好: %s\t", p_student->hobby);
    printf("擅长: %s\n", p_student->skill);
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