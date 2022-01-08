#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include "book.h"
#define MAX 100

using namespace std;

void showBooks(Book &book, int &countbooks, int &countquantity) {
    countbooks = 0;
    countquantity = 0;
    FILE *fIn;
    fIn = fopen("book.txt", "r");
    if (fIn != NULL) {
        while(!feof(fIn)) {
            printf("Thông tin của quyển sách thứ %d\n", countbooks + 1);
            fscanf(fIn, "%[^-] - ", book.isbn);
            fscanf(fIn, "%[^-] - ", book.namebook);
            fscanf(fIn, "%[^-] - ", book.nameauthor);
            fscanf(fIn, "%[^-] - ", book.publishcompany);
            fscanf(fIn, "%[^-] - ", book.publishyear);
            fscanf(fIn, "%[^-] - ", book.category);
            fscanf(fIn, "%[^-] - ", book.price);
            fscanf(fIn, "%[^\n]\n", book.quantity);
            printf("_ Mã sách (ISBN)      : %s\n", book.isbn);
            printf("_ Tên sách            : %s\n", book.namebook);
            printf("_ Tác giả             : %s\n", book.nameauthor);
            printf("_ Nhà xuất bản        : %s\n", book.publishcompany);
            printf("_ Năm xuất bản        : %s\n", book.publishyear);
            printf("_ Thể loại            : %s\n", book.category);
            printf("_ Giá sách            : %sVNĐ\n", book.price);
            printf("_ Số quyển sách       : %s\n", book.quantity);
            printf("\n");
            countquantity += stoi(book.quantity);
            countbooks++;
        }
    }
    fclose(fIn);
}

void addBook(Book &book, int &countbooks) {
    char newline[MAX];
    FILE *fIn;
    fIn = fopen("book.txt", "r");
    if(fIn != NULL) {
        fgets(newline, 100, stdin);
        printf("Thêm thông tin sách thứ %d\n", countbooks + 1);
        printf("_ Mã sách (ISBN)      : "); fgets(book.isbn, MAX, stdin);
        strtok(book.isbn, "\n");
        printf("_ Tên sách            : "); fgets(book.namebook, MAX, stdin);
        strtok(book.namebook, "\n");
        printf("_ Tác giả             : "); fgets(book.nameauthor, MAX, stdin);
        strtok(book.nameauthor, "\n");
        printf("_ Nhà xuất bản        : "); fgets(book.publishcompany, MAX, stdin);
        strtok(book.publishcompany, "\n");
        printf("_ Năm xuất bản        : "); fgets(book.publishyear, MAX, stdin);
        strtok(book.publishyear, "\n");
        printf("_ Thể loại            : "); fgets(book.category, MAX, stdin);
        strtok(book.category, "\n");
        printf("_ Giá sách            : "); fgets(book.price, MAX, stdin);
        strtok(book.price, "\n");
        printf("_ Số quyển sách       : "); fgets(book.quantity, MAX, stdin);
        strtok(book.quantity, "\n");
    }
    fclose(fIn);
    countbooks++;
    FILE *fOut;
    fOut = fopen("book.txt", "a+");
    if(fOut != NULL) {
        fprintf(fOut, "\n%s", book.isbn);
        fprintf(fOut, " - %s", book.namebook);
        fprintf(fOut, " - %s", book.nameauthor);
        fprintf(fOut, " - %s", book.publishcompany);
        fprintf(fOut, " - %s", book.publishyear);
        fprintf(fOut, " - %s", book.category);
        fprintf(fOut, " - %s", book.price);
        fprintf(fOut, " - %s", book.quantity);
    }
    fclose(fOut);
}

void modifyBook(Book &book) {
    char newline[MAX];
    int position;
    int count = 0;
    int ch;
    int edited = 0;
    printf("Mời nhập stt sách cần chỉnh sửa: ");
    scanf("%d", &position);
    FILE *fIn, *fOut;
    fIn = fopen("book.txt", "r");
    fOut = fopen("book-edited.txt", "w");
    while((ch = fgetc(fIn)) != EOF) {
        if(ch == '\n')
            count++;
        if(count == position-1 && edited == 0) {
            fgets(newline, 100, stdin);
            printf("_ Mã sách (ISBN)      : "); fgets(book.isbn, MAX, stdin);
            strtok(book.isbn, "\n");
            printf("_ Tên sách            : "); fgets(book.namebook, MAX, stdin);
            strtok(book.namebook, "\n");
            printf("_ Tác giả             : "); fgets(book.nameauthor, MAX, stdin);
            strtok(book.nameauthor, "\n");
            printf("_ Nhà xuất bản        : "); fgets(book.publishcompany, MAX, stdin);
            strtok(book.publishcompany, "\n");
            printf("_ Năm xuất bản        : "); fgets(book.publishyear, MAX, stdin);
            strtok(book.publishyear, "\n");
            printf("_ Thể loại            : "); fgets(book.category, MAX, stdin);
            strtok(book.category, "\n");
            printf("_ Giá sách            : "); fgets(book.price, MAX, stdin);
            strtok(book.price, "\n");
            printf("_ Số quyển sách       : "); fgets(book.quantity, MAX, stdin);
            strtok(book.quantity, "\n");

            if(count == 0) {
                fprintf(fOut, "%s", book.isbn);
                fprintf(fOut, " - %s", book.namebook);
                fprintf(fOut, " - %s", book.nameauthor);
                fprintf(fOut, " - %s", book.publishcompany);
                fprintf(fOut, " - %s", book.publishyear);
                fprintf(fOut, " - %s", book.category);
                fprintf(fOut, " - %s", book.price);
                fprintf(fOut, " - %s", book.quantity);
                fprintf(fOut,"\n");
            }
            else {
                fprintf(fOut, "\n%s", book.isbn);
                fprintf(fOut, " - %s", book.namebook);
                fprintf(fOut, " - %s", book.nameauthor);
                fprintf(fOut, " - %s", book.publishcompany);
                fprintf(fOut, " - %s", book.publishyear);
                fprintf(fOut, " - %s", book.category);
                fprintf(fOut, " - %s", book.price);
                fprintf(fOut, " - %s", book.quantity);
                fprintf(fOut,"\n");
            }
            edited=1;

            while( (ch = fgetc(fIn)) != EOF ) {
                if(ch == '\n')
                    break;
            }
        } else {
            fprintf(fOut,"%c",ch);
        }
    }
    fclose(fIn);
    fclose(fOut);
    if(edited==1)
        printf("\nChỉnh sửa thông tin sách thành công!\n");
    else
        printf("\nSTT sách không tồn tại!\n");
}

void deleteBook(Book &book, int &countbooks) {
    int position;
    int count = 0;
    int ch;
    int edited = 0;
    printf("Mời nhập stt sách cần xóa: ");
    scanf("%d", &position);
    FILE *fIn, *fOut;
    fIn = fopen("book.txt", "r");
    fOut = fopen("book-edited.txt", "w");
    while((ch = fgetc(fIn)) != EOF) {
        if(ch == '\n')
            count++;
        if(count == position-1 && edited == 0) {
            if(count != 0)
                fprintf(fOut,"\n");

            edited=1;

            while((ch = fgetc(fIn)) != EOF) {
                if(ch == '\n')
                    break;
            }
        } else
            fprintf(fOut,"%c",ch);
    }
    countbooks--;
    fclose(fIn);
    fclose(fOut);
    if(edited==1)
        printf("\nXóa sách thành công!\n");
    else
        printf("\nSTT sách không tồn tại!\n");
}

void findBookByISBN(Book &book) {
    char isbncheck[MAX];
    char temp[MAX];
    char line[MAX];
    char newline[MAX];
    int position;
    int ch;
    int count = 0;
    bool isavailable = false;
    fgets(newline, 100, stdin);
    printf("Mời nhập ISBN sách cần tìm: "); fgets(isbncheck, MAX, stdin);
    strtok(isbncheck, "\n");
    FILE *fIn;
    fIn = fopen("book.txt", "r");
    if (fIn != NULL) {
        while (!feof(fIn)) {
            ch = fgetc(fIn);
            if(ch == '\n')
            {
                count++;
            }
            fscanf(fIn, "%s", temp);
            if (strcmp(temp, isbncheck) == 0) {
                position = count;
                count = 0;
                isavailable = true;
                break;
            }
        }
    }
    fclose(fIn);

    if(isavailable) {
        FILE *fInNew;
        fInNew = fopen("book.txt", "r");
        if (fInNew != NULL) {
            while (!feof(fInNew)) {
                ch = fgetc(fInNew);
                if(ch == '\n')
                {
                    count++;
                }
                fscanf(fInNew, "%[^\n]", line);
                if (count == position) {
                    printf("\nThông tin của quyển sách cần tìm: \n");
                    printf("%s\n", line);
                }
            }
        }
        fclose(fInNew);
    } else
        printf("Quyển sách có ISBN %s không tồn tại!\n", isbncheck);
}

void findBooksByName(Book &book) {
    char namecheck[MAX];
    char temp[MAX];
    char line[MAX];
    char newline[MAX];
    int position;
    int ch;
    int count = 0;
    bool isavailable = false;
    fgets(newline, 100, stdin);
    printf("Mời nhập tên quyển sách cần tìm: "); fgets(namecheck, MAX, stdin);
    strtok(namecheck, "\n");
    FILE *fIn;
    fIn = fopen("book.txt", "r");
    if (fIn != NULL) {
        while (!feof(fIn)) {
            count++;
            fscanf(fIn, "%[^-] - ", temp);
            if (strcmp(temp, namecheck) == 0) {
                position = round((count-2)/8) + 1;
                count = 0;
                isavailable = true;
                break;
            }
        }
    }
    fclose(fIn);

    if(isavailable) {
        FILE *fInNew;
        fInNew = fopen("book.txt", "r");
        if (fInNew != NULL) {
            while (!feof(fInNew)) {
                ch = fgetc(fInNew);
                if(ch == '\n')
                {
                    count++;
                }
                fscanf(fInNew, "%[^\n]", line);
                if (count == position) {
                    printf("\nThông tin của quyển sách cần tìm: \n");
                    printf("%s\n", line);
                }
            }
        }
        fclose(fInNew);
    } else
        printf("Quyển sách có tên %s không tồn tại!\n", namecheck);
}

void quantitybooks(int countquantity) {
    printf("Số lượng sách có trong thư viện là: %d\n" ,countquantity);
}

void categorybooks(Book &book) {
    FILE *fIn;
    fIn = fopen("book.txt", "r");
    printf("Số lượng sách thuộc thể loại: \n");
    if (fIn != NULL) {
        while(!feof(fIn)) {
            fscanf(fIn, "%[^-] - ", book.isbn);
            fscanf(fIn, "%[^-] - ", book.namebook);
            fscanf(fIn, "%[^-] - ", book.nameauthor);
            fscanf(fIn, "%[^-] - ", book.publishcompany);
            fscanf(fIn, "%[^-] - ", book.publishyear);
            fscanf(fIn, "%[^-] - ", book.category);
            fscanf(fIn, "%[^-] - ", book.price);
            fscanf(fIn, "%[^\n]\n", book.quantity);
            printf("_ %s: %s\n", book.category, book.quantity);
        }
    }
    fclose(fIn);
}