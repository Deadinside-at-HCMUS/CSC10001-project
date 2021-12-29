#include <stdio.h>
#include "user.h"
#define MAX 100

using namespace std;

void showUsers(User user) {
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "r");
    if (fIn != NULL) {
        fscanf(fIn, "%d\n", &user.countusers);
        if (user.countusers == 0) {
            printf("Danh sách độc giả trống!\n");
        } else {
            for (int i = 0; i < user.countusers + 1; i++) {
                printf("Thông tin của độc gỉả thứ %d\n", i);
                fscanf(fIn, "%[^-] - ", user.id);
                fscanf(fIn, "%[^-] - ", user.nameuser);
                fscanf(fIn, "%[^-] - ", user.cmnd);
                fscanf(fIn, "%[^-] - ", user.birthday);
                fscanf(fIn, "%[^-] - ", user.sex);
                fscanf(fIn, "%[^-] - ", user.email);
                fscanf(fIn, "%[^-] - ", user.address);
                fscanf(fIn, "%[^-] - ", user.createday);
                fscanf(fIn, "%[^\n]\n", user.dueday);
                printf("_ Mã độc giả          : %s\n", user.id);
                printf("_ Họ tên              : %s\n", user.nameuser);
                printf("_ CMND                : %s\n", user.cmnd);
                printf("_ Ngày tháng năm sinh : %s\n", user.birthday);
                printf("_ Giới tính           : %s\n", user.sex);
                printf("_ Email               : %s\n", user.email);
                printf("_ Địa chỉ             : %s\n", user.address);
                printf("_ Ngày lập thẻ        : %s\n", user.createday);
                printf("_ Ngày hết hạn thẻ    : %s\n", user.dueday);
                printf("\n");
            }
        }
    }
    fclose(fIn);
}

void addUser(User &user) {
    char test[MAX] = "hello there";
    FILE *fOut;
    fOut = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "a+");
    if(fOut != NULL) {
        fscanf(fOut, "%d\n", &user.countusers);
        printf("Thêm thông tin độc giả thứ %d\n", user.countusers+1);
        printf("_ Mã độc giả                : "); scanf("%s", user.id);
        printf("%s", user.id);
        fprintf(fOut, "%s", test);
    } else {
        printf("Cannot open the file");
    }
    fclose(fOut);
}

//void addUser(User &user) {
//        int i = user.countusers;
//        bool checkid = false;
//        cout << "Thêm thông tin độc giả thứ " << i + 1 << endl;
//        cin.ignore();
//        cout << "_ Mã độc giả                : "; getline(cin, user.id[i]);
//        for (int j = 0; j < i; j++) {
//            if (user.id[j] == user.id[i]) {
//                checkid = true;
//            }
//        }
//        if (checkid) {
//            cout << endl;
//            cout << "Mã độc giả đã tồn tại!" << endl;
//        } else {
//            cout << "_ Họ tên                    : "; getline(cin, user.nameuser[i]);
//            cout << "_ CMND                      : "; getline(cin, user.cmnd[i]);
//            do {
//                cout << "_ Ngày tháng năm sinh       : "; getline(cin, user.birthday[i]);
//            } while (user.birthday[i].length() != 10);
//            cout << "_ Giới tính                 : "; getline(cin, user.sex[i]);
//            cout << "_ Email                     : "; getline(cin, user.email[i]);
//            cout << "_ Địa chỉ                   : "; getline(cin, user.address[i]);
//            do {
//                cout << "_ Ngày lập thẻ (yyyy/mm/dd) : "; getline(cin, user.createday[i]);
//            } while (user.createday[i].length() != 10);
//            string yearcreate = user.createday[i].substr(0,4);
//            string monthdaycreate = user.createday[i].substr(4,6);
//            int numdueyear = stoi(yearcreate) + 4;
//            user.dueday[i] = to_string(numdueyear) + monthdaycreate;
//            user.countusers++;
//        }
//}

//void modifyUser(User &user){
//        int i;
//        bool checkid = false;
//        if (user.countusers == 0) {
//            cout << "Danh sách độc giả trống!" << endl;
//        } else {
//            cout << "Mời nhập stt độc giả cần chỉnh sửa: "; cin >> i;
//            cout << endl;
//            if (user.countusers< i) {
//                cout << "Stt độc giả lớn hơn danh sách độc giả hiện có!" << endl;
//            } else {
//                cout << "Chỉnh sửa thông tin độc giả thứ " << i << endl;
//                cin.ignore();
//                cout << "_ Mã độc giả                : "; getline(cin, user.id[i-1]);
//                for (int j = 0; j < i - 1; j++) {
//                    if (user.id[j] == user.id[i-1]) {
//                        checkid = true;
//                    }
//                }
//                if (checkid) {
//                    cout << endl;
//                    cout << "Mã độc giả đã tồn tại!" << endl;
//                } else {
//                    cout << "_ Họ tên                    : "; getline(cin, user.nameuser[i-1]);
//                    cout << "_ CMND                      : "; getline(cin, user.cmnd[i-1]);
//                    do {
//                        cout << "_ Ngày tháng năm sinh       : "; getline(cin, user.birthday[i-1]);
//                    } while (user.birthday[i-1].length() != 10);
//                    cout << "_ Giới tính                 : "; getline(cin, user.sex[i-1]);
//                    cout << "_ Email                     : "; getline(cin, user.email[i-1]);
//                    cout << "_ Địa chỉ                   : "; getline(cin, user.address[i-1]);
//                    do {
//                        cout << "_ Ngày lập thẻ (yyyy/mm/dd) : "; getline(cin, user.createday[i-1]);
//                    } while (user.createday[i-1].length() != 10);
//                }
//            }
//        }
//}

//void deleteUser(User &user) {
//        int i;
//        cout << "Mời nhập stt độc giả cần xóa: "; cin >> i;
//        cout << endl;
//        user.id[i-1] = user.id[i];
//        user.nameuser[i-1] = user.nameuser[i];
//        user.cmnd[i-1] = user.cmnd[i];
//        user.birthday[i-1] = user.birthday[i];
//        user.sex[i-1] = user.sex[i];
//        user.email[i-1] = user.email[i];
//        user.address[i-1] = user.address[i];
//        user.createday[i-1] = user.createday[i];
//        user.dueday[i-1] = user.dueday[i];
//        user.countusers--;
//        cout << "Độc giả thứ " << i << " đã được xóa!" << endl;
//}

//void findUserByCMND(User &user) {
//        string cmndcheck;
//        bool isavailable = false;
//        cin.ignore();
//        cout << "Mời nhập CMND độc giả cần tìm: "; getline(cin, cmndcheck);
//        cout << endl;
//        for (int i = 0; i < user.countusers; i++) {
//            if (cmndcheck == user.cmnd[i]) {
//                cout << "Thông tin của độc gỉả thứ " << i + 1 << endl;
//                cout << "_ Mã độc giả          : " << user.id[i] << endl;
//                cout << "_ Họ tên              : " << user.nameuser[i] << endl;
//                cout << "_ CMND                : " << user.cmnd[i] << endl;
//                cout << "_ Ngày tháng năm sinh : " << user.birthday[i] << endl;
//                cout << "_ Giới tính           : " << user.sex[i] << endl;
//                cout << "_ Email               : " << user.email[i] << endl;
//                cout << "_ Địa chỉ             : " << user.address[i] << endl;
//                cout << "_ Ngày lập thẻ        : " << user.createday[i] << endl;
//                cout << "_ Ngày hết hạn thẻ    : " << user.dueday[i] << endl;
//                isavailable = true;
//            }
//        }
//        if (!isavailable)
//            cout << "Độc giả có CMND " << cmndcheck << " không tồn tại!" << endl;
//}

//void findUsersByName(User &user) {
//        string nameusercheck;
//        bool isavailable = false;
//        cin.ignore();
//        cout << "Mời nhập tên độc giả cần tìm: "; getline(cin,nameusercheck);
//        cout << endl;
//        for (int i = 0; i < user.countusers; i++) {
//            if (nameusercheck == user.nameuser[i]) {
//                cout << "Thông tin của độc gỉả thứ " << i + 1 << endl;
//                cout << "_ Mã độc giả          : " << user.id[i] << endl;
//                cout << "_ Họ tên              : " << user.nameuser[i] << endl;
//                cout << "_ CMND                : " << user.cmnd[i] << endl;
//                cout << "_ Ngày tháng năm sinh : " << user.birthday[i] << endl;
//                cout << "_ Giới tính           : " << user.sex[i] << endl;
//                cout << "_ Email               : " << user.email[i] << endl;
//                cout << "_ Địa chỉ             : " << user.address[i] << endl;
//                cout << "_ Ngày lập thẻ        : " << user.createday[i] << endl;
//                cout << "_ Ngày hết hạn thẻ    : " << user.dueday[i] << endl;
//                isavailable = true;
//            }
//        }
//        if (!isavailable)
//            cout << "Độc giả có tên " << nameusercheck << " không tồn tại!" << endl;
//}

//void quantityusers(User &user) {
//    cout << "Số lượng độc giả hiện có là: " << user.countusers << endl;
//}

//void sexusers(User &user) {
//    int countmale = 0;
//    int countfemale = 0;
//    int countother = 0;
//    cin.ignore();
//    for (int i = 0; i < user.countusers; i++) {
//        if (user.sex[i] == "Nam" || user.sex[i] == "nam") {
//            countmale++;
//        } else if (user.sex[i] == "Nu" || user.sex[i] == "nu") {
//            countfemale++;
//        } else
//            countother++;
//    }
//    cout << "Số độc giả giới tính nam  : " << countmale << endl;
//    cout << "Số độc giả giới tính nữ   : " << countfemale << endl;
//    cout << "Số độc giả giới tính khác : " << countother << endl;
//}

//void checkduedayuser(User &user, Today today) {
//    int count = 0;
//    cout << "Danh sách các độc giả hết hạn thẻ: " << endl;
//    for (int i = 0; i < user.countusers; i++) {
//        int yearpay = stoi(user.dueday[i].substr(0,4));
//        int monthpay = stoi(user.dueday[i].substr(5,2));
//        int daypay = stoi(user.dueday[i].substr(8,2));
//        if (yearpay < today.todayyear) {
//            cout << "_ Họ và tên: " << user.nameuser[i] << " - ID: " << user.id[i] << endl;
//            count++;
//        } else if (yearpay == today.todayyear && monthpay < today.todaymonth) {
//            cout << "_ Họ và tên: " << user.nameuser[i] << " - ID: " << user.id[i] << endl;
//            count++;
//        } else if (yearpay == today.todayyear && monthpay == today.todaymonth && daypay < today.todayday) {
//            cout << "_ Họ và tên: " << user.nameuser[i] << " - ID: " << user.id[i] << endl;
//            count++;
//        }
//    }
//    if (count == 0)
//        cout << "Trống!" << endl;
//}