
// Example 12-2: To ensure system security, user accounts and passwords are usually required to log in to the system. The system user information is stored in a file, and the system account name and password consist of several letters and numbers. For security reasons, the password in the file cannot be in plaintext and must be encrypted. Please write a program to implement: input 5 user information (including account name and password) and write it into the file f12-2.dat. Each user information in the file occupies one line, and there is a space between the account name and the encrypted password. Password encryption algorithm: invert the low four bits of each character ASCII code, and keep the high four bits unchanged (that is, XOR it with 15).*/

#include <stdio.h>

#include <string.h>

#include <process.h>

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
    struct sysuser su;

    if ((fp = fopen("f12-2.txt", "w")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }

    for (i = 1; i <= 5; i++)
    {
        printf("Enter %i th sysuser(name password):", i);
        scanf("%s%s", su.username, su.password);
        encrypt(su.password);
        fprintf(fp, "%s %s\n", su.username, su.password);
    }
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
