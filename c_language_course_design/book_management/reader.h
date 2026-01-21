#ifndef READER_H
#define READER_H

typedef struct Reader
{
    char cardId[20];
    char unit[30];
    char name[20];
    char gender[10];
    char title[20];      // 鏈鐢?/ 鐮旂┒鐢?
    char address[50];
    int borrowCount;     // 褰撳墠鍊熼槄鏁伴噺
    struct Reader *next;
} Reader;

/* 鍔熻兘鍑芥暟澹版槑 */
Reader* addReader(Reader *head);
Reader* deleteReader(Reader *head, char *cardId);
void modifyReader(Reader *head, char *cardId);
void displayReaders(Reader *head);
Reader* findReaderByCard(Reader *head, char *cardId);

#endif
