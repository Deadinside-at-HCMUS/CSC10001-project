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

int dayToNum(int d, int m, int y) {
    if (m < 3) {
        y--;
        m += 12;
    }
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457)/5 + d - 306;
}

void rentTicket(User user, Book book, Ticket ticket) {
        string rentusercheck;
        string rentbookcheck;
        bool checkuserid = false;
        bool checkbookid = false;
        cout << endl;
        cout << "Lập phiếu mượn sách cho độc giả" << endl;
        cin.ignore();
        cout << "_ Mã độc giả            : "; getline(cin, rentusercheck);
        for (int i = 0; i < user.countusers; i++) {
            if (rentusercheck == user.id[i]) {
                ticket.rentuserid[ticket.countrent] = rentusercheck;
                checkuserid = true;
            }
        }
        if (!checkuserid)
            cout << "Mã độc giả không tồn tại!" << endl;
        else {
            cout << "_ Mã sách               : "; getline(cin, rentbookcheck);
            for (int i = 0; i < book.countbooks; i++) {
                if (rentbookcheck == book.isbn[i]) {
                    ticket.rentbookid[ticket.countrent] = rentbookcheck;
                    ticket.pricerent[ticket.countrent] = book.price[i];
                    checkbookid = true;
                }
            }
            if (!checkbookid)
                cout << "Mã sách không tồn tại!" << endl;
            else {
                cout << "_ Mã phiếu mượn         : "; getline(cin, ticket.rentid[ticket.countrent]);
                cout << "_ Ngày mượn (yyyy/mm/dd): "; getline(cin, ticket.rentday[ticket.countrent]);
                int yearrent = stoi(ticket.rentday[ticket.countrent].substr(0,4));
                int monthrent = stoi(ticket.rentday[ticket.countrent].substr(5,2));
                int dayrent = stoi(ticket.rentday[ticket.countrent].substr(8,2));
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
                ticket.payday[ticket.countrent] = to_string(yearpay) + ' ' + to_string(monthpay) + ' ' + to_string(daypay);
                cout << "_ Ngày trả dự kiến      : " << ticket.payday[ticket.countrent] << endl;
                ticket.countrent++;
                cout << endl;
                cout << "Độc giả mượn sách thành công!" << endl;
                cout << "Phiếu mượn của độc giả có mã là: " << ticket.rentid[ticket.countrent-1] << endl;
            }
        }
}

void returnTicket(Ticket ticket, string today) {
        string lostcheck;
        string rentidcheck;
        int flag;
        bool checkrentid = false;
        cout << endl;
        cout << "Lập phiếu trả sách cho độc giả" << endl;
        cin.ignore();
        cout << "Mời nhập mã phiếu mượn: "; getline(cin, rentidcheck);
        for (int i = 0; i < ticket.countrent; i++) {
            if (rentidcheck == ticket.rentid[i]) {
                ticket.rentuserid[i] = ticket.rentuserid[i+1];
                ticket.rentbookid[i] = ticket.rentbookid[i+1];
                ticket.rentday[i] = ticket.rentday[i+1];
                ticket.rentid[i] = ticket.rentid[i+1];
                ticket.countrent--;
                flag = i;
                checkrentid = true;
            }
        }
        if (!checkrentid)
            cout << "Mã phiếu mượn không tồn tại!" << endl;
        else {
            cout << "Độc giả có làm mất sách hay không? (y/n): "; getline(cin, lostcheck);
            if (lostcheck == "n") {
                cout << "Mời nhập ngày hôm nay (yyyy/mm/dd): "; getline(cin, today);
                cout << endl;
                if (today > ticket.payday[flag]) {
                    cout << "Độc giả trả sách không đúng hạn!" << endl;
                    int todayyear = stoi(today.substr(0,4));
                    int todaymonth = stoi(today.substr(5,2));
                    int todayday = stoi(today.substr(8,2));
                    int yearpay = stoi(ticket.payday[flag].substr(0,4));
                    int monthpay = stoi(ticket.payday[flag].substr(5,2));
                    int daypay = stoi(ticket.payday[flag].substr(8,2));
                    int todayToDay = dayToNum(todayday, todaymonth, todayyear);
                    int paydayToDay = dayToNum(daypay, monthpay, yearpay);
                    ticket.pricerent[flag] = (todayToDay - paydayToDay) * 5000;
                    cout << "Độc giả cần trả số tiền phạt là: " << ticket.pricerent[flag] << endl;
                    ticket.payday[flag] = ticket.payday[flag+1];
                    ticket.pricerent[flag] = ticket.pricerent[flag+1];
                } else {
                    cout << "Độc giả trả sách đúng hạn!" << endl;
                    ticket.payday[flag] = ticket.payday[flag+1];
                    ticket.pricerent[flag] = ticket.pricerent[flag+1];
                }
            } else {
                cout << endl;
                cout << "Độc giả làm mất sách!" << endl;
                cout << "Độc giả cần trả số tiền phạt là: " << ticket.pricerent[flag] * 2 << endl;
                ticket.payday[flag] = ticket.payday[flag+1];
                ticket.pricerent[flag] = ticket.pricerent[flag+1];
            }
        }
}

void rentedbooks(Ticket ticket) {
    cout << "Số lượng sách đang được mượn là: " << ticket.countrent << endl;
}

void checkdueday(User user, Ticket ticket, string today) {
    int count = 0;
    cin.ignore();
    cout << "Mời nhập ngày hôm nay (yyyy/mm/dd):"; getline(cin, today);
    cout << "Danh sách các độc giả bị trễ hạn" << endl;
    for (int i = 0; i < ticket.countrent; i++) {
        if (ticket.payday[i] < today) {
            for (int j = 0; j < user.countusers; j++) {
                if (ticket.rentuserid[i] == user.id[j]){
                    cout << "_ Họ và tên: " << user.nameuser[j] << " - ID: " << user.id[j] << endl;
                    count++;
                }
            }
        }
    }
    if (count == 0)
        cout << "Không có!" << endl;
}