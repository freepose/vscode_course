
// Example 9-1: Output the information of the student with the highest average score. Assume that the basic information of the student includes student number, name, three course scores, and personal average score.
// Input n students' score information, calculate and output the information of the student with the highest average score.

#include <stdio.h>

struct student
{
    int num;
    char name[10];
    int computer, english, math;
    double average;
};

int main(void)
{
    int i, n;
    struct student max, stu;

    printf("Input n: ");
    scanf("%d", &n);
    printf("Input the student's number, name and course scores\n");
    for (i = 1; i <= n; i++)
    {
        printf("No.%d: ", i);
        scanf("%d%s%d%d%d", &stu.num, stu.name, &stu.math, &stu.english, &stu.computer);
        stu.average = (stu.math + stu.english + stu.computer) / 3.0;
        if (i == 1)
        {
            max = stu;
        }
        else if (max.average < stu.average)
        {
            max = stu;
        }
    }
    printf("num:%d, name:%s, average:%.2lf\n", max.num, max.name, max.average);

    return 0;
}

// Input n: 3
// Input the student's number, name and course scores
// No.1: 101 Zhang 78 87 85
// No.2: 102 Wang 91 88 90
// No.3: 103 Li 75 90 84
// num:102, name:Wang, average:89.67