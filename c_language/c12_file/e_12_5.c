
// Example 12-5: Write a program to implement the binary read and write of user information file f12-5.txt. 
// Write 5 user information (username and password, password must be encrypted by the encrypt() function in Example 12-2) into the file, and then read all user information and display it on the screen.

#include <stdio.h>

#include <string.h>

#include <process.h>

#define SIZE 5

struct sysuser
{
    char username[20];
    char password[8];
};
void encrypt(char *pwd);

int main(void)
{
    FILE *fp;
    int i;
    struct sysuser u[SIZE], su[SIZE], *pu = u, *psu = su;

    if ((fp = fopen("f12-5.txt", "wb+")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }

    for (i = 0; i < SIZE; i++, pu++)
    {
        printf("Enter %i th sysuser(name password):", i);
        scanf("%s%s", pu->username, pu->password);
        encrypt(pu->password);
    }
    pu = u;
    fwrite(pu, sizeof(struct sysuser), SIZE, fp);
    rewind(fp);
    fread(psu, sizeof(struct sysuser), SIZE, fp);
    for (i = 0; i < SIZE; i++, psu++)
        printf("%s\t%s\n", psu->username, psu->password);

    if (fclose(fp))
    {
        printf("Can not close the file!\n");
        exit(0);
    }

    return 0;
}

void encrypt(char *pwd)
{
    int i;

    for (i = 0; i < strlen(pwd); i++)
    {
        pwd[i] = pwd[i] ^ 15;
    }
}

// Enter 0 th sysuser(name password):zhangsan zs123
// Enter 1 th sysuser(name password):wangxiao wx123
// Enter 2 th sysuser(name password):liusi ls123
// Enter 3 th sysuser(name password):minggo mg123
// Enter 4 th sysuser(name password):wengtao wt123
// zhangsan        u|>=<
// wangxiao        xw>=<
// liusi   c|>=<
// minggo  bh>=<
// wengtao x{>=<