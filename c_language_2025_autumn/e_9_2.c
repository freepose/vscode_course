

// Example 9-2: 学生成绩排序

/*
学号    	    姓名    	    所属标签    	成绩（虚拟）
202321182020	李书怡	计算2411	64
202421002078	何辉	计算2513	73
202421063061	张启航	计算2512	91
202421093021	王佳裕	计算2511	64
202521331001	郑伟琪	计算2511	79
202521331002	王月阳	计算2511	67
202521331003	邹悦	计算2511	70
202521331004	陈静湘	计算2511	88
202521331005	林辰祎	计算2511	63
202521331006	赵梓希	计算2511	64
202521331007	张丽娟	计算2511	87
202521331008	庄雨佳	计算2511	77
202521331009	陈如筠	计算2511	96
202521331010	池建鸿	计算2511	81
202521331011	朱锐杰	计算2511	69
202521331012	郎子谦	计算2511	78
202521331013	刘诗凯	计算2511	90
202521331014	卜建鸿	计算2511	96
202521331015	刘嘉宏	计算2511	61
202521331016	刘明淞	计算2511	79
202521331017	林晨旭	计算2511	80
202521331018	耿天宇	计算2511	83
202521331019	吴俊豪	计算2511	72
202521331020	李思源	计算2511	82
 */

#include <stdio.h>
#include <string.h>

typedef struct _student{
    char number[20];
    char name[20];
    char cls[20];
    int score;
} Student;

void print_header()
{
    printf("学号\t\t\t");
    printf("姓名\t");
    printf("所属标签\t");
    printf("成绩\n");
    printf("-----------------------------------------------------\n");
}

void print_student_info(Student *p_student)
{
    printf("%s\t", p_student->number);
    printf("%s\t", p_student->name);
    printf("%s\t", p_student->cls);
    printf("%d\n", p_student->score);
}

void print_student_array(Student *students, int size)
{
    print_header();
    for (int i = 0; i < size; i++)
    {
        print_student_info(&students[i]);
    }
}

void sort_students_by_number_asc(Student students[], int size)
{
    // Bubble Sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(students[j].number, students[j + 1].number) > 0)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sort_students_by_score_asc(Student students[], int size)
{
    // Bubble Sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (students[j].score > students[j + 1].score)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main()
{
    Student students[] = {
        {"202321182020", "李书怡", "计算2411", 64},
        {"202421002078", "何辉", "计算2513", 73},
        {"202421063061", "张启航", "计算2512", 91},
        {"202421093021", "王佳裕", "计算2511", 64},
        {"202521331001", "郑伟琪", "计算2511", 79},
        {"202521331002", "王月阳", "计算2511", 67},
        {"202521331003", "邹悦", "计算2511", 70},
        {"202521331004", "陈静湘", "计算2511", 88},
        {"202521331005", "林辰祎", "计算2511", 63},
        {"202521331006", "赵梓希", "计算2511", 64},
        {"202521331007", "张丽娟", "计算2511", 87},
        {"202521331008", "庄雨佳", "计算2511", 77},
        {"202521331009", "陈如筠", "计算2511", 96},
        {"202521331010", "池建鸿", "计算2511", 81},
        {"202521331011", "朱锐杰", "计算2511", 69},
        {"202521331012", "郎子谦", "计算2511", 78},
        {"202521331013", "刘诗凯", "计算2511", 90},
        {"202521331014", "卜建鸿", "计算2511", 96},
        {"202521331015", "刘嘉宏", "计算2511", 61},
        {"202521331016", "刘明淞", "计算2511", 79},
        {"202521331017", "林晨旭", "计算2511", 80},
        {"202521331018", "耿天宇", "计算2511", 83},
        {"202521331019", "吴俊豪", "计算2511", 72},
        {"202521331020", "李思源", "计算2511", 82}
    };

    int n = sizeof(students) / sizeof(students[0]);

    // print_student_array(students, n);
    // sort_students_by_number_asc(students, n);
    // print_student_array(students, n);

    print_student_info(&students[12]);
    students[12].score = 100;
    print_student_info(&students[12]);

    return 0;
}