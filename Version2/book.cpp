#include <iostream>
#include "book.h"
#define MAX 100

using namespace std;

void showBooks(Book &book) {
    if (book.countbooks == 0) {
        cout << "Thư viện sách trống!" << endl;
    } else {
        for (int i = 0; i < book.countbooks; i++) {
            cout << "Thông tin của quyển sách thứ " << i + 1 << endl;
            cout << "_ Mã sách (ISBN)     : " << book.isbn[i] << endl;
            cout << "_ Tên sách           : " << book.namebook[i] << endl;
            cout << "_ Tác giả            : " << book.nameauthor[i] << endl;
            cout << "_ Nhà xuất bản       : " << book.publishcompany[i] << endl;
            cout << "_ Năm xuất bản       : " << book.publishyear[i] << endl;
            cout << "_ Thể loại           : " << book.category[i] << endl;
            cout << "_ Giá sách           : " << book.price[i] << endl;
            cout << "_ Số quyển sách      : " << book.quantity[i] << endl;
            cout << endl;
        }
    }
}

void addBook(Book &book) {
        int i = book.countbooks;
        cout << "Thêm quyển sách thứ " << i + 1 << endl;
        cin.ignore();
        cout << "_ Mã sách (ISBN)     : "; getline(cin, book.isbn[i]);
        cout << "_ Tên sách           : "; getline(cin, book.namebook[i]);
        cout << "_ Tác giả            : "; getline(cin, book.nameauthor[i]);
        cout << "_ Nhà xuất bản       : "; getline(cin, book.publishcompany[i]);
        cout << "_ Năm xuất bản       : "; cin >> book.publishyear[i];
        cin.ignore();
        cout << "_ Thể loại           : "; getline(cin, book.category[i]);
        cout << "_ Giá sách           : "; cin >> book.price[i];
        cout << "_ Số quyển sách      : "; cin >> book.quantity[i];
        book.countbooks++;
}

void modifyBook(Book &book) {
        int i;
        if (book.countbooks== 0) {
            cout << "Thư viện sách trống!" << endl;
        } else {
            cout << "Mời nhập stt sách cần chỉnh sửa: "; cin >> i;
            cout << endl;
            if (book.countbooks < i) {
                cout << "Stt sách lớn hơn thư viện sách hiện có!" << endl;
            } else {
                cout << "Chỉnh sửa quyển sách thứ " << i << endl;
                cin.ignore();
                cout << "_ Mã sách (ISBN)     : "; getline(cin, book.isbn[i-1]);
                cout << "_ Tên sách           : "; getline(cin, book.namebook[i-1]);
                cout << "_ Tác giả            : "; getline(cin, book.nameauthor[i-1]);
                cout << "_ Nhà xuất bản       : "; getline(cin, book.publishcompany[i-1]);
                cout << "_ Năm xuất bản       : "; cin >> book.publishyear[i-1];
                cin.ignore();
                cout << "_ Thể loại           : "; getline(cin, book.category[i-1]);
                cout << "_ Giá sách           : "; cin >> book.price[i-1];
                cout << "_ Số quyển sách      : "; cin >> book.quantity[i-1];
            }
        }
}

void deleteBook(Book &book) {
        int i;
        cout << "Mời nhập stt sách cần xóa: "; cin >> i;
        cout << endl;
        book.isbn[i-1] = book.isbn[i];
        book.namebook[i-1] = book.namebook[i];
        book.nameauthor[i-1] = book.nameauthor[i];
        book.publishcompany[i-1] = book.publishcompany[i];
        book.publishyear[i-1] = book.publishyear[i];
        book.category[i-1] = book.category[i];
        book.price[i-1] = book.price[i];
        book.quantity[i-1] = book.quantity[i];
        book.countbooks--;
        cout << "Quyển sách thứ " << i << " đã được xóa!" << endl;
}

void findBooksByISBN(Book &book) {
        string isbncheck;
        bool isavailable = false;
        cin.ignore();
        cout << "Mời nhập ISBN sách cần tìm: "; getline(cin, isbncheck);
        cout << endl;
        for (int i = 0; i < book.countbooks; i++) {
            if (isbncheck == book.isbn[i]) {
                cout << "Thông tin của quyển sách thứ " << i + 1 << endl;
                cout << "_ Mã sách (ISBN)     : " << book.isbn[i] << endl;
                cout << "_ Tên sách           : " << book.namebook[i] << endl;
                cout << "_ Tác giả            : " << book.nameauthor[i] << endl;
                cout << "_ Nhà xuất bản       : " << book.publishcompany[i] << endl;
                cout << "_ Năm xuất bản       : " << book.publishyear[i] << endl;
                cout << "_ Thể loại           : " << book.category[i] << endl;
                cout << "_ Giá sách           : " << book.price[i] << " VNĐ" << endl;
                cout << "_ Số quyển sách      : " << book.quantity[i] << endl;
                isavailable = true;
            }
        }
        if (!isavailable)
            cout << "Quyển sách có ISBN " << isbncheck << " không tồn tại!" << endl;
}

void findBooksByName(Book &book) {
        string namebookcheck;
        bool isavailable = false;
        cin.ignore();
        cout << "Mời nhập tên quyển sách cần tìm: "; getline(cin, namebookcheck);
        cout << endl;
        for (int i = 0; i < book.countbooks; i++) {
            if (namebookcheck == book.isbn[i]) {
                cout << "Thông tin của quyển sách thứ " << i + 1 << endl;
                cout << "_ Mã sách (ISBN)     : " << book.isbn[i] << endl;
                cout << "_ Tên sách           : " << book.namebook[i] << endl;
                cout << "_ Tác giả            : " << book.nameauthor[i] << endl;
                cout << "_ Nhà xuất bản       : " << book.publishcompany[i] << endl;
                cout << "_ Năm xuất bản       : " << book.publishyear[i] << endl;
                cout << "_ Thể loại           : " << book.category[i] << endl;
                cout << "_ Giá sách           : " << book.price[i] << " VNĐ" << endl;
                cout << "_ Số quyển sách      : " << book.quantity[i] << endl;
                isavailable = true;
            }
        }
        if (!isavailable)
            cout << "Quyển sách có tên " << namebookcheck << " không tồn tại!" << endl;
}

void quantitybooks(Book &book) {
    int count = 0;
    for (int i = 0; i < book.countbooks; i++) {
        count += book.quantity[i];
    }
    cout << "Số lượng sách có trong thư viện là: " << count << endl;
}

void categorybooks(Book &book) {
    string listcategory[MAX];
    int quantitycategory[MAX];
    int countcategory = 0;
    int flag;
    if (book.countbooks == 0)
        cout << "Thư viện trống!" << endl;
    else {
        cout << "Số lượng sách thể loại: " << endl;
        for (int i = 0; i < book.countbooks; i++) {
            int count = 0;
            for (int j = i + 1; j < book.countbooks; j++) {
                if (book.category[i] != book.category[j])
                    count++;
                else
                    flag = j;
            }
            if (count == book.countbooks - i - 1) {
                listcategory[countcategory] = book.category[i];
                quantitycategory[countcategory] += book.quantity[i];
                countcategory++;
            } else
                book.quantity[flag] += book.quantity[i];
        }

        for (int i = 0; i < countcategory; i++)
            cout << "_ " << listcategory[i] << ": " << quantitycategory[i] << endl;
    }
}