#include <cstdio>
#include <cstring>
#include <cstdlib>
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

void rentTicket(Ticket &ticket, int &countrent) {
    char newline[100];
    fgets(newline, 100, stdin);
    printf("Lập phiếu mượn sách cho độc giả\n");
    printf("_ Mã độc giả             : ");
    fgets(ticket.rentuserid, MAX, stdin);
    strtok(ticket.rentuserid, "\n");
    printf("_ Mã sách                : ");
    fgets(ticket.rentbookid, MAX, stdin);
    strtok(ticket.rentbookid, "\n");
    printf("_ Mã phiếu mượn          : ");
    fgets(ticket.rentid, MAX, stdin);
    strtok(ticket.rentid, "\n");
    printf("_ Ngày mượn (yyyy/mm/dd) : ");
    fgets(ticket.rentday, MAX, stdin);
    strtok(ticket.rentday, "\n");
    printf("_ Ngày trả dự kiến       : ");
    fgets(ticket.payday, MAX, stdin);
    strtok(ticket.payday, "\n");
    printf("\nĐộc giả mượn sách thành công!\n");
    printf("Phiếu mượn của độc giả có mã là: %s\n", ticket.rentid);
    countrent++;
    FILE *fOut;
    fOut = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/ticket.txt", "a+");
    if (fOut != NULL) {
        fprintf(fOut, "\n%s", ticket.rentuserid);
        fprintf(fOut, " - %s", ticket.rentbookid);
        fprintf(fOut, " - %s", ticket.rentid);
        fprintf(fOut, " - %s", ticket.rentday);
        fprintf(fOut, " - %s", ticket.payday);
    }
    fclose(fOut);
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

void returnTicket(Ticket &ticket, int &countrent) {
    int position;
    int count = 0;
    int ch;
    int edited = 0;
    printf("Lập phiếu trả sách cho độc giả\n");
    printf("Mời nhập mã phiếu mượn: ");
    scanf("%d", &position);
    FILE *fIn, *fOut;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/ticket.txt", "r");
    fOut = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/ticket-edited.txt", "w");
    while((ch = fgetc(fIn)) != EOF) {
        if(ch == '\n')
            count++;
        if(count == position-1 && edited == 0) {
            if(count != 0)
                fprintf(fOut,"\n");

            edited=1;

            while((ch = fgetc(fIn)) != EOF ) {
                if(ch == '\n')
                    break;
            }
        } else
            fprintf(fOut,"%c",ch);
    }
    countrent--;
    fclose(fIn);
    fclose(fOut);
    if(edited == 1)
        printf("\nCongrates...Error Edited Successfully.");
    else
        printf("\nLine Not Found");
}

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

void rentedbooks(int &countrent) {
    int ch;
    countrent = 1;
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/ticket.txt", "r");
    while(!feof(fIn))
    {
        ch = fgetc(fIn);
        if(ch == '\n')
        {
            countrent++;
        }
    }
    fclose(fIn);
    printf("Số lượng sách đang được mượn là: %d\n", countrent);
}

void checkduedayticket(Ticket &ticket, Today today) {
    char yearpay[5], monthpay[3], daypay[3];
    char *ptr;
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/ticket.txt", "r");
    printf("\nDanh sách các độc giả bị trễ hạn:  \n");
    if (fIn != NULL) {
        while(!feof(fIn)) {
            fscanf(fIn, "%[^-] - ", ticket.rentuserid);
            fscanf(fIn, "%[^-] - ", ticket.rentbookid);
            fscanf(fIn, "%[^-] - ", ticket.rentid);
            fscanf(fIn, "%[^-] - ", ticket.rentday);
            fscanf(fIn, "%[^\n]\n", ticket.payday);
            memcpy(yearpay, &ticket.payday[0], 4);
            yearpay[4] = '\0';
            memcpy(monthpay, &ticket.payday[5], 2);
            monthpay[2] = '\0';
            memcpy(daypay, &ticket.payday[8], 2);
            daypay[2] = '\0';
            if (strtol(yearpay, &ptr, 10) < today.todayyear) {
                printf("_ Mã độc giả: %s\n", ticket.rentuserid);
            } else if (strtol(yearpay, &ptr, 10) == today.todayyear && strtol(monthpay, &ptr, 10) < today.todaymonth) {
                printf("_ Mã độc giả: %s\n", ticket.rentuserid);
            } else if (strtol(yearpay, &ptr, 10)  == today.todayyear && strtol(monthpay, &ptr, 10) == today.todaymonth && strtol(daypay, &ptr, 10) < today.todayday) {
                printf("_ Mã độc giả: %s\n", ticket.rentuserid);
            }
        }
    }
    fclose(fIn);
}

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