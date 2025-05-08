

// Example 9-1: struct definition, initialization and access

#include <stdio.h>
#include <string.h>

typedef struct _student
{
    char number[20];    // student number
    char name[20];      // student name
    char classroom[20]; // student classroom
    float math;         // math score
    float english;      // english score
    float chinese;      // chinese score
    float average;      // average score
} Student;

void print_student(Student *p)
{
    /// @brief print the information of a given student.
    /// @param p : the pointer of a given student.

    printf("Number: %s\t", p->number);
    printf("Name: %s\t", p->name);
    printf("Classroom: %s\t", p->classroom);
    printf("Math: %.2f\t", p->math);
    printf("English: %.2f\t", p->english);
    printf("Chinese: %.2f\t", p->chinese);
    printf("Average: %.2f\n", p->average);
}

void print_students(Student *p, int n)
{
    /// @brief print the information of all students.
    /// @param p : the pointer of a given student.
    /// @param n : the number of students.

    // Header
    printf("Number\tName\tClassroom\tMath\tEnglish\tChinese\tAverage\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        print_student(p + i);
    }
}

void update_students(Student *array, int size)
{
    /// @brief update the average score of all students.
    /// @param array : the pointer of a given student.
    /// @param size : the number of students.

    for (int i = 0; i < size; i++)
    {
        array[i].average = (array[i].math + array[i].english + array[i].chinese) / 3.0;
    }
}

void bubble_sort(Student *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j].average > array[j + 1].average)
            {
                Student temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}


int main()
{
    Student students[70] = {{"202421511001", "Binbin Liu", "GIS 2411", 90.0, 85.0, 100.0},
                            {"202421511002", "Langting Li", "GIS 2411", 90.0, 85.0, 98.0},
                            {"202421511003", "Lisa Ou", "GIS 2411", 90.0, 85.0, 88.0}};

    print_students(students, 3);
    update_students(students, 3);
    bubble_sort(students, 3);
    print_students(students, 3);

    return 0;
}