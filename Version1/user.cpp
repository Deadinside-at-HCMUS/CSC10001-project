#include <iostream>
#include "user.h"
#define MAX 100

using namespace std;

void showUsers(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers ) {
    if (countusers == 0) {
        cout << "Danh sách độc giả trống!" << endl;
    } else {
        for (int i = 0; i < countusers; i++) {
            cout << "Thông tin của độc gỉả thứ " << i + 1 << endl;
            cout << "_ Mã độc giả         : " << id[i] << endl;
            cout << "_ Họ tên             : " << nameuser[i] << endl;
            cout << "_ CMND               : " << cmnd[i] << endl;
            cout << "_ Ngày tháng năm sinh: " << birthday[i] << endl;
            cout << "_ Giới tính          : " << sex[i] << endl;
            cout << "_ Email              : " << email[i] << endl;
            cout << "_ Địa chỉ            : " << address[i] << endl;
            cout << "_ Ngày lập thẻ       : " << createday[i] << endl;
            cout << "_ Ngày hết hạn thẻ   : " << dueday[i] << endl;
            cout << endl;
        }
    }
}

void addUser(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers ) {
        int i = countusers;
        cout << "Thêm thông tin độc giả thứ " << i + 1 << endl;
        cin.ignore();
        cout << "_ Mã độc giả         : "; getline(cin, id[i]);
        cout << "_ Họ tên             : "; getline(cin,nameuser[i]);
        cout << "_ CMND               : "; getline(cin, cmnd[i]);
        cout << "_ Ngày tháng năm sinh: "; getline(cin, birthday[i]);
        cout << "_ Giới tính          : "; getline(cin, sex[i]);
        cout << "_ Email              : "; getline(cin, email[i]);
        cout << "_ Địa chỉ            : "; getline(cin, address[i]);
        cout << "_ Ngày lập thẻ       : "; getline(cin, createday[i]);
        cout << "_ Ngày hết hạn thẻ   : "; getline(cin, dueday[i]);
        countusers++;
}

void modifyUser(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers ) {
        int i;
        if (countusers == 0) {
            cout << "Danh sách độc giả trống!" << endl;
        } else {
            cout << "Mời nhập stt độc giả cần chỉnh sửa: "; cin >> i;
            cout << endl;
            if (countusers < i) {
                cout << "Stt độc giả lớn hơn danh sách độc giả hiện có!" << endl;
            } else {
                cout << "Chỉnh sửa thông tin độc giả thứ " << i << endl;
                cin.ignore();
                cout << "_ Mã độc giả         : "; getline(cin, id[i-1]);
                cout << "_ Họ tên             : "; getline(cin,nameuser[i-1]);
                cout << "_ CMND               : "; getline(cin,cmnd[i-1]);
                cout << "_ Ngày tháng năm sinh: "; getline(cin, birthday[i-1]);
                cout << "_ Giới tính          : "; getline(cin, sex[i-1]);
                cout << "_ Email              : "; getline(cin, email[i-1]);
                cout << "_ Địa chỉ            : "; getline(cin, address[i-1]);
                cout << "_ Ngày lập thẻ       : "; getline(cin, createday[i-1]);
                cout << "_ Ngày hết hạn thẻ   : "; getline(cin, dueday[i-1]);
            }
        }
}

void deleteUser(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers ) {
        int i;
        cout << "Mời nhập stt độc giả cần xóa: "; cin >> i;
        cout << endl;
        id[i-1] = id[i];
        nameuser[i-1] = nameuser[i];
        cmnd[i-1] = cmnd[i];
        birthday[i-1] = birthday[i];
        sex[i-1] = sex[i];
        email[i-1] = email[i];
        address[i-1] = address[i];
        createday[i-1] = createday[i];
        dueday[i-1] = dueday[i];
        countusers--;
        cout << "Độc giả thứ " << i << " đã được xóa!" << endl;
}

void findUserByCMND(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers ) {
        string cmndcheck;
        bool isavailable = false;
        cin.ignore();
        cout << "Mời nhập CMND độc giả cần tìm: "; getline(cin, cmndcheck);
        cout << endl;
        for (int i = 0; i < countusers; i++) {
            if (cmndcheck == cmnd[i]) {
                cout << "Thông tin của độc gỉả thứ " << i + 1 << endl;
                cout << "_ Mã độc giả         : " << id[i] << endl;
                cout << "_ Họ tên             : " << nameuser[i] << endl;
                cout << "_ CMND               : " << cmnd[i] << endl;
                cout << "_ Ngày tháng năm sinh: " << birthday[i] << endl;
                cout << "_ Giới tính          : " << sex[i] << endl;
                cout << "_ Email              : " << email[i] << endl;
                cout << "_ Địa chỉ            : " << address[i] << endl;
                cout << "_ Ngày lập thẻ       : " << createday[i] << endl;
                cout << "_ Ngày hết hạn thẻ   : " << dueday[i] << endl;
                isavailable = true;
            }
        }
        if (!isavailable)
            cout << "Độc giả có CMND " << cmndcheck << " không tồn tại!" << endl;
}

void findUsersByName(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers ) {
        string nameusercheck;
        bool isavailable = false;
        cin.ignore();
        cout << "Mời nhập tên độc giả cần tìm: "; getline(cin,nameusercheck);
        cout << endl;
        for (int i = 0; i < countusers; i++) {
            if (nameusercheck == nameuser[i]) {
                cout << "Thông tin của độc gỉả thứ " << i + 1 << endl;
                cout << "_ Mã độc giả         : " << id[i] << endl;
                cout << "_ Họ tên             : " << nameuser[i] << endl;
                cout << "_ CMND               : " << cmnd[i] << endl;
                cout << "_ Ngày tháng năm sinh: " << birthday[i] << endl;
                cout << "_ Giới tính          : " << sex[i] << endl;
                cout << "_ Email              : " << email[i] << endl;
                cout << "_ Địa chỉ            : " << address[i] << endl;
                cout << "_ Ngày lập thẻ       : " << createday[i] << endl;
                cout << "_ Ngày hết hạn thẻ   : " << dueday[i] << endl;
                isavailable = true;
            }
        }
        if (!isavailable)
            cout << "Độc giả có tên " << nameusercheck << " không tồn tại!" << endl;
}

void quantityusers(int &countusers) {
    cout << "Số lượng độc giả hiện có là: " << countusers << endl;
}

void sexusers(string sex[MAX], int &countusers) {
    string sexcheck;
    bool isavailable = false;
    int count = 0;
    cin.ignore();
    cout << "Mời bạn nhập giới tính độc giả cần thống kê: ";
    getline(cin, sexcheck);
    cout << endl;
    for (int i = 0; i < countusers; i++) {
        if (sexcheck == sex[i]) {
            count ++;
            isavailable = true;
        }
    }
    if (!isavailable)
        cout << "Độc giả giới tính " << sexcheck << " không tồn tại!" << endl;
    else
        cout << "Số lượng độc giả giới tính " << sexcheck <<  " là: " << count << endl;
}