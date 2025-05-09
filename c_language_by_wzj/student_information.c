/*****
 *
 *  Student information system for GIS2411 and GIS2412
 *
 *  Author: Zhijin Wang
 *  Date: 2023-10-01
 *  Description: This program manages student information, including input, output, and sorting by average score.
 *
 */

#include <stdio.h>
#include <string.h>

// 班级,学号,姓名,性别,出生年月,电话号码,家庭地址,爱好,擅长
struct _student
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
};

typedef struct _student Student;

void get_student_info(char *filename, Student *p, int *n)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    char line[1024] = {0};
    fgets(line, 1024, fp); // Skip the first line (header)

    int i = 0;
    while (fgets(line, 1024, fp))
    {
        // Remove trailing newline character
        line[strcspn(line, "\r\n")] = 0;

        // Initialize all fields to empty strings
        memset(&p[i], 0, sizeof(Student));

        // Parse the line, allowing missing fields
        int fields = sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                            p[i].clbum, p[i].number, p[i].name, p[i].gender, p[i].birth,
                            p[i].phone, p[i].address, p[i].hobby, p[i].skill);

        // Fill missing fields with default values
        if (fields < 9)
        {
            for (int j = fields; j < 9; j++)
            {
                switch (j)
                {
                case 7: strcpy(p[i].hobby, "N/A"); break;
                case 8: strcpy(p[i].skill, "N/A"); break;
                }
            }
        }

        i++;
    }
    *n = i; // Update the number of students

    fclose(fp);
}

void print_table_header()
{
    /// @brief Print table header
    printf("Class\tNumber\tName\tGender\tBirth\tPhone\tAddress\tHobby\tSkill\n");
    printf("---------------------------------------------------------------\n");
}

void print_student_info(Student *p, int n)
{
    /// @brief Print student information
    /// @param stu student pointer
    /// @param n number of students

    for (int i = 0; i < n; i++)
    {
        printf("%s\t", p[i].clbum);
        printf("%s\t", p[i].number);
        printf("%s\t", p[i].name);
        printf("%s\t", p[i].gender);
        printf("%s\t", p[i].birth);
        printf("%s\t", p[i].phone);
        printf("%s\t", p[i].address);
        printf("%s\t", p[i].hobby);
        printf("%s\n", p[i].skill);
    }
}

int find_student_by_number(Student *p, int n, char *target_number)
{
    /// @brief Find student by number using linear search
    /// @param stu student pointer
    /// @param n number of students
    /// @param target_number target student number

    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].number, target_number) == 0)
        {
            return i; 
        }
    }
    return -1; // Not found
}

void sort_by_phone(Student *p, int n)
{
    /// @brief Sort students by phone number using selection sort
    /// @param stu student pointer
    /// @param n number of students

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(p[j].phone, p[min_index].phone) < 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            Student temp = p[i];
            p[i] = p[min_index];
            p[min_index] = temp;
        }
    }
}

int main()
{
    Student students[100];
    int n = 0;
    char filename[100] = "D://study//gis2411-2412.csv";

    char* target_number = "202421511007"; 

    memset(students, 0, sizeof(students)); // Initialize the student array
    get_student_info(filename, students, &n);

    print_table_header();
    print_student_info(students, n);

    int index = find_student_by_number(students, n, target_number);
    if (index != -1)
    {
        printf("Target number: %s, Student found: %s\n", target_number, students[index].name);
    }
    else
    {
        printf("Student with number %s not found.\n", target_number);
    }

    sort_by_phone(students, n);
    print_table_header();
    print_student_info(students, n);

    return 0;
}