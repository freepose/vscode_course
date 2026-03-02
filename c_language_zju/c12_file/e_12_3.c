
// Example 12-3: Copy user information file. Back up the user information file f12-2.txt of Example 12-2 and name the file f12-3.txt. Note: Place the file f12-2.txt in the same directory as the source program and execute the program.

#include <stdio.h>

#include <process.h>

int main(void)
{
    FILE *fp1, *fp2;
    char ch;

    if ((fp1 = fopen("f12-2.txt", "r")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    if ((fp2 = fopen("f12-3.txt", "w")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }

    while (!feof(fp1))
    {
        ch = fgetc(fp1);
        if (ch != EOF)
            fputc(ch, fp2);
    }

    if (fclose(fp1))
    {
        printf("Can not close the file!\n");
        exit(0);
    }

    if (fclose(fp2))
    {
        printf("Can not close the file!\n");
        exit(0);
    }

    return 0;
}
