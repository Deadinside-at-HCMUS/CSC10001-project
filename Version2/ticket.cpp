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

void rentTicket(User &user, Book &book, Ticket &ticket) {
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
                do {
                    cout << "_ Ngày mượn (yyyy/mm/dd): "; getline(cin, ticket.rentday[ticket.countrent]);
                } while (ticket.rentday[ticket.countrent].length() != 10);
                int yearrent = stoi(ticket.rentday[ticket.countrent].substr(0,4));
                int monthrent = stoi(ticket.rentday[ticket.countrent].substr(5,2));
                int dayrent = stoi(ticket.rentday[ticket.countrent].substr(8,2));
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
                    ticket.payday[ticket.countrent] = to_string(yearpay) + " 0" + to_string(monthpay) + " 0" + to_string(daypay);
                else if (monthpay < 10 && daypay > 9)
                    ticket.payday[ticket.countrent] = to_string(yearpay) + " 0" + to_string(monthpay) + " " + to_string(daypay);
                else if (monthpay > 9 && daypay < 10)
                    ticket.payday[ticket.countrent] = to_string(yearpay) + " " + to_string(monthpay) + " 0" + to_string(daypay);
                else
                    ticket.payday[ticket.countrent] = to_string(yearpay) + " " + to_string(monthpay) + " " + to_string(daypay);
                cout << "_ Ngày trả dự kiến      : " << ticket.payday[ticket.countrent] << endl;
                ticket.countrent++;
                cout << endl;
                cout << "Độc giả mượn sách thành công!" << endl;
                cout << "Phiếu mượn của độc giả có mã là: " << ticket.rentid[ticket.countrent-1] << endl;
            }
        }
}

void returnTicket(User &user, Book &book, Ticket &ticket, Today today) {
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
                int yearpay = stoi(ticket.payday[flag].substr(0,4));
                int monthpay = stoi(ticket.payday[flag].substr(5,2));
                int daypay = stoi(ticket.payday[flag].substr(8,2));
                cout << endl;
                if (yearpay < today.todayyear || monthpay < today.todaymonth || daypay < today.todayday) {
                    cout << "Độc giả trả sách không đúng hạn!" << endl;
                    int todayToDay = dayToNum(today.todayday, today.todaymonth, today.todayyear);
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

void rentedbooks(Ticket &ticket) {
    cout << "Số lượng sách đang được mượn là: " << ticket.countrent << endl;
}

void checkduedayticket(User &user, Ticket &ticket, Today today) {
    int count = 0;
    cout << "Danh sách các độc giả bị trễ hạn" << endl;
    for (int i = 0; i < ticket.countrent; i++) {
        int yearpay = stoi(ticket.payday[i].substr(0,4));
        int monthpay = stoi(ticket.payday[i].substr(5,2));
        int daypay = stoi(ticket.payday[i].substr(8,2));
        if (yearpay < today.todayyear) {
            for (int j = 0; j < user.countusers; j++) {
                if (ticket.rentuserid[i] == user.id[j]){
                    cout << "_ Họ và tên: " << user.nameuser[j] << " - ID: " << user.id[j] << endl;
                    count++;
                }
            }
        } else if (yearpay == today.todayyear && monthpay < today.todaymonth) {
            for (int j = 0; j < user.countusers; j++) {
                if (ticket.rentuserid[i] == user.id[j]){
                    cout << "_ Họ và tên: " << user.nameuser[j] << " - ID: " << user.id[j] << endl;
                    count++;
                }
            }
        } else if (yearpay == today.todayyear && monthpay == today.todaymonth && daypay < today.todayday) {
            for (int j = 0; j < user.countusers; j++) {
                if (ticket.rentuserid[i] == user.id[j]){
                    cout << "_ Họ và tên: " << user.nameuser[j] << " - ID: " << user.id[j] << endl;
                    count++;
                }
            }
        }
    }
    if (count == 0)
        cout << "Trống!" << endl;;
}