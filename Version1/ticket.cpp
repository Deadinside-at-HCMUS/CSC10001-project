#include <iostream>
#include "ticket.h"
#include <ctime>
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
        default:
            return 0;
    }
}

int dayToNum(int d, int m, int y) {
    if (m < 3) {
        y--;
        m += 12;
    }
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457)/5 + d - 306;
}

void rentTicket(
        string id[MAX],
        int &countusers,
        string isbn[MAX],
        int price[MAX],
        int &countbooks,
        string rentuserid[MAX],
        string rentbookid[MAX],
        string rentday[MAX],
        string payday[MAX],
        string rentid[MAX],
        int pricerent[MAX],
        int &countrent) {
        string rentusercheck;
        string rentbookcheck;
        bool checkuserid = false;
        bool checkbookid = false;
        cout << endl;
        cout << "Lập phiếu mượn sách cho độc giả" << endl;
        cin.ignore();
        cout << "_ Mã độc giả            : "; getline(cin, rentusercheck);
        for (int i = 0; i < countusers; i++) {
            if (rentusercheck == id[i]) {
                rentuserid[countrent] = rentusercheck;
                checkuserid = true;
            }
        }
        if (!checkuserid)
            cout << "Mã độc giả không tồn tại!" << endl;
        else {
            cout << "_ Mã sách               : "; getline(cin, rentbookcheck);
            for (int i = 0; i < countbooks; i++) {
                if (rentbookcheck == isbn[i]) {
                    rentbookid[countrent] = rentbookcheck;
                    pricerent[countrent] = price[i];
                    checkbookid = true;
                }
            }
            if (!checkbookid)
                cout << "Mã sách không tồn tại!" << endl;
            else {
                cout << "_ Mã phiếu mượn         : "; getline(cin, rentid[countrent]);
                do {
                    cout << "_ Ngày mượn (yyyy/mm/dd): "; getline(cin, rentday[countrent]);
                } while (rentday[countrent].length() != 10);
                int yearrent = stoi(rentday[countrent].substr(0,4));
                int monthrent = stoi(rentday[countrent].substr(5,2));
                int dayrent = stoi(rentday[countrent].substr(8,2));
                int yearpay, monthpay, daypay;
                if (monthrent != 12 && dayrent + 6 >= dayInMonth(monthrent, yearrent)) {
                    daypay = 7 - (dayInMonth(monthrent, yearrent) - dayrent);
                    monthpay = monthrent + 1;
                    yearpay = yearrent;
                } else if (monthrent == 12 && dayrent + 6 >= dayInMonth(monthrent, yearrent)) {
                    daypay = 7 - (dayInMonth(monthrent, yearrent) - dayrent);
                    monthpay = 1;
                    yearpay = yearrent + 1;
                } else {
                    daypay = dayrent + 7;
                    monthpay = monthrent;
                    yearpay = yearrent;
                }
                if (monthpay < 10 && daypay < 10)
                    payday[countrent] = to_string(yearpay) + " 0" + to_string(monthpay) + " 0" + to_string(daypay);
                else if (monthpay < 10 && daypay > 9)
                    payday[countrent] = to_string(yearpay) + " 0" + to_string(monthpay) + " " + to_string(daypay);
                else if (monthpay > 9 && daypay < 10)
                    payday[countrent] = to_string(yearpay) + " " + to_string(monthpay) + " 0" + to_string(daypay);
                else
                    payday[countrent] = to_string(yearpay) + " " + to_string(monthpay) + " " + to_string(daypay);
                cout << "_ Ngày trả dự kiến      : " << payday[countrent] << endl;
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
        int pricerent[MAX],
        int &countrent) {
        string lostcheck;
        string rentidcheck;
        int flag;
        bool checkrentid = false;
        cout << endl;
        cout << "Lập phiếu trả sách cho độc giả" << endl;
        cin.ignore();
        cout << "Mời nhập mã phiếu mượn: "; getline(cin, rentidcheck);
        for (int i = 0; i < countrent; i++) {
            if (rentidcheck == rentid[i]) {
                rentuserid[i] = rentuserid[i+1];
                rentbookid[i] = rentbookid[i+1];
                rentday[i] = rentday[i+1];
                rentid[i] = rentid[i+1];
                countrent--;
                flag = i;
                checkrentid = true;
            }
        }
        if (!checkrentid)
            cout << "Mã phiếu mượn không tồn tại!" << endl;
        else {
            cout << "Độc giả có làm mất sách hay không? (y/n): "; getline(cin, lostcheck);
            if (lostcheck == "n") {
                time_t now = time(0);
                tm *ltm = localtime(&now);
                int todayyear = 1900 + ltm->tm_year;
                int todaymonth = 1 + ltm->tm_mon;
                int todayday = ltm->tm_mday;
                int yearpay = stoi(payday[flag].substr(0,4));
                int monthpay = stoi(payday[flag].substr(5,2));
                int daypay = stoi(payday[flag].substr(8,2));
                cout << endl;
                if (yearpay < todayyear || monthpay < todaymonth || daypay < todayday) {
                    cout << "Độc giả trả sách không đúng hạn!" << endl;
                    int todayToDay = dayToNum(todayday, todaymonth, todayyear);
                    int paydayToDay = dayToNum(daypay, monthpay, yearpay);
                    pricerent[flag] = (todayToDay - paydayToDay) * 5000;
                    cout << "Độc giả cần trả số tiền phạt là: " << pricerent[flag] << endl;
                    payday[flag] = payday[flag+1];
                    pricerent[flag] = pricerent[flag+1];
                } else {
                    cout << "Độc giả trả sách đúng hạn!" << endl;
                    payday[flag] = payday[flag+1];
                    pricerent[flag] = pricerent[flag+1];
                }
            } else {
                cout << endl;
                cout << "Độc giả làm mất sách!" << endl;
                cout << "Độc giả cần trả số tiền phạt là: " << pricerent[flag] * 2 << endl;
                payday[flag] = payday[flag+1];
                pricerent[flag] = pricerent[flag+1];
            }
        }
}

void rentedbooks(int &countrent) {
    cout << "Số lượng sách đang được mượn là: " << countrent << endl;
}

void checkduedayticket(
        string id[MAX],
        string nameuser[MAX],
        string rentuserid[MAX],
        int &countusers,
        string payday[MAX],
        int &countrent) {
        int count = 0;
        cin.ignore();
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int todayyear = 1900 + ltm->tm_year;
        int todaymonth = 1 + ltm->tm_mon;
        int todayday = ltm->tm_mday;
        cout << "Danh sách các độc giả bị trễ hạn" << endl;
        for (int i = 0; i < countrent; i++) {
            int yearpay = stoi(payday[i].substr(0,4));
            int monthpay = stoi(payday[i].substr(5,2));
            int daypay = stoi(payday[i].substr(8,2));
            if (yearpay < todayyear || monthpay < todaymonth || daypay < todayday) {
                for (int j = 0; j < countusers; j++) {
                    if (rentuserid[i] == id[j]){
                        cout << "_ Họ và tên: " << nameuser[j] << " - ID: " << id[j] << endl;
                        count++;
                    }
                }
            }
        }
        if (count == 0)
            cout << "Không có!" << endl;
}

void numrentofbooks(string namebook[MAX], string rentbookid[MAX], int &countrent) {
    int count = 0;
    cout << "Số lượt mượn của các quyển sách" << endl;
    for (int i = 0; i < countrent; i++) {
        for (int j = i; j < countrent; j++) {
            if (rentbookid[i] == rentbookid[j]) {
                count++;
            }
        }
        cout << "_ " << namebook[i] << ": " << count << endl;
        count = 0;
    }
}