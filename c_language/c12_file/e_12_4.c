
// Example 12-4: Check user validity in a system.
// Compile and run the program to check if the user is valid based on the information stored in the file f12-2.txt. The password is encrypted using a simple XOR operation with 15.

#include <stdio.h>

#include <stdlib.h>

#include <process.h>

#include <string.h>

struct sysuser
{
    char username[20];
    char password[8];
};

void encrypt(char *pwd);

int checkUserValid(struct sysuser *psu);

int main(void)
{
    struct sysuser su;

    printf("Enter username:");
    scanf("%s", su.username);
    printf("Enter password:");
    scanf("%s", su.password);
    if (checkUserValid(&su) == 1)
    {
        printf("Valid user!\n");
    }
    else
    {
        printf("Invalid user!\n");
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

int checkUserValid(struct sysuser *psu)
{
    FILE *fp;
    char usr[30], usr1[30], pwd[10];
    int check = 0;

    strcpy(usr, psu->username);
    strcpy(pwd, psu->password);
    encrypt(pwd);

    strcat(usr, " ");
    strcat(usr, pwd);
    strcat(usr, "\n");

    if ((fp = fopen("f12-2.txt", "r")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }

    while (!feof(fp))
    {
        fgets(usr1, 30, fp);
        if (strcmp(usr, usr1) == 0)
        {
            check = 1;
            break;
        }
    }

    if (fclose(fp))
    {
        printf("Can not close the file!\n");
        exit(0);
    }

    return check;
}

// Enter username:zhangwen
// Enter password:zw123
// Valid user!

// Enter username:zhangwen
// Enter password:abc 123
// Invalid user!