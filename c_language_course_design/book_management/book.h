#ifndef BOOK_H
#define BOOK_H

typedef struct Book {
    char bookId[20];     // 鍥句功缂栧彿 TST-2024-001
    char isbn[20];       // ISBN
    char name[50];       // 涔﹀悕
    char author[30];     // 浣滆€?
    char publisher[30];  // 鍑虹増绀?
    char category[20];   // 鏂囧 / 涓撲笟
    int isBorrowed;      // 0 鏈€熷嚭锛? 宸插€熷嚭
    struct Book *next;
} Book;

/* 鍑芥暟澹版槑 */
Book* addBook(Book *head);
Book* deleteBook(Book *head, char *bookId);
void modifyBook(Book *head, char *bookId);
void displayBooks(Book *head);
Book* findBook(Book *head, char *bookId);
int checkBookId(char *bookId);    // 鏍￠獙 TST-xxxx-xxx
int getLimitDays(Book *b);        // 鑾峰彇鍊熼槄澶╂暟
void searchBooksByAuthor(Book *head, char *author);
void searchBooksByPublisher(Book *head, char *publisher);

#endif
