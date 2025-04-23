/*****
 *
 *  Student information system
 *
 */

#include <stdio.h>
#include <string.h>

struct student
{
    char number[20];   // 学号
    char name[20];     // 姓名：一个汉字占两个字节
    char class[20];    // 班级
    char gender[4];    // 性别
    char phone[20];    // 手机号
    char address[100]; // 家庭地址
    char interest[20]; // 兴趣
};

typedef struct student Student;

void read_students(char *csv_filename, Student *pss, int *p_num_students)
{
    // :param csv_filename: the csv file name
    // :param pss: the pointer of the student array
    // :param p_num_students: the pointer of the number of students, _num_students varies as the csv file
    FILE *fp = fopen(csv_filename, "r");
    if (fp == NULL)
    {
        printf("Error: cannot open file %s\n", csv_filename);
        return;
    }

    char line[1024];
    // skip the first line
    fgets(line, 1024, fp);

    int i = 0;
    while (fgets(line, 1024, fp))
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",
               pss[i].number, pss[i].name, pss[i].class, pss[i].gender, pss[i].phone, pss[i].address, pss[i].interest);
        i++;
    }
    *p_num_students = i; // update the number of students
}

void print_a_student(Student *ps)
{
    // print a student information, use tab to separate the fields, and use a new line to separate the students
    printf("%s\t", ps->number);
    printf("%s\t", ps->name);
    printf("%s\t", ps->class);
    printf("%s\t", ps->gender);
    printf("%s\t", ps->phone);
    printf("%s\t", ps->address);
    printf("%s\n", ps->interest);
}

void print_students(Student *pss, int n)
{
    // print all students information
    for (int i = 0; i < n; i++)
    {
        print_a_student(pss + i);
    }
}

void sort_students(Student *pss, int n)
{
    // sort the students by a struct member variable, the sort algorithm is bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(pss[j].address, pss[j + 1].address) > 0)
            {
                Student temp = pss[j];
                pss[j] = pss[j + 1];
                pss[j + 1] = temp;
            }
        }
    }
}

void search_stduent_address(Student *pss, int n, char *target)
{
    // Print student address contains target strings
    for (int i = 0; i < n; i++)
    {
        if (strstr(pss[i].address, target))
        {
            print_a_student(pss + i);
        }
    }
}

int main()
{
    Student ss[100];
    int num_students = 1;
    char csv_filename[] = "data/wd2411-dz2411.csv";

    read_students(csv_filename, ss, &num_students);
    // print_students(ss, num_students);

    sort_students(ss, num_students);
    // printf("\nAfter sorting:\n");
    // print_students(ss, num_students);

    search_stduent_address(ss, num_students, "福州");

    return 0;
}