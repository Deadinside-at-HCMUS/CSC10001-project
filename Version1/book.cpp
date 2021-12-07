#include <iostream>
#include "book.h"
#define MAX 100

using namespace std;

void showBooks(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks ) {
    if (countbooks == 0) {
        cout << "Thư viện sách trống!" << endl;
    } else {
        for (int i = 0; i < countbooks; i++) {
            cout << "Thông tin của quyển sách thứ " << i + 1 << endl;
            cout << "_ Mã sách (ISBN)     : " << isbn[i] << endl;
            cout << "_ Tên sách           : " << namebook[i] << endl;
            cout << "_ Tác giả            : " << nameauthor[i] << endl;
            cout << "_ Nhà xuất bản       : " << publishcompany[i] << endl;
            cout << "_ Năm xuất bản       : " << publishyear[i] << endl;
            cout << "_ Thể loại           : " << category[i] << endl;
            cout << "_ Giá sách           : " << price[i] << " VNĐ" << endl;
            cout << "_ Số quyển sách      : " << quantity[i] << endl;
            cout << endl;
        }
    }
}

void addBook(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks ) {
        int i = countbooks;
        cout << "Thêm quyển sách thứ " << i + 1 << endl;
        cin.ignore();
        cout << "_ Mã sách (ISBN)     : "; getline(cin, isbn[i]);
        cout << "_ Tên sách           : "; getline(cin, namebook[i]);
        cout << "_ Tác giả            : "; getline(cin, nameauthor[i]);
        cout << "_ Nhà xuất bản       : "; getline(cin, publishcompany[i]);
        cout << "_ Năm xuất bản       : "; cin >> publishyear[i];
        cin.ignore();
        cout << "_ Thể loại           : "; getline(cin, category[i]);
        cout << "_ Giá sách           : "; cin >> price[i];
        cout << "_ Số quyển sách      : "; cin >> quantity[i];
        countbooks++;
}


void modifyBook(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks ) {
        int i;
        if (countbooks == 0) {
            cout << "Thư viện sách trống!" << endl;
        } else {
            cout << "Mời nhập stt sách cần chỉnh sửa: "; cin >> i;
            cout << endl;
            if (countbooks < i) {
                cout << "Stt sách lớn hơn thư viện sách hiện có!" << endl;
            } else {
                cout << "Chỉnh sửa quyển sách thứ " << i << endl;
                cin.ignore();
                cout << "_ Mã sách (ISBN)     : "; getline(cin, isbn[i-1]);
                cout << "_ Tên sách           : "; getline(cin, namebook[i-1]);
                cout << "_ Tác giả            : "; getline(cin, nameauthor[i-1]);
                cout << "_ Nhà xuất bản       : "; getline(cin, publishcompany[i-1]);
                cout << "_ Năm xuất bản       : "; cin >> publishyear[i-1];
                cin.ignore();
                cout << "_ Thể loại           : "; getline(cin, category[i-1]);
                cout << "_ Giá sách           : "; cin >> price[i-1];
                cout << "_ Số quyển sách      : "; cin >> quantity[i-1];
            }
        }
}


void deleteBook(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks ) {
        int i;
        cout << "Mời nhập stt sách cần xóa: "; cin >> i;
        cout << endl;
        isbn[i-1] = isbn[i];
        namebook[i-1] = namebook[i];
        nameauthor[i-1] = nameauthor[i];
        publishcompany[i-1] = publishcompany[i];
        publishyear[i-1] = publishyear[i];
        category[i-1] = category[i];
        price[i-1] = price[i];
        quantity[i-1] = quantity[i];
        countbooks--;
        cout << "Quyển sách thứ " << i << " đã được xóa!" << endl;
}

void findBooksByISBN(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks ) {
        string isbncheck;
        bool isavailable = false;
        cin.ignore();
        cout << "Mời nhập ISBN sách cần tìm: "; getline(cin, isbncheck);
        cout << endl;
        for (int i = 0; i < countbooks; i++) {
            if (isbncheck == isbn[i]) {
                cout << "Thông tin của quyển sách thứ " << i + 1 << endl;
                cout << "_ Mã sách (ISBN)     : " << isbn[i] << endl;
                cout << "_ Tên sách           : " << namebook[i] << endl;
                cout << "_ Tác giả            : " << nameauthor[i] << endl;
                cout << "_ Nhà xuất bản       : " << publishcompany[i] << endl;
                cout << "_ Năm xuất bản       : " << publishyear[i] << endl;
                cout << "_ Thể loại           : " << category[i] << endl;
                cout << "_ Giá sách           : " << price[i] << " VNĐ" << endl;
                cout << "_ Số quyển sách      : " << quantity[i] << endl;
                isavailable = true;
            }
        }
        if (!isavailable)
            cout << "Quyển sách có ISBN " << isbncheck << " không tồn tại!" << endl;
}

void findBooksByName(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks ) {
        string namebookcheck;
        bool isavailable = false;
        cin.ignore();
        cout << "Mời nhập tên quyển sách cần tìm: "; getline(cin, namebookcheck);
        cout << endl;
        for (int i = 0; i < countbooks; i++) {
            if (namebookcheck == isbn[i]) {
                cout << "Thông tin của quyển sách thứ " << i + 1 << endl;
                cout << "_ Mã sách (ISBN)     : " << isbn[i] << endl;
                cout << "_ Tên sách           : " << namebook[i] << endl;
                cout << "_ Tác giả            : " << nameauthor[i] << endl;
                cout << "_ Nhà xuất bản       : " << publishcompany[i] << endl;
                cout << "_ Năm xuất bản       : " << publishyear[i] << endl;
                cout << "_ Thể loại           : " << category[i] << endl;
                cout << "_ Giá sách           : " << price[i] << " VNĐ" << endl;
                cout << "_ Số quyển sách      : " << quantity[i] << endl;
                isavailable = true;
            }
        }
        if (!isavailable)
            cout << "Quyển sách có tên " << namebookcheck << " không tồn tại!" << endl;
}

void quantitybooks(int quantity[MAX], int &countbooks) {
    int count = 0;
    for (int i = 0; i < countbooks; i++) {
        count += quantity[i];
    }
    cout << "Số lượng sách có trong thư viện là: " << count << endl;
}

void categorybooks(string category[MAX], int quantity[MAX], int &countbooks) {
    string categorycheck;
    bool isavailable = false;
    int count = 0;
    cin.ignore();
    cout << "Mời bạn nhập thể loại sách cần thống kê: ";
    getline(cin, categorycheck);
    cout << endl;
    for (int i = 0; i < countbooks; i++) {
        if (categorycheck == category[i]) {
            count += quantity[i];
            isavailable = true;
        }
    }
    if (!isavailable)
        cout << "Sách thuộc thể loại " << categorycheck << " không tồn tại!" << endl;
    else
        cout << "Số lượng sách thuộc thể loại " << categorycheck <<  " có trong thư viện là: " << count << endl;
}