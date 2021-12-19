#include <iostream>
#include "user.h"
#define MAX 100

using namespace std;

void showUsers(User user) {
    if (user.countusers == 0) {
        cout << "Danh sách độc giả trống!" << endl;
    } else {
        for (int i = 0; i < user.countusers; i++) {
            cout << "Thông tin của độc gỉả thứ " << i + 1 << endl;
            cout << "_ Mã độc giả          : " << user.id[i] << endl;
            cout << "_ Họ tên              : " << user.nameuser[i] << endl;
            cout << "_ CMND                : " << user.cmnd[i] << endl;
            cout << "_ Ngày tháng năm sinh : " << user.birthday[i] << endl;
            cout << "_ Giới tính           : " << user.sex[i] << endl;
            cout << "_ Email               : " << user.email[i] << endl;
            cout << "_ Địa chỉ             : " << user.address[i] << endl;
            cout << "_ Ngày lập thẻ        : " << user.createday[i] << endl;
            cout << "_ Ngày hết hạn thẻ    : " << user.dueday[i] << endl;
            cout << endl;
        }
    }
}

void addUser(User user) {
        int i = user.countusers;
        cout << "Thêm thông tin độc giả thứ " << i + 1 << endl;
        cin.ignore();
        cout << "_ Mã độc giả               : "; getline(cin, user.id[i]);
        cout << "_ Họ tên                   : "; getline(cin, user.nameuser[i]);
        cout << "_ CMND                     : "; getline(cin, user.cmnd[i]);
        cout << "_ Ngày tháng năm sinh      : "; getline(cin, user.birthday[i]);
        cout << "_ Giới tính                : "; getline(cin, user.sex[i]);
        cout << "_ Email                    : "; getline(cin, user.email[i]);
        cout << "_ Địa chỉ                  : "; getline(cin, user.address[i]);
        cout << "_ Ngày lập thẻ (yyyy/mm/dd): "; getline(cin, user.createday[i]);
        string yearcreate = user.createday[i].substr(0,4);
        string monthdaycreate = user.createday[i].substr(4,6);
        int numdueyear = stoi(yearcreate) + 4;
        user.dueday[i] = to_string(numdueyear) + monthdaycreate;
        user.countusers++;
}

void modifyUser(User user){
        int i;
        if (user.countusers == 0) {
            cout << "Danh sách độc giả trống!" << endl;
        } else {
            cout << "Mời nhập stt độc giả cần chỉnh sửa: "; cin >> i;
            cout << endl;
            if (user.countusers < i) {
                cout << "Stt độc giả lớn hơn danh sách độc giả hiện có!" << endl;
            } else {
                cout << "Chỉnh sửa thông tin độc giả thứ " << i << endl;
                cin.ignore();
                cout << "_ Mã độc giả          : "; getline(cin, user.id[i-1]);
                cout << "_ Họ tên              : "; getline(cin, user.nameuser[i-1]);
                cout << "_ CMND                : "; getline(cin, user.cmnd[i-1]);
                cout << "_ Ngày tháng năm sinh : "; getline(cin, user.birthday[i-1]);
                cout << "_ Giới tính           : "; getline(cin, user.sex[i-1]);
                cout << "_ Email               : "; getline(cin, user.email[i-1]);
                cout << "_ Địa chỉ             : "; getline(cin, user.address[i-1]);
                cout << "_ Ngày lập thẻ        : "; getline(cin, user.createday[i-1]);
                cout << "_ Ngày hết hạn thẻ    : "; getline(cin, user.dueday[i-1]);
            }
        }
}

void deleteUser(User user) {
        int i;
        cout << "Mời nhập stt độc giả cần xóa: "; cin >> i;
        cout << endl;
        user.id[i-1] = user.id[i];
        user.nameuser[i-1] = user.nameuser[i];
        user.cmnd[i-1] = user.cmnd[i];
        user.birthday[i-1] = user.birthday[i];
        user.sex[i-1] = user.sex[i];
        user.email[i-1] = user.email[i];
        user.address[i-1] = user.address[i];
        user.createday[i-1] = user.createday[i];
        user.dueday[i-1] = user.dueday[i];
        user.countusers--;
        cout << "Độc giả thứ " << i << " đã được xóa!" << endl;
}

void findUserByCMND(User user) {
        string cmndcheck;
        bool isavailable = false;
        cin.ignore();
        cout << "Mời nhập CMND độc giả cần tìm: "; getline(cin, cmndcheck);
        cout << endl;
        for (int i = 0; i < user.countusers; i++) {
            if (cmndcheck == user.cmnd[i]) {
                cout << "Thông tin của độc gỉả thứ " << i + 1 << endl;
                cout << "_ Mã độc giả          : " << user.id[i] << endl;
                cout << "_ Họ tên              : " << user.nameuser[i] << endl;
                cout << "_ CMND                : " << user.cmnd[i] << endl;
                cout << "_ Ngày tháng năm sinh : " << user.birthday[i] << endl;
                cout << "_ Giới tính           : " << user.sex[i] << endl;
                cout << "_ Email               : " << user.email[i] << endl;
                cout << "_ Địa chỉ             : " << user.address[i] << endl;
                cout << "_ Ngày lập thẻ        : " << user.createday[i] << endl;
                cout << "_ Ngày hết hạn thẻ    : " << user.dueday[i] << endl;
                isavailable = true;
            }
        }
        if (!isavailable)
            cout << "Độc giả có CMND " << cmndcheck << " không tồn tại!" << endl;
}

void findUsersByName(User user) {
        string nameusercheck;
        bool isavailable = false;
        cin.ignore();
        cout << "Mời nhập tên độc giả cần tìm: "; getline(cin,nameusercheck);
        cout << endl;
        for (int i = 0; i < user.countusers; i++) {
            if (nameusercheck == user.nameuser[i]) {
                cout << "Thông tin của độc gỉả thứ " << i + 1 << endl;
                cout << "_ Mã độc giả          : " << user.id[i] << endl;
                cout << "_ Họ tên              : " << user.nameuser[i] << endl;
                cout << "_ CMND                : " << user.cmnd[i] << endl;
                cout << "_ Ngày tháng năm sinh : " << user.birthday[i] << endl;
                cout << "_ Giới tính           : " << user.sex[i] << endl;
                cout << "_ Email               : " << user.email[i] << endl;
                cout << "_ Địa chỉ             : " << user.address[i] << endl;
                cout << "_ Ngày lập thẻ        : " << user.createday[i] << endl;
                cout << "_ Ngày hết hạn thẻ    : " << user.dueday[i] << endl;
                isavailable = true;
            }
        }
        if (!isavailable)
            cout << "Độc giả có tên " << nameusercheck << " không tồn tại!" << endl;
}

void quantityusers(User user) {
    cout << "Số lượng độc giả hiện có là: " << user.countusers << endl;
}

void sexusers(User user) {
    int countmale = 0;
    int countfemale = 0;
    int countother = 0;
    cin.ignore();
    cout << endl;
    for (int i = 0; i < user.countusers; i++) {
        if (user.sex[i] == "Nam" || user.sex[i] == "nam") {
            countmale++;
        } else if (user.sex[i] == "Nu" || user.sex[i] == "nu") {
            countfemale++;
        } else
            countother++;
    }
    cout << "Số độc giả giới tính nam  : " << countmale << endl;
    cout << "Số độc giả giới tính nữ   : " << countfemale << endl;
    cout << "Số độc giả giới tính khác : " << countother << endl;
}