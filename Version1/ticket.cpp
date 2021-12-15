#include <iostream>
#include "ticket.h"
#define MAX 100

using namespace std;

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
                cout << "_ Ngày mượn         : "; getline(cin, rentday[countrent]);
                cout << "_ Ngày trả dự kiến  : "; getline(cin, payday[countrent]);
                cout << "_ Mã phiếu mượn     : "; getline(cin, rentid[countrent]);
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