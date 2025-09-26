
// Example 9-1: struct definition, initialization and access

#include <stdio.h>

struct _student
{
    char number[20];             // number
    char name[20];               // name
    char clbum[20];              // class and grade
    int age;                     // age
    int math, english, computer; // scores
    float average;               // score
};

typedef struct _student Student;

void print_a_student(Student *p)
{
    /// @brief Print a student information using struct pointer
    /// @param stu student pointer

    printf("number: %s\t", p->number);
    printf("name: %s\t", p->name);
    printf("class: %s\t", p->clbum);
    printf("age: %d\t", p->age);
    printf("math: %d\t", p->math);
    printf("english: %d\t", p->english);
    printf("computer: %d\t", p->computer);
    printf("average: %.2f\n", p->average);
}

void update_average_score(Student *p)
{
    /// @brief Update the average score of a student
    /// @param stu student pointer

    p->average = (p->math + p->english + p->computer) / 3.0;
}

void sort_students_by_average(Student *p, int n)
{
    /// @brief Sort students by average score in descending order using bubble sort.
    /// @param stu student pointer
    /// @param n number of students

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].average < p[j + 1].average)
            {
                Student temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main()
{
    Student students[] = {{"2020211001", "Wang Zhenjun", "CS 2411", 20, 90, 85, 75, 90.0},
                          {"2020211002", "Li Ming", "CS 2412", 21, 80, 75, 65, 80.0},
                          {"2020211003", "Zhang San", "CS 2413", 22, 70, 90, 75, 70.0}};

    int n = sizeof(students) / sizeof(students[0]); // number of students

    Student *p = 0;


    for (int i = 0; i < n; i++)
    {
        update_average_score(&students[i]); 
        print_a_student(&students[i]); 
    }

    printf("\nStudents sorted by average score:\n");
    sort_students_by_average(students, n); // sort students by average score

    for (int i = 0; i < n; i++)
    {
        print_a_student(&students[i]); // print sorted students
    }

    // update studdent information
    p = &students[1]; 

    p->math = 95; // update math score

    for (int i = 0; i < n; i++)
    {
        print_a_student(&students[i]); // print sorted students
    }

    return 0;
}