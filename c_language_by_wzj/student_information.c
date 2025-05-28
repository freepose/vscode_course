/*****
 *
 *  Student Information Management System for GIS2411 and GIS2412
 *
 *  Author: Zhijin Wang
 *  Date: 2023-10-01
 *  Version: 2.0
 *  Description: Advanced student information management system with enhanced features
 *               including input, output, search, sort, and data validation.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Add Windows compatibility for strcasecmp
#ifdef _WIN32
#define strcasecmp _stricmp
#endif
#include <ctype.h>

// Add Windows compatibility for strcasecmp
#ifdef _WIN32
#define strcasecmp _stricmp
#endif

// Constants definition
#define MAX_STUDENTS 100
#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 50
#define MIN_FIELD_LENGTH 20

// Student data structure
typedef struct {
    char class_name[MIN_FIELD_LENGTH];    // class name
    char student_id[MIN_FIELD_LENGTH];    // student ID
    char name[MIN_FIELD_LENGTH];          // student name
    char gender[5];                       // gender
    char birth_date[MIN_FIELD_LENGTH];    // birth date
    char phone[MIN_FIELD_LENGTH];         // phone number
    char address[MAX_FIELD_LENGTH];       // home address
    char hobby[MAX_FIELD_LENGTH];         // hobbies
    char skill[MAX_FIELD_LENGTH];         // skills
} Student;

// Function to safely read student information from CSV file
int load_student_data(const char *filename, Student *students, int max_students)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open file '%s'\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    
    // Skip header line
    if (fgets(line, sizeof(line), fp) == NULL)
    {
        printf("Error: File '%s' is empty or corrupted\n", filename);
        fclose(fp);
        return -1;
    }

    int count = 0;
    while (fgets(line, sizeof(line), fp) && count < max_students)
    {
        // Remove trailing newline characters
        line[strcspn(line, "\r\n")] = '\0';
        
        // Skip empty lines
        if (strlen(line) == 0) continue;

        // Initialize current student structure
        memset(&students[count], 0, sizeof(Student));

        // Parse CSV line with proper field handling
        int fields = sscanf(line, 
            "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
            students[count].class_name, students[count].student_id, 
            students[count].name, students[count].gender, 
            students[count].birth_date, students[count].phone,
            students[count].address, students[count].hobby, 
            students[count].skill);

        // Set default values for missing fields
        if (fields < 9)
        {
            if (fields < 7) strcpy(students[count].address, "N/A");
            if (fields < 8) strcpy(students[count].hobby, "N/A");
            if (fields < 9) strcpy(students[count].skill, "N/A");
        }

        count++;
    }

    fclose(fp);
    printf("Successfully loaded %d student records from '%s'\n", count, filename);
    return count;
}

// Function to print formatted table header
void print_table_header()
{
    printf("\n");
    printf("%-12s %-15s %-10s %-8s %-12s %-15s %-20s %-15s %-15s\n",
           "Class", "Student_ID", "Name", "Gender", "Birth", "Phone", "Address", "Hobby", "Skill");
    printf("%-12s %-15s %-10s %-8s %-12s %-15s %-20s %-15s %-15s\n",
           "------------", "---------------", "----------", "--------", "------------", 
           "---------------", "--------------------", "---------------", "---------------");
}

// Function to print student information in formatted table
void print_student_info(const Student *students, int count)
{
    if (count <= 0)
    {
        printf("No student records to display.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%-12s %-15s %-10s %-8s %-12s %-15s %-20s %-15s %-15s\n",
               students[i].class_name, students[i].student_id, students[i].name,
               students[i].gender, students[i].birth_date, students[i].phone,
               students[i].address, students[i].hobby, students[i].skill);
    }
    printf("\nTotal students: %d\n", count);
}

// Function to find student by student ID using linear search
int find_student_by_id(const Student *students, int count, const char *target_id)
{
    if (students == NULL || target_id == NULL || count <= 0)
    {
        return -1;
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].student_id, target_id) == 0)
        {
            return i;
        }
    }
    return -1; // Student not found
}

// Function to find student by name
int find_student_by_name(const Student *students, int count, const char *target_name)
{
    if (students == NULL || target_name == NULL || count <= 0)
    {
        return -1;
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].name, target_name) == 0)
        {
            return i;
        }
    }
    return -1; // Student not found
}

// Function to swap two students (helper for sorting)
void swap_students(Student *a, Student *b)
{
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort students by phone number using selection sort
void sort_by_phone(Student *students, int count)
{
    if (students == NULL || count <= 1)
    {
        return;
    }

    for (int i = 0; i < count - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(students[j].phone, students[min_index].phone) < 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap_students(&students[i], &students[min_index]);
        }
    }
    printf("Students sorted by phone number.\n");
}

// Function to sort students by student ID
void sort_by_student_id(Student *students, int count)
{
    if (students == NULL || count <= 1)
    {
        return;
    }

    for (int i = 0; i < count - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(students[j].student_id, students[min_index].student_id) < 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap_students(&students[i], &students[min_index]);
        }
    }
    printf("Students sorted by student ID.\n");
}

// Function to sort students by name
void sort_by_name(Student *students, int count)
{
    if (students == NULL || count <= 1)
    {
        return;
    }

    for (int i = 0; i < count - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(students[j].name, students[min_index].name) < 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap_students(&students[i], &students[min_index]);
        }
    }
    printf("Students sorted by name.\n");
}

// Function to check if a string represents male gender
int is_male_gender(const char *gender)
{
    if (gender == NULL || strlen(gender) == 0) return 0;
    
    // Create a copy for processing
    char temp[50];
    strcpy(temp, gender);
    
    // Convert to lowercase for case-insensitive comparison
    for (int i = 0; temp[i]; i++) {
        temp[i] = tolower(temp[i]);
    }
    
    // Check for various male representations
    if (strstr(gender, "男") != NULL ||
        strstr(temp, "male") != NULL ||
        strcmp(temp, "m") == 0 ||
        strstr(temp, "man") != NULL)
    {
        return 1;
    }
    return 0;
}

// Function to check if a string represents female gender
int is_female_gender(const char *gender)
{
    if (gender == NULL || strlen(gender) == 0) return 0;
    
    // Create a copy for processing
    char temp[50];
    strcpy(temp, gender);
    
    // Convert to lowercase for case-insensitive comparison
    for (int i = 0; temp[i]; i++) {
        temp[i] = tolower(temp[i]);
    }
    
    // Check for various female representations
    if (strstr(gender, "女") != NULL ||
        strstr(temp, "female") != NULL ||
        strcmp(temp, "f") == 0 ||
        strstr(temp, "woman") != NULL)
    {
        return 1;
    }
    return 0;
}

// Function to display menu options
void display_menu()
{
    printf("\n=== Student Information Management System ===\n");
    printf("1. Display all students\n");
    printf("2. Find student by ID\n");
    printf("3. Find student by name\n");
    printf("4. Sort by student ID\n");
    printf("5. Sort by name\n");
    printf("6. Sort by phone number\n");
    printf("7. Display statistics\n");
    printf("8. Save student data to file\n");
    printf("9. Search students by class\n");
    printf("10. Search students by phone prefix\n");
    printf("11. Validate student data\n");
    printf("12. Debug gender data\n");
    printf("13. Exit\n");
    printf("Please enter your choice (1-13): ");
}

// Function to display statistics
void display_statistics(const Student *students, int count)
{
    if (count <= 0)
    {
        printf("No students to analyze.\n");
        return;
    }

    int gis2411_count = 0, gis2412_count = 0;
    int male_count = 0, female_count = 0;    for (int i = 0; i < count; i++)
    {
        // Count by class
        if (strstr(students[i].class_name, "2411") != NULL)
        {
            gis2411_count++;
        }
        else if (strstr(students[i].class_name, "2412") != NULL)
        {
            gis2412_count++;
        }
        
        // Count by gender using helper functions
        char trimmed_gender[50];
        strcpy(trimmed_gender, students[i].gender);
        
        // Remove leading/trailing whitespace
        char *start = trimmed_gender;
        while (isspace(*start)) start++;
        char *end = start + strlen(start) - 1;
        while (end > start && isspace(*end)) end--;
        *(end + 1) = '\0';
        
        if (is_male_gender(start))
        {
            male_count++;
        }
        else if (is_female_gender(start))
        {
            female_count++;
        }
    }printf("\n=== Student Statistics ===\n");
    printf("Total students: %d\n", count);
    printf("GIS2411 students: %d\n", gis2411_count);
    printf("GIS2412 students: %d\n", gis2412_count);
    printf("Other classes: %d\n", count - gis2411_count - gis2412_count);
    printf("Male students: %d\n", male_count);
    printf("Female students: %d\n", female_count);
    printf("Gender unspecified: %d\n", count - male_count - female_count);
    
    // Show percentages
    if (count > 0)
    {
        printf("\n=== Percentages ===\n");
        printf("Male: %.1f%%\n", (float)male_count / count * 100);
        printf("Female: %.1f%%\n", (float)female_count / count * 100);
        printf("GIS2411: %.1f%%\n", (float)gis2411_count / count * 100);
        printf("GIS2412: %.1f%%\n", (float)gis2412_count / count * 100);
    }
    printf("========================\n");
}

// Function to print single student details
void print_student_details(const Student *student, int index)
{
    printf("\n=== Student Details ===\n");
    printf("Index: %d\n", index + 1);
    printf("Class: %s\n", student->class_name);
    printf("Student ID: %s\n", student->student_id);
    printf("Name: %s\n", student->name);
    printf("Gender: %s\n", student->gender);
    printf("Birth Date: %s\n", student->birth_date);
    printf("Phone: %s\n", student->phone);
    printf("Address: %s\n", student->address);
    printf("Hobby: %s\n", student->hobby);
    printf("Skill: %s\n", student->skill);
    printf("======================\n");
}

// Function to save student data to a new CSV file
int save_student_data(const char *filename, const Student *students, int count)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error: Unable to create file '%s' for writing\n", filename);
        return -1;
    }

    // Write header
    fprintf(fp, "班级,学号,姓名,性别,出生年月,电话号码,家庭地址,爱好,擅长\n");

    // Write student data
    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                students[i].class_name, students[i].student_id, students[i].name,
                students[i].gender, students[i].birth_date, students[i].phone,
                students[i].address, students[i].hobby, students[i].skill);
    }

    fclose(fp);
    printf("Successfully saved %d student records to '%s'\n", count, filename);
    return 0;
}

// Function to search students by class
void search_by_class(const Student *students, int count, const char *class_name)
{
    int found_count = 0;
    printf("\n=== Students in class '%s' ===\n", class_name);
    
    for (int i = 0; i < count; i++)
    {
        if (strstr(students[i].class_name, class_name) != NULL)
        {
            if (found_count == 0)
            {
                print_table_header();
            }
            printf("%-12s %-15s %-10s %-8s %-12s %-15s %-20s %-15s %-15s\n",
                   students[i].class_name, students[i].student_id, students[i].name,
                   students[i].gender, students[i].birth_date, students[i].phone,
                   students[i].address, students[i].hobby, students[i].skill);
            found_count++;
        }
    }
    
    if (found_count == 0)
    {
        printf("No students found in class '%s'\n", class_name);
    }
    else
    {
        printf("\nFound %d students in class '%s'\n", found_count, class_name);
    }
}

// Function to search students by phone prefix
void search_by_phone_prefix(const Student *students, int count, const char *prefix)
{
    int found_count = 0;
    printf("\n=== Students with phone starting with '%s' ===\n", prefix);
    
    for (int i = 0; i < count; i++)
    {
        if (strncmp(students[i].phone, prefix, strlen(prefix)) == 0)
        {
            if (found_count == 0)
            {
                print_table_header();
            }
            printf("%-12s %-15s %-10s %-8s %-12s %-15s %-20s %-15s %-15s\n",
                   students[i].class_name, students[i].student_id, students[i].name,
                   students[i].gender, students[i].birth_date, students[i].phone,
                   students[i].address, students[i].hobby, students[i].skill);
            found_count++;
        }
    }
    
    if (found_count == 0)
    {
        printf("No students found with phone prefix '%s'\n", prefix);
    }
    else
    {
        printf("\nFound %d students with phone prefix '%s'\n", found_count, prefix);
    }
}

// Function to validate student ID format
int validate_student_id(const char *student_id)
{
    if (strlen(student_id) != 12)
    {
        return 0; // Invalid length
    }
    
    for (int i = 0; i < 12; i++)
    {
        if (student_id[i] < '0' || student_id[i] > '9')
        {
            return 0; // Contains non-digit characters
        }
    }
    
    return 1; // Valid format
}

// Function to validate phone number format
int validate_phone_number(const char *phone)
{
    int len = strlen(phone);
    if (len < 7 || len > 15)
    {
        return 0; // Invalid length
    }
    
    for (int i = 0; i < len; i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
        {
            return 0; // Contains non-digit characters
        }
    }
    
    return 1; // Valid format
}

// Function to perform data validation
void validate_student_data(const Student *students, int count)
{
    int invalid_count = 0;
    printf("\n=== Data Validation Report ===\n");
    
    for (int i = 0; i < count; i++)
    {
        int has_error = 0;
        
        printf("Student %d (%s):\n", i + 1, students[i].name);
        
        if (!validate_student_id(students[i].student_id))
        {
            printf("  - Invalid student ID format: %s\n", students[i].student_id);
            has_error = 1;
        }
        
        if (!validate_phone_number(students[i].phone))
        {
            printf("  - Invalid phone number format: %s\n", students[i].phone);
            has_error = 1;
        }
        
        if (strlen(students[i].name) == 0)
        {
            printf("  - Missing name\n");
            has_error = 1;
        }
        
        if (strlen(students[i].class_name) == 0)
        {
            printf("  - Missing class name\n");
            has_error = 1;
        }
        
        if (has_error)
        {
            invalid_count++;
        }
        else
        {
            printf("  - All fields valid\n");
        }
    }
    
    printf("\nValidation Summary:\n");
    printf("Total students checked: %d\n", count);
    printf("Students with errors: %d\n", invalid_count);
    printf("Students valid: %d\n", count - invalid_count);
    printf("============================\n");
}

// Function to debug and display all gender values
void debug_gender_data(const Student *students, int count)
{
    printf("\n=== Gender Data Debug ===\n");
    printf("Index\tName\t\tGender\t\tGender(hex)\t\tClassification\n");
    printf("-----\t----\t\t------\t\t-----------\t\t--------------\n");
    
    int male_test = 0, female_test = 0;
    
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%-10s\t'%s'\t\t", i+1, students[i].name, students[i].gender);
        
        // Print hex values to see encoding
        for (int j = 0; students[i].gender[j] != '\0'; j++)
        {
            printf("%02X ", (unsigned char)students[i].gender[j]);
        }
        printf("\t\t");
        
        // Test classification
        if (is_male_gender(students[i].gender)) {
            printf("MALE");
            male_test++;
        } else if (is_female_gender(students[i].gender)) {
            printf("FEMALE");
            female_test++;
        } else {
            printf("UNKNOWN");
        }
        printf("\n");
        
        // Only show first 10 for readability
        if (i >= 9) {
            printf("... (showing first 10 students only)\n");
            break;
        }
    }
    
    printf("\nDebug Summary:\n");
    printf("Male count (test): %d\n", male_test);
    printf("Female count (test): %d\n", female_test);
    printf("Unknown count (test): %d\n", (count > 9 ? 10 : count) - male_test - female_test);
    printf("========================\n");
}

// Function to debug gender data format
void debug_gender_data_format(const Student *students, int count)
{
    printf("\n=== Gender Data Debug Information ===\n");
    printf("Total students: %d\n", count);
    
    for (int i = 0; i < count; i++)
    {
        printf("Student %d: Name='%s', Gender='%s' (length=%d)\n", 
               i + 1, students[i].name, students[i].gender, (int)strlen(students[i].gender));
        
        // Print each character in gender field with its ASCII code
        printf("  Gender bytes: ");
        for (int j = 0; j < strlen(students[i].gender); j++)
        {
            printf("[%d:'%c'] ", (unsigned char)students[i].gender[j], students[i].gender[j]);
        }
        printf("\n");
    }
    printf("====================================\n");
}

int main()
{
    Student students[MAX_STUDENTS];
    int student_count = 0;
    const char *filename = "D:\\gis2411-2412.csv";
    
    // Load student data from file
    student_count = load_student_data(filename, students, MAX_STUDENTS);
    if (student_count < 0)
    {
        printf("Failed to load student data. Exiting...\n");
        return 1;
    }

    int choice;
    char search_term[50];
    int found_index;

    while (1)
    {
        display_menu();
        
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice)
        {
            case 1: // Display all students
                printf("\n=== All Students ===\n");
                print_table_header();
                print_student_info(students, student_count);
                break;

            case 2: // Find by student ID
                printf("Enter student ID to search: ");
                scanf("%s", search_term);
                found_index = find_student_by_id(students, student_count, search_term);
                if (found_index != -1)
                {
                    printf("Student found!\n");
                    print_student_details(&students[found_index], found_index);
                }
                else
                {
                    printf("Student with ID '%s' not found.\n", search_term);
                }
                break;

            case 3: // Find by name
                printf("Enter student name to search: ");
                scanf("%s", search_term);
                found_index = find_student_by_name(students, student_count, search_term);
                if (found_index != -1)
                {
                    printf("Student found!\n");
                    print_student_details(&students[found_index], found_index);
                }
                else
                {
                    printf("Student with name '%s' not found.\n", search_term);
                }
                break;

            case 4: // Sort by student ID
                sort_by_student_id(students, student_count);
                print_table_header();
                print_student_info(students, student_count);
                break;

            case 5: // Sort by name
                sort_by_name(students, student_count);
                print_table_header();
                print_student_info(students, student_count);
                break;

            case 6: // Sort by phone
                sort_by_phone(students, student_count);
                print_table_header();
                print_student_info(students, student_count);
                break;

            case 7: // Display statistics
                display_statistics(students, student_count);
                break;

            case 8: // Save student data to file
                {
                    char save_filename[100];
                    printf("Enter filename to save student data (e.g., output.csv): ");
                    scanf("%s", save_filename);
                    save_student_data(save_filename, students, student_count);
                }
                break;

            case 9: // Search students by class
                printf("Enter class name to search: ");
                scanf("%s", search_term);
                search_by_class(students, student_count, search_term);
                break;

            case 10: // Search students by phone prefix
                printf("Enter phone prefix to search: ");
                scanf("%s", search_term);
                search_by_phone_prefix(students, student_count, search_term);
                break;            case 11: // Validate student data
                validate_student_data(students, student_count);
                break;

            case 12: // Debug gender data
                debug_gender_data(students, student_count);
                break;

            case 13: // Exit
                printf("Thank you for using Student Information Management System!\n");
                return 0;

            default:
                printf("Invalid choice. Please select 1-13.\n");
                break;
        }
        
        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Clear input buffer
        getchar(); // Wait for Enter key
    }

    return 0;
}