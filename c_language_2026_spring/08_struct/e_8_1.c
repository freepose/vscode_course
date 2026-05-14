
// Example 8-1


#include <stdio.h>
#include <string.h>

typedef struct _student
{
     char name[50];     // name
     char number[20];   // number
     short age;         // age
     char phone[20];    // telephone number
} Student;

void print_a_student(Student  *p)
{
     printf("%s, %s, %d, %s\n", p->name, p->number, p->age, p->phone);
}


int main()
{
     Student s1 = {"张三", "1008610086", 30, "001001001001"};
     Student s2 = {"李四", "1008510085", 31, "002002002002"};

     //s1 = s2;

     strcpy(s1.name, s2.name);
     strcpy(s1.number, s2.number);
     s1.age = s2.age;
     strcpy(s1.phone, s2.phone);

     print_a_student(&s1);
     print_a_student(&s2);

	return 0;
}
