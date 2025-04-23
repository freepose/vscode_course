
// Example 12-6: Implement fund account management. The specific requirements are as follows:
// (1) The information of the fund account is stored in a random file, and the data items of the file include: record ID, occurrence date, occurrence event, occurrence amount (positive indicates income, negative indicates expenditure), and balance. Each time a transaction occurs, a new record should be added to the file, and the balance should be calculated once.
// (2) The program implements three functions, including: ① create a fund account file and add income or expenditure records; ② output all records and display the detailed income and expenditure information of the fund account; ③ query the last record to obtain the account balance. The account file is named cashbox.dat, and part of the file content is as follows:

#include "stdio.h"

#include "stdlib.h"

#include "process.h"

long size;

struct LogData
{
    long logid;
    char logdate[11];
    char lognote[15];
    double charge;
    double balance;
};

int inputchoice()
{
    int mychoice;

    printf("\nEnter your choice:\n");
    printf("1 - Add a new cash LOG.\n2 - List All Cash LOG.\n");
    printf("3 - Query Last Cash LOG.\n0 - End program.\n");
    scanf("%d", &mychoice);

    return mychoice;
}

long getLogcount(FILE *cfptr)
{
    long begin, end, logcount;

    fseek(cfptr, 0L, SEEK_SET);
    begin = ftell(cfptr);
    fseek(cfptr, 0L, SEEK_END);
    end = ftell(cfptr);
    logcount = (end - begin) / size;

    return logcount;
}

void ListAllLog(FILE *cfptr)
{
    struct LogData log;

    fseek(cfptr, 0L, SEEK_SET);
    fread(&log, size, 1, cfptr);
    printf("logid  logdate lognote charge balance\n");
    while (!feof(cfptr))
    {
        printf("%6ld %-11s %-15s %10.2lf %10.2lf\n", log.logid, log.logdate, log.lognote, log.charge, log.balance);
        fread(&log, size, 1, cfptr);
    }
}

void QueryLastLog(FILE *cfptr)
{
    struct LogData log;
    long logcount;

    logcount = getLogcount(cfptr);
    if (logcount > 0)
    {
        fseek(cfptr, size * (logcount - 1), SEEK_SET);
        fread(&log, size, 1, cfptr);
        printf("The last log is:\n");
        printf("logid:%-6ld\nlogdate:%-11s\nlognote:%-15s\n", log.logid, log.logdate, log.lognote);
        printf("charge:%-10.2lf\nbalance:%-10.2lf\n", log.charge, log.balance);
    }
    else
    {
        printf("no logs in file!\n");
    }
}

void AddNewLog(FILE *cfptr)
{
    struct LogData log, lastlog;
    long logcount;

    printf("Input logdate(format:2006-01-01):");
    scanf("%s", log.logdate);
    printf("Input lognote:");
    scanf("%s", log.lognote);
    printf("Input Charge:Income+ and expend-:");
    scanf("%lf", &log.charge);
    logcount = getLogcount(cfptr);

    if (logcount > 0)
    {
        fseek(cfptr, size * (logcount - 1), SEEK_SET);
        fread(&lastlog, size, 1, cfptr);
        log.logid = lastlog.logid + 1;
        log.balance = log.charge + lastlog.balance;
    }
    else
    {
        log.logid = 1;
        log.balance = log.charge;
    }
    rewind(cfptr);
    printf("logid= %ld\n", log.logid);
    fwrite(&log, sizeof(struct LogData), 1, cfptr);
}

int main(void)
{
    FILE *fp;
    int choice;

    if ((fp = fopen("cashbox.txt", "ab+")) == NULL)
    {
        printf("can not open file cashbox.txt!\n");
        exit(0);
    }
    size = sizeof(struct LogData);
    while ((choice = inputchoice()) != 0)
    {
        switch (choice)
        {
        case 1:
            AddNewLog(fp);
            break;
        case 2:
            ListAllLog(fp);
            break;
        case 3:
            QueryLastLog(fp);
            break;
        default:
            printf("Input Error.");
            break;
        }
    }
    if (fclose(fp) != 0)
    {
        printf("Can not close the file!\n");
        exit(0);
    }

    return 0;
}
