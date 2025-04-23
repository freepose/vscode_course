
#include<stdio.h>

int main()
{
    int grade = 0, sum = 0, counter = 0;
    double average = 0.;

    while (grade != -1)
    {
        scanf("%d", &grade);
        if (grade != -1)
        {
            sum += grade;
            counter++;
        }
    }
    if (counter > 0)
    {
        average = sum * 1.0 / counter;
    } 
    printf("%d students: sum = %d, avg = %lf\n", counter, sum, average);
    return 0;
}
