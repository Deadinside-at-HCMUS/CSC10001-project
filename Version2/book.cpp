#include <iostream>
#include "book.h"
#define MAX 100

using namespace std;

void showBooks(Book book) {
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
            cout << "_ Giá sách           : " << book.price[i] << " VNĐ" << endl;
            cout << "_ Số quyển sách      : " << book.quantity[i] << endl;
            cout << endl;
        }
    }
}

void addBook(Book book) {
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

void modifyBook(Book book) {
        int i;
        if (book.countbooks == 0) {
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

void deleteBook(Book book) {
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

void findBooksByISBN(Book book) {
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

void findBooksByName(Book book) {
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

void quantitybooks(Book book) {
    int count = 0;
    for (int i = 0; i < book.countbooks; i++) {
        count += book.quantity[i];
    }
    cout << "Số lượng sách có trong thư viện là: " << count << endl;
}

void categorybooks(Book book) {
    int countsgk = 0;
    int countnovel = 0;
    int countliterature = 0;
    int countbiography = 0;
    int countcomic = 0;
    int countother = 0;
    for (int i = 0; i < book.countbooks; i++) {
        if (book.category[i] == "Sach giao khoa" || book.category[i] == "sach giao khoa" || book.category[i] == "sgk") {
            countsgk += book.quantity[i];
        } else if (book.category[i] == "Tieu thuyet" || book.category[i] == "tieu thuyet") {
            countnovel += book.quantity[i];
        } else if (book.category[i] == "Van hoc" || book.category[i] == "van hoc") {
            countliterature += book.quantity[i];
        } else if (book.category[i] == "Tu truyen" || book.category[i] == "tu truyen") {
            countbiography += book.quantity[i];
        } else if (book.category[i] == "Truyen tranh" || book.category[i] == "truyen tranh") {
            countcomic += book.quantity[i];
        } else
            countother += book.quantity[i];
    }
    cout << "Số lượng sách thuộc thể loại sách giáo khoa : " << countsgk <<  endl;
    cout << "Số lượng sách thuộc thể loại tiểu thuyết    : " << countnovel <<  endl;
    cout << "Số lượng sách thuộc thể loại văn học        : " << countliterature <<  endl;
    cout << "Số lượng sách thuộc thể loại tự truyện      : " << countbiography <<  endl;
    cout << "Số lượng sách thuộc thể loại truyện tranh   : " << countcomic <<  endl;
    cout << "Số lượng sách thuộc thể loại khác           : " << countother <<  endl;
}