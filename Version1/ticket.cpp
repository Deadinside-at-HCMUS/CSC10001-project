#include <iostream>
#include "ticket.h"
#define MAX 100

using namespace std;

int leapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        } else
            return 1;
    } else
        return 0;
}

int dayInMonth(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if (leapYear(year) == 1)
                return 29;
            else
                return 28;
            break;
    }
}

void rentTicket(
        string id[MAX],
        int &countusers,
        string isbn[MAX],
        int &countbooks,
        string rentuserid[MAX],
        string rentbookid[MAX],
        string rentday[MAX],
        string payday[MAX],
        string rentid[MAX],
        int &countrent ) {
        string rentusercheck;
        string rentbookcheck;
        bool checkuserid = false;
        bool checkbookid = false;
        cout << endl;
        cout << "Lập phiếu mượn sách cho độc giả" << endl;
        cin.ignore();
        cout << "_ Mã độc giả        : "; getline(cin, rentusercheck);
        for (int i = 0; i < countusers; i++) {
            if (rentusercheck == id[i]) {
                rentuserid[countrent] = rentusercheck;
                checkuserid = true;
            }
        }
        if (!checkuserid)
            cout << "Mã độc giả không tồn tại!" << endl;
        else {
            cout << "_ Mã sách           : "; getline(cin, rentbookcheck);
            for (int i = 0; i < countbooks; i++) {
                if (rentbookcheck == isbn[i]) {
                    rentbookid[countrent] = rentbookcheck;
                    checkbookid = true;
                }
            }
            if (!checkbookid)
                cout << "Mã sách không tồn tại!" << endl;
            else {
                cout << "_ Mã phiếu mượn     : "; getline(cin, rentid[countrent]);
                cout << "_ Ngày mượn         : "; getline(cin, rentday[countrent]);
                int yearrent = stoi(rentday[countrent].substr(0,4));
                int monthrent = stoi(rentday[countrent].substr(5,2));
                int dayrent = stoi(rentday[countrent].substr(8,2));
                int yearpay, monthpay, daypay;
                if (yearrent != 12 && dayrent + 6 == dayInMonth(monthrent, yearrent)) {
                    daypay = 1;
                    monthpay = monthrent + 1;
                    yearpay = yearrent;
                } else if (monthrent == 12 && dayrent + 6 == dayInMonth(monthrent, yearrent)) {
                    daypay = 1;
                    monthpay = 1;
                    yearpay = yearrent + 1;
                } else {
                    daypay = dayrent + 7;
                    monthpay = monthrent;
                    yearpay = yearrent;
                }
                payday[countrent] = to_string(yearpay) + ' ' + to_string(monthpay) + ' ' + to_string(daypay);
                cout << "_ Ngày trả dự kiến  : " << payday[countrent] << endl;
                countrent++;
                cout << endl;
                cout << "Độc giả mượn sách thành công!" << endl;
                cout << "Phiếu mượn của độc giả có mã là: " << rentid[countrent-1] << endl;
            }
        }
}

void returnTicket(
        string rentuserid[MAX],
        string rentbookid[MAX],
        string rentday[MAX],
        string payday[MAX],
        string rentid[MAX],
        int &countrent) {
        string rentidcheck;
        bool checkrentid = false;
        cout << endl;
        cout << "Lập phiếu trả sách cho độc giả" << endl;
        cin.ignore();
        cout << "_ Mã phiếu mượn      : "; getline(cin, rentidcheck);
        for (int i = 0; i < countrent; i++) {
            if (rentidcheck == rentid[i]) {
                rentuserid[i] = rentuserid[i+1];
                rentbookid[i] = rentbookid[i+1];
                rentday[i] = rentday[i+1];
                payday[i] = payday[i+1];
                rentid[i] = rentid[i+1];
                countrent--;
                checkrentid = true;
            }
        }
        if (!checkrentid)
            cout << "Mã phiếu mượn không tồn tại!" << endl;
        else
            cout << "Độc giả trả sách thành công!" << endl;
}

void rentedbooks(int &countrent) {
    cout << "Số lượng sách đang được mượn là: " << countrent << endl;
}

void checkdueday(string id[MAX], string nameuser[MAX], string rentuserid[MAX], int &countusers, string payday[MAX], int &countrent, string today) {
    int count = 0;
    cin.ignore();
    cout << "Mời nhập ngày tháng năm hôm nay: "; getline(cin, today);
    cout << "Danh sách các độc giả bị trễ hạn: " << endl;
    for (int i = 0; i < countrent; i++) {
        if (payday[i] < today) {
            for (int j = 0; j < countusers; j++) {
                if (rentuserid[i] == id[j]){
                    cout << "_ " << nameuser[j] << endl;
                    count++;
                }
            }
        }
    }
    if (count == 0)
        cout << "Không có!" << endl;
}