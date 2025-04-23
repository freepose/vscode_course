
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

typedef struct {
    char name[20];
    int score;
} homework;


typedef struct {
	char name[20];		// student name
	char number[20];	// student number
	char gender[2];		// gender in {male, female}
	char address[100];	// address
	homework work[20];	// homeworks 
    int num_work;		// number of homeworks
} student;

void initialize_student(student* p_student)
{
	/// @brief intialize a given student. Set all information to empty.
	/// @param p_student : the pointer of a given student.
	strcpy(p_student->name, "");
	strcpy(p_student->number, "");
	strcpy(p_student->gender, "");
	strcpy(p_student->address, "");
}

void print_student(student* p_student)
{
	/// @brief print the information of a given student.
	/// @param p : the pointer of a given student.

	printf("Name: %s\n", p_student->name);
	printf("Number: %s\n", p_student->name);
	printf("Gender: %s\n", p_student->gender);
	printf("Address: %s\n", p_student->address);
}

int main()
{
	student a[63];
	memset(a, 0, 63 * sizeof(student));

	initialize_student(&a[0]);
	print_student(&a[0]);

	// initialize a student information by hand
	strcpy(a[0].name, "John");
	strcpy(a[0].number, "123456");
	strcpy(a[0].gender, "M");
	strcpy(a[0].address, "1234 Main St, Apt 1, New York, NY 10001");

	return 0;
}