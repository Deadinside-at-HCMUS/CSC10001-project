#include <stdio.h>
#include <cstring>
#include <string>
#include "book.h"
#define MAX 100

using namespace std;

void showBooks(Book &book, int &countbooks, int &countquantity) {
    countbooks = 0;
    countquantity = 0;
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/book.txt", "r");
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
    printf("%d", countbooks);
    fclose(fIn);
}

void addBook(Book &book, int &countbooks) {
    char newline[100];
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/book.txt", "r");
    if(fIn != NULL) {
        fgets(newline, 100, stdin);
        printf("Thêm thông tin độc giả thứ %d\n", countbooks + 1);
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
    fOut = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/book.txt", "a+");
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

//void addBook(Book &book) {
//        int i = book.countbooks;
//        bool checkisbn = false;
//        cout << "Thêm quyển sách thứ " << i + 1 << endl;
//        cin.ignore();
//        cout << "_ Mã sách (ISBN)     : "; getline(cin, book.isbn[i]);
//        for (int j = 0; j < i; j++) {
//            if (book.isbn[j] == book.isbn[i]) {
//                checkisbn = true;
//            }
//        }
//        if (checkisbn) {
//            cout << endl;
//            cout << "Mã sách (ISBN) đã tồn tại!" << endl;
//        } else {
//            cout << "_ Tên sách           : "; getline(cin, book.namebook[i]);
//            cout << "_ Tác giả            : "; getline(cin, book.nameauthor[i]);
//            cout << "_ Nhà xuất bản       : "; getline(cin, book.publishcompany[i]);
//            cout << "_ Năm xuất bản       : "; cin >> book.publishyear[i];
//            cin.ignore();
//            cout << "_ Thể loại           : "; getline(cin, book.category[i]);
//            cout << "_ Giá sách           : "; cin >> book.price[i];
//            cout << "_ Số quyển sách      : "; cin >> book.quantity[i];
//            book.countbooks++;
//        }
//}

//void modifyBook(Book &book) {
//        int i;
//        bool checkisbn = false;
//        if (book.countbooks== 0) {
//            cout << "Thư viện sách trống!" << endl;
//        } else {
//            cout << "Mời nhập stt sách cần chỉnh sửa: "; cin >> i;
//            cout << endl;
//            if (book.countbooks < i) {
//                cout << "Stt sách lớn hơn thư viện sách hiện có!" << endl;
//            } else {
//                cout << "Chỉnh sửa quyển sách thứ " << i << endl;
//                cin.ignore();
//                cout << "_ Mã sách (ISBN)     : "; getline(cin, book.isbn[i-1]);
//                for (int j = 0; j < i - 1; j++) {
//                    if (book.isbn[j] == book.isbn[i-1]) {
//                        checkisbn = true;
//                    }
//                }
//                if (checkisbn) {
//                    cout << endl;
//                    cout << "Mã sách (ISBN) đã tồn tại!" << endl;
//                } else {
//                    cout << "_ Tên sách           : "; getline(cin, book.namebook[i-1]);
//                    cout << "_ Tác giả            : "; getline(cin, book.nameauthor[i-1]);
//                    cout << "_ Nhà xuất bản       : "; getline(cin, book.publishcompany[i-1]);
//                    cout << "_ Năm xuất bản       : "; cin >> book.publishyear[i-1];
//                    cin.ignore();
//                    cout << "_ Thể loại           : "; getline(cin, book.category[i-1]);
//                    cout << "_ Giá sách           : "; cin >> book.price[i-1];
//                    cout << "_ Số quyển sách      : "; cin >> book.quantity[i-1];
//                }
//            }
//        }
//}

void deleteBook(Book &book, int &countbooks) {
    char ch;
    int position, temp = 1;
    FILE *fIn, *fOut;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/book.txt", "r");
    fOut = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/book-edited.txt", "w");
    ch = getc(fIn);
    while (ch != EOF) {
        ch = getc(fIn);
    }
    rewind(fIn);
    printf("Mời nhập stt sách cần xóa: ");
    scanf("%d", &position);
    ch = 'A';
    while (ch != EOF) {
        ch = getc(fIn);
        if (temp != position) {
            putc(ch, fOut);
        }
        if (ch == '\n') {
            temp++;
        }
    }
    countbooks--;
    fclose(fIn);
    fclose(fOut);
}


//void deleteBook(Book &book) {
//        int i;
//        cout << "Mời nhập stt sách cần xóa: "; cin >> i;
//        cout << endl;
//        book.isbn[i-1] = book.isbn[i];
//        book.namebook[i-1] = book.namebook[i];
//        book.nameauthor[i-1] = book.nameauthor[i];
//        book.publishcompany[i-1] = book.publishcompany[i];
//        book.publishyear[i-1] = book.publishyear[i];
//        book.category[i-1] = book.category[i];
//        book.price[i-1] = book.price[i];
//        book.quantity[i-1] = book.quantity[i];
//        book.countbooks--;
//        cout << "Quyển sách thứ " << i << " đã được xóa!" << endl;
//}

//void findBooksByISBN(Book &book) {
//        string isbncheck;
//        bool isavailable = false;
//        cin.ignore();
//        cout << "Mời nhập ISBN sách cần tìm: "; getline(cin, isbncheck);
//        cout << endl;
//        for (int i = 0; i < book.countbooks; i++) {
//            if (isbncheck == book.isbn[i]) {
//                cout << "Thông tin của quyển sách thứ " << i + 1 << endl;
//                cout << "_ Mã sách (ISBN)     : " << book.isbn[i] << endl;
//                cout << "_ Tên sách           : " << book.namebook[i] << endl;
//                cout << "_ Tác giả            : " << book.nameauthor[i] << endl;
//                cout << "_ Nhà xuất bản       : " << book.publishcompany[i] << endl;
//                cout << "_ Năm xuất bản       : " << book.publishyear[i] << endl;
//                cout << "_ Thể loại           : " << book.category[i] << endl;
//                cout << "_ Giá sách           : " << book.price[i] << " VNĐ" << endl;
//                cout << "_ Số quyển sách      : " << book.quantity[i] << endl;
//                isavailable = true;
//            }
//        }
//        if (!isavailable)
//            cout << "Quyển sách có ISBN " << isbncheck << " không tồn tại!" << endl;
//}

//void findBooksByName(Book &book) {
//        string namebookcheck;
//        bool isavailable = false;
//        cin.ignore();
//        cout << "Mời nhập tên quyển sách cần tìm: "; getline(cin, namebookcheck);
//        cout << endl;
//        for (int i = 0; i < book.countbooks; i++) {
//            if (namebookcheck == book.namebook[i]) {
//                cout << "Thông tin của quyển sách thứ " << i + 1 << endl;
//                cout << "_ Mã sách (ISBN)     : " << book.isbn[i] << endl;
//                cout << "_ Tên sách           : " << book.namebook[i] << endl;
//                cout << "_ Tác giả            : " << book.nameauthor[i] << endl;
//                cout << "_ Nhà xuất bản       : " << book.publishcompany[i] << endl;
//                cout << "_ Năm xuất bản       : " << book.publishyear[i] << endl;
//                cout << "_ Thể loại           : " << book.category[i] << endl;
//                cout << "_ Giá sách           : " << book.price[i] << " VNĐ" << endl;
//                cout << "_ Số quyển sách      : " << book.quantity[i] << endl;
//                isavailable = true;
//            }
//        }
//        if (!isavailable)
//            cout << "Quyển sách có tên " << namebookcheck << " không tồn tại!" << endl;
//}

void quantitybooks(int countquantity) {
    printf("Số lượng sách có trong thư viện là: %d\n" ,countquantity);
}

//void categorybooks(Book &book) {
//    string listcategory[MAX];
//    int quantitycategory[MAX];
//    int countcategory = 0;
//    int flag;
//    if (book.countbooks == 0)
//        cout << "Thư viện trống!" << endl;
//    else {
//        cout << "Số lượng sách thuộc thể loại: " << endl;
//        for (int i = 0; i < book.countbooks; i++) {
//            int count = 0;
//            for (int j = i + 1; j < book.countbooks; j++) {
//                if (book.category[i] != book.category[j])
//                    count++;
//                else
//                    flag = j;
//            }
//            if (count == book.countbooks - i - 1) {
//                listcategory[countcategory] = book.category[i];
//                quantitycategory[countcategory] += book.quantity[i];
//                countcategory++;
//            } else
//                book.quantity[flag] += book.quantity[i];
//        }
//
//        for (int i = 0; i < countcategory; i++)
//            cout << "_ " << listcategory[i] << ": " << quantitycategory[i] << endl;
//    }
//}

//void checkoutofstock(Book &book) {
//    int count = 0;
//    if (book.countbooks == 0) {
//        cout << "Thư viện trống!" << endl;
//    } else {
//        cout << "Danh sách sách đã được mượn hết: " << endl;
//        for (int i = 0; i < book.countbooks; i++) {
//            if (book.quantity[i] == 0) {
//                cout << "_ Tên sách: " << book.namebook[i] << " - ISBN: " << book.isbn[i] << endl;
//                count++;
//            }
//        }
//    }
//    if (count == 0) {
//        cout << endl;
//        cout << "Trống!" << endl;
//    }
//}