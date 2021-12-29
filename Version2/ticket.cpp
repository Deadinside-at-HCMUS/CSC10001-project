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

//void rentTicket(User &user, Book &book, Ticket &ticket) {
//        string rentusercheck;
//        string rentbookcheck;
//        bool checkuserid = false;
//        bool checkbookid = false;
//        bool checkrentid = false;
//        int flag;
//        cout << endl;
//        cout << "Lập phiếu mượn sách cho độc giả" << endl;
//        cin.ignore();
//        cout << "_ Mã độc giả             : "; getline(cin, rentusercheck);
//        for (int i = 0; i < user.countusers; i++) {
//            if (rentusercheck == user.id[i]) {
//                ticket.rentuserid[ticket.countrent] = rentusercheck;
//                checkuserid = true;
//            }
//        }
//        if (!checkuserid) {
//            cout << endl;
//            cout << "Mã độc giả không tồn tại!" << endl;
//        }
//        else {
//            cout << "_ Mã sách                : "; getline(cin, rentbookcheck);
//            for (int i = 0; i < book.countbooks; i++) {
//                if (rentbookcheck == book.isbn[i]) {
//                    ticket.rentbookid[ticket.countrent] = rentbookcheck;
//                    ticket.pricerent[ticket.countrent] = book.price[i];
//                    checkbookid = true;
//                    flag = i;
//                }
//            }
//            if (!checkbookid) {
//                cout << endl;
//                cout << "Mã sách không tồn tại!" << endl;
//            }
//            else {
//                if (book.quantity[flag] > 0) {
//                    cout << "_ Mã phiếu mượn          : "; getline(cin, ticket.rentid[ticket.countrent]);
//                    for (int i = 0; i < ticket.countrent; i++) {
//                        if (ticket.rentid[ticket.countrent] == ticket.rentid[i]) {
//                            checkrentid = true;
//                        }
//                    }
//                    if (checkrentid) {
//                        cout << endl;
//                        cout << "Mã phiếu mượn đã tồn tại!" << endl;
//                    }
//                    else {
//                        do {
//                            cout << "_ Ngày mượn (yyyy/mm/dd) : "; getline(cin, ticket.rentday[ticket.countrent]);
//                        } while (ticket.rentday[ticket.countrent].length() != 10);
//                        int yearrent = stoi(ticket.rentday[ticket.countrent].substr(0,4));
//                        int monthrent = stoi(ticket.rentday[ticket.countrent].substr(5,2));
//                        int dayrent = stoi(ticket.rentday[ticket.countrent].substr(8,2));
//                        int yearpay, monthpay, daypay;
//                        if (monthrent != 12 && dayrent + 6 >= dayInMonth(monthrent, yearrent)) {
//                            daypay = 7 - (dayInMonth(monthrent, yearrent) - dayrent);
//                            monthpay = monthrent + 1;
//                            yearpay = yearrent;
//                        } else if (monthrent == 12 && dayrent + 6 >= dayInMonth(monthrent, yearrent)) {
//                            daypay = 7 - (dayInMonth(monthrent, yearrent) - dayrent);
//                            monthpay = 1;
//                            yearpay = yearrent + 1;
//                        } else {
//                            daypay = dayrent + 7;
//                            monthpay = monthrent;
//                            yearpay = yearrent;
//                        }
//                        if (monthpay < 10 && daypay < 10)
//                            ticket.payday[ticket.countrent] = to_string(yearpay) + " 0" + to_string(monthpay) + " 0" + to_string(daypay);
//                        else if (monthpay < 10 && daypay > 9)
//                            ticket.payday[ticket.countrent] = to_string(yearpay) + " 0" + to_string(monthpay) + " " + to_string(daypay);
//                        else if (monthpay > 9 && daypay < 10)
//                            ticket.payday[ticket.countrent] = to_string(yearpay) + " " + to_string(monthpay) + " 0" + to_string(daypay);
//                        else
//                            ticket.payday[ticket.countrent] = to_string(yearpay) + " " + to_string(monthpay) + " " + to_string(daypay);
//                        cout << "_ Ngày trả dự kiến       : " << ticket.payday[ticket.countrent] << endl;
//                        ticket.countrent++;
//                        book.quantity[flag]--;
//                        cout << endl;
//                        cout << "Độc giả mượn sách thành công!" << endl;
//                        cout << "Phiếu mượn của độc giả có mã là: " << ticket.rentid[ticket.countrent-1] << endl;
//                    }
//                } else {
//                    cout << endl;
//                    cout << "Sách " << book.namebook[flag] <<  " đã được mượn hết!" << endl;
//                }
//            }
//        }
//}

//void returnTicket(User &user, Book &book, Ticket &ticket, Today today) {
//        string lostcheck;
//        string rentidcheck;
//        int flag;
//        bool checkrentid = false;
//        cout << endl;
//        cout << "Lập phiếu trả sách cho độc giả" << endl;
//        cin.ignore();
//        cout << "Mời nhập mã phiếu mượn: "; getline(cin, rentidcheck);
//        for (int i = 0; i < ticket.countrent; i++) {
//            if (rentidcheck == ticket.rentid[i]) {
//                flag = i;
//                checkrentid = true;
//            }
//        }
//        if (!checkrentid)
//            cout << "Mã phiếu mượn không tồn tại!" << endl;
//        else {
//            cout << "Độc giả có làm mất sách hay không? (y/n): "; getline(cin, lostcheck);
//            if (lostcheck == "n") {
//                time_t now = time(0);
//                tm *ltm = localtime(&now);
//                int todayyear = 1900 + ltm->tm_year;
//                int todaymonth = 1 + ltm->tm_mon;
//                int todayday = ltm->tm_mday;
//                int yearpay = stoi(ticket.payday[flag].substr(0,4));
//                int monthpay = stoi(ticket.payday[flag].substr(5,2));
//                int daypay = stoi(ticket.payday[flag].substr(8,2));
//                cout << endl;
//                if (yearpay < todayyear || monthpay < todaymonth || daypay < todayday) {
//                    cout << "Độc giả trả sách không đúng hạn!" << endl;
//                    int todayToDay = dayToNum(todayday, todaymonth, todayyear);
//                    int paydayToDay = dayToNum(daypay, monthpay, yearpay);
//                    ticket.pricerent[flag] = (todayToDay - paydayToDay) * 5000;
//                    cout << "Độc giả cần trả số tiền phạt là: " << ticket.pricerent[flag] << " VNĐ" << endl;
//                } else {
//                    cout << "Độc giả trả sách đúng hạn!" << endl;
//                }
//            } else {
//                cout << endl;
//                cout << "Độc giả làm mất sách!" << endl;
//                cout << "Độc giả cần trả số tiền phạt là: " << ticket.pricerent[flag] * 2 << " VNĐ" << endl;
//            }
//            for (int i = 0; i < book.countbooks; i++) {
//                if (ticket.rentbookid[flag] == book.isbn[i]) {
//                    book.quantity[i]++;
//                }
//            }
//            ticket.rentuserid[flag] = ticket.rentuserid[flag+1];
//            ticket.rentbookid[flag] = ticket.rentbookid[flag+1];
//            ticket.rentday[flag] = ticket.rentday[flag+1];
//            ticket.payday[flag] = ticket.payday[flag+1];
//            ticket.rentid[flag] = ticket.rentid[flag+1];
//            ticket.pricerent[flag] = ticket.pricerent[flag+1];
//            ticket.countrent--;
//        }
//}

//void rentedbooks(Ticket &ticket) {
//    cout << "Số lượng sách đang được mượn là: " << ticket.countrent << endl;
//}

//void checkduedayticket(User &user, Ticket &ticket, Today today) {
//    int count = 0;
//    cout << "Danh sách các độc giả bị trễ hạn: " << endl;
//    for (int i = 0; i < ticket.countrent; i++) {
//        int yearpay = stoi(ticket.payday[i].substr(0,4));
//        int monthpay = stoi(ticket.payday[i].substr(5,2));
//        int daypay = stoi(ticket.payday[i].substr(8,2));
//        if (yearpay < today.todayyear) {
//            for (int j = 0; j < user.countusers; j++) {
//                if (ticket.rentuserid[i] == user.id[j]){
//                    cout << "_ Họ và tên: " << user.nameuser[j] << " - ID: " << user.id[j] << endl;
//                    count++;
//                }
//            }
//        } else if (yearpay == today.todayyear && monthpay < today.todaymonth) {
//            for (int j = 0; j < user.countusers; j++) {
//                if (ticket.rentuserid[i] == user.id[j]){
//                    cout << "_ Họ và tên: " << user.nameuser[j] << " - ID: " << user.id[j] << endl;
//                    count++;
//                }
//            }
//        } else if (yearpay == today.todayyear && monthpay == today.todaymonth && daypay < today.todayday) {
//            for (int j = 0; j < user.countusers; j++) {
//                if (ticket.rentuserid[i] == user.id[j]){
//                    cout << "_ Họ và tên: " << user.nameuser[j] << " - ID: " << user.id[j] << endl;
//                    count++;
//                }
//            }
//        }
//    }
//    if (count == 0) {
//        cout << endl;
//        cout << "Trống!" << endl;;
//    }
//}