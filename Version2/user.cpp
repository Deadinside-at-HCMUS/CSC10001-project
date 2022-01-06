#include <cstdio>
#include <cstring>
#include "user.h"
#define MAX 100

using namespace std;

void showUsers(User user, int &countusers) {
    countusers = 0;
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "r");
    if (fIn != NULL) {
        while(!feof(fIn)) {
            printf("Thông tin của độc gỉả thứ %d\n", countusers + 1);
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
            countusers++;
        }
    }
    printf("%d", countusers);
    fclose(fIn);
}

void addUser(User &user, int &countusers) {
    char newline[100];
    fgets(newline, 100, stdin);
    printf("Thêm thông tin độc giả thứ %d\n", countusers + 1);
    printf("_ Mã độc giả          : "); fgets(user.id, MAX, stdin);
    strtok(user.id, "\n");
    printf("_ Họ tên              : "); fgets(user.nameuser, MAX, stdin);
    strtok(user.nameuser, "\n");
    printf("_ CMND                : "); fgets(user.cmnd, MAX, stdin);
    strtok(user.cmnd, "\n");
    printf("_ Ngày tháng năm sinh : "); fgets(user.birthday, MAX, stdin);
    strtok(user.birthday, "\n");
    printf("_ Giới tính           : "); fgets(user.sex, MAX, stdin);
    strtok(user.sex, "\n");
    printf("_ Email               : "); fgets(user.email, MAX, stdin);
    strtok(user.email, "\n");
    printf("_ Địa chỉ             : "); fgets(user.address, MAX, stdin);
    strtok(user.address, "\n");
    printf("_ Ngày lập thẻ        : "); fgets(user.createday, MAX, stdin);
    strtok(user.createday, "\n");
    printf("_ Ngày hết hạn thẻ    : "); fgets(user.dueday, MAX, stdin);
    strtok(user.dueday, "\n");
    countusers++;
    FILE *fOut;
    fOut = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "a+");
    if(fOut != NULL) {
        fprintf(fOut, "\n%s", user.id);
        fprintf(fOut, " - %s", user.nameuser);
        fprintf(fOut, " - %s", user.cmnd);
        fprintf(fOut, " - %s", user.birthday);
        fprintf(fOut, " - %s", user.sex);
        fprintf(fOut, " - %s", user.email);
        fprintf(fOut, " - %s", user.address);
        fprintf(fOut, " - %s", user.createday);
        fprintf(fOut, " - %s", user.dueday);
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

void modifyUser(User &user) {
    char newline[100];
    int position;
    int count = 0;
    int ch;
    int edited = 0;
    printf("Mời nhập stt độc giả cần chỉnh sửa: ");
    scanf("%d", &position);
    printf("%d\n", position);
    FILE *fIn, *fOut;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "r");
    fOut = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user-edited.txt", "w");
    while((ch = fgetc(fIn)) != EOF) {
        if(ch == '\n')
            count++;
        if(count == position-1 && edited == 0) {
            fgets(newline, 100, stdin);
            printf("_ Mã độc giả          : "); fgets(user.id, MAX, stdin);
            strtok(user.id, "\n");
            printf("_ Họ tên              : "); fgets(user.nameuser, MAX, stdin);
            strtok(user.nameuser, "\n");
            printf("_ CMND                : "); fgets(user.cmnd, MAX, stdin);
            strtok(user.cmnd, "\n");
            printf("_ Ngày tháng năm sinh : "); fgets(user.birthday, MAX, stdin);
            strtok(user.birthday, "\n");
            printf("_ Giới tính           : "); fgets(user.sex, MAX, stdin);
            strtok(user.sex, "\n");
            printf("_ Email               : "); fgets(user.email, MAX, stdin);
            strtok(user.email, "\n");
            printf("_ Địa chỉ             : "); fgets(user.address, MAX, stdin);
            strtok(user.address, "\n");
            printf("_ Ngày lập thẻ        : "); fgets(user.createday, MAX, stdin);
            strtok(user.createday, "\n");
            printf("_ Ngày hết hạn thẻ    : "); fgets(user.dueday, MAX, stdin);
            strtok(user.dueday, "\n");

            if(count == 0) {
                fprintf(fOut, "%s", user.id);
                fprintf(fOut, " - %s", user.nameuser);
                fprintf(fOut, " - %s", user.cmnd);
                fprintf(fOut, " - %s", user.birthday);
                fprintf(fOut, " - %s", user.sex);
                fprintf(fOut, " - %s", user.email);
                fprintf(fOut, " - %s", user.address);
                fprintf(fOut, " - %s", user.createday);
                fprintf(fOut, " - %s", user.dueday);
                fprintf(fOut,"\n");
            }
            else {
                fprintf(fOut, "\n%s", user.id);
                fprintf(fOut, " - %s", user.nameuser);
                fprintf(fOut, " - %s", user.cmnd);
                fprintf(fOut, " - %s", user.birthday);
                fprintf(fOut, " - %s", user.sex);
                fprintf(fOut, " - %s", user.email);
                fprintf(fOut, " - %s", user.address);
                fprintf(fOut, " - %s", user.createday);
                fprintf(fOut, " - %s", user.dueday);
                fprintf(fOut,"\n");
            }
            edited=1;

            while( (ch=fgetc(fIn))!=EOF ) {
                if(ch=='\n')
                    break;
            }
        } else {
            fprintf(fOut,"%c",ch);
        }
    }
    fclose(fIn);
    fclose(fOut);
    if(edited==1)
        printf("\nCongrates...Error Edited Successfully.");
    else
        printf("\nLine Not Found");
}

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

void deleteUser(User &user, int &countusers) {
    int position;
    int count = 0;
    int ch;
    int edited = 0;
    printf("Mời nhập stt độc giả cần xóa: ");
    scanf("%d", &position);
    FILE *fIn, *fOut;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "r");
    fOut = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user-edited.txt", "w");
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
    countusers--;
    fclose(fIn);
    fclose(fOut);
    if(edited == 1)
        printf("\nCongrates...Error Edited Successfully.");
    else
        printf("\nLine Not Found");
}

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

void findUserByCMND(User &user) {
    char cmndcheck[100];
    char temp[100];
    char line[100];
    char newline[100];
    int position;
    int ch;
    int count = 0;
    fgets(newline, 100, stdin);
    printf("Mời nhập CMND độc giả cần tìm: "); fgets(cmndcheck, MAX, stdin);
    strtok(cmndcheck, "\n");
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "r");
    if (fIn != NULL) {
        while (!feof(fIn)) {
            ch = fgetc(fIn);
            if(ch == '\n')
            {
                count++;
            }
            fscanf(fIn, "%s", temp);
            if (strcmp(temp, cmndcheck) == 0) {
                position = count;
                count = 0;
                break;
            }
        }
    }
    fclose(fIn);
    FILE *fInNew;
    fInNew = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "r");
    if (fInNew != NULL) {
        while (!feof(fInNew)) {
            ch = fgetc(fInNew);
            if(ch == '\n')
            {
                count++;
            }
            fscanf(fInNew, "%[^\n]", line);
            if (count == position) {
                printf("%s\n", line);
            }
        }
    }
    fclose(fInNew);
}

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

void findUsersByName(User &user) {
    char namecheck[100];
    char temp[100];
    char line[100];
    char newline[100];
    int position;
    int ch;
    int count = 0;
    fgets(newline, 100, stdin);
    printf("Mời nhập tên độc giả cần tìm: "); fgets(namecheck, MAX, stdin);
    strtok(namecheck, "\n");
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "r");
    if (fIn != NULL) {
        while (!feof(fIn)) {
            count++;
            fscanf(fIn, "%[^-] - ", temp);
            if (strcmp(temp, namecheck) == 0) {
                position = count/9;
                count = 0;
                break;
            }
        }
    }
    fclose(fIn);
    FILE *fInNew;
    fInNew = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user.txt", "r");
    if (fInNew != NULL) {
        while (!feof(fInNew)) {
            ch = fgetc(fInNew);
            if(ch == '\n')
            {
                count++;
            }
            fscanf(fInNew, "%[^\n]", line);
            if (count == position) {
                printf("%s\n", line);
            }
        }
    }
    fclose(fInNew);
}

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

void quantityusers(int countusers) {
    printf("Số lượng độc giả hiện có là: %d\n", countusers);
}

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
//