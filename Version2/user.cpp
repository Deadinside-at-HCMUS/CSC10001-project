#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
    fclose(fIn);
}

void addUser(User &user, int &countusers) {
    char newline[MAX];
    char yearcreate[5], monthdaycreate[7];
    int valueyearcreate, yeardue;
    char stringyeardue[5];
    char *ptr;
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

    memcpy(yearcreate, &user.createday[0], 4);
    yearcreate[4] = '\0';
    valueyearcreate = strtol(yearcreate, &ptr, 10);
    memcpy(monthdaycreate, &user.createday[4], 6);
    monthdaycreate[6] = '\0';
    yeardue = valueyearcreate + 4;
    sprintf(stringyeardue, "%i", yeardue);
    snprintf(user.dueday, sizeof(user.dueday), "%s%s", stringyeardue, monthdaycreate);

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

void modifyUser(User &user) {
    char newline[MAX];
    int position;
    int count = 0;
    int ch;
    int edited = 0;
    char yearcreate[5], monthdaycreate[7];
    int valueyearcreate, yeardue;
    char stringyeardue[5];
    char *ptr;
    printf("Mời nhập stt độc giả cần chỉnh sửa: ");
    scanf("%d", &position);
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

            memcpy(yearcreate, &user.createday[0], 4);
            yearcreate[4] = '\0';
            valueyearcreate = strtol(yearcreate, &ptr, 10);
            memcpy(monthdaycreate, &user.createday[4], 6);
            monthdaycreate[6] = '\0';
            yeardue = valueyearcreate + 4;
            sprintf(stringyeardue, "%i", yeardue);
            snprintf(user.dueday, sizeof(user.dueday), "%s%s", stringyeardue, monthdaycreate);

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
        printf("\nChỉnh sửa thông tin độc giả thành công!\n");
    else
        printf("\nSTT độc giả không tồn tại!\n");
}

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
        printf("\nXóa độc giả thành công!\n");
    else
        printf("\nSTT độc giả không tồn tại!\n");
}

void findUserByCMND(User &user) {
    char cmndcheck[MAX];
    char temp[MAX];
    char line[MAX];
    char newline[MAX];
    int position;
    int ch;
    int count = 0;
    bool isavailable = false;
    fgets(newline, 100, stdin);
    printf("Mời nhập CMND độc giả cần tìm: "); fgets(cmndcheck, MAX, stdin);
    strtok(cmndcheck, "\n");
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user-edited.txt", "r");
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
                isavailable = true;
                break;
            }
        }
    }
    fclose(fIn);

    if(isavailable) {
        FILE *fInNew;
        fInNew = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user-edited.txt", "r");
        if (fInNew != NULL) {
            while (!feof(fInNew)) {
                ch = fgetc(fInNew);
                if(ch == '\n')
                {
                    count++;
                }
                fscanf(fInNew, "%[^\n]", line);
                if (count == position) {
                    printf("\nThông tin của độc gỉả cần tìm: \n");
                    printf("%s\n", line);
                }
            }
        }
        fclose(fInNew);
    } else
        printf("Độc giả có CMND %s không tồn tại!\n", cmndcheck);
}

void findUsersByName(User &user) {
    char namecheck[MAX];
    char temp[MAX];
    char line[MAX];
    char newline[MAX];
    int position;
    int ch;
    int count = 0;
    bool isavailable = false;
    fgets(newline, 100, stdin);
    printf("Mời nhập tên độc giả cần tìm: "); fgets(namecheck, MAX, stdin);
    strtok(namecheck, "\n");
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user-edited.txt", "r");
    if (fIn != NULL) {
        while (!feof(fIn)) {
            count++;
            fscanf(fIn, "%[^-] - ", temp);
            if (strcmp(temp, namecheck) == 0) {
                position = round((count-2)/9) + 1;
                count = 0;
                isavailable = true;
                break;
            }
        }
    }
    fclose(fIn);

    if (isavailable) {
        FILE *fInNew;
        fInNew = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user-edited.txt", "r");
        if (fInNew != NULL) {
            while (!feof(fInNew)) {
                ch = fgetc(fInNew);
                if(ch == '\n')
                {
                    count++;
                }
                fscanf(fInNew, "%[^\n]", line);
                if (count == position) {
                    printf("\nThông tin của độc gỉả cần tìm: \n");
                    printf("%s\n", line);
                }
            }
        }
        fclose(fInNew);
    } else {
        printf("Độc giả có tên %s không tồn tại!\n", namecheck);
    }
}

void quantityusers(int countusers) {
    printf("Số lượng độc giả hiện có là: %d\n", countusers);
}

void sexusers(User &user) {
    int countmale = 0;
    int countfemale = 0;
    int countother = 0;
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user-edited.txt", "r");
    if (fIn != NULL) {
        while(!feof(fIn)) {
            fscanf(fIn, "%[^-] - ", user.id);
            fscanf(fIn, "%[^-] - ", user.nameuser);
            fscanf(fIn, "%[^-] - ", user.cmnd);
            fscanf(fIn, "%[^-] - ", user.birthday);
            fscanf(fIn, "%[^-] - ", user.sex);
            fscanf(fIn, "%[^-] - ", user.email);
            fscanf(fIn, "%[^-] - ", user.address);
            fscanf(fIn, "%[^-] - ", user.createday);
            fscanf(fIn, "%[^\n]\n", user.dueday);
            if (strcmp(user.sex, "Nam ") == 0 || strcmp(user.sex, "nam ") == 0) {
                countmale++;
            } else if (strcmp(user.sex, "Nu ") == 0 || strcmp(user.sex, "nu ") == 0) {
                countfemale++;
            } else
                countother++;
        }
    }
    fclose(fIn);
    printf("Số độc giả giới tính nam  : %d\n", countmale);
    printf("Số độc giả giới tính nữ  : %d\n", countfemale);
    printf("Số độc giả giới tính khác  : %d\n", countother);
}

void checkduedayuser(User &user, Today today) {
    char yearpay[5], monthpay[3], daypay[3];
    char *ptr;
    bool isavailable = false;
    FILE *fIn;
    fIn = fopen("/home/jasminele/Workspace/University/Final Project/NMLT-Library/Version2/user-edited.txt", "r");
    printf("Danh sách các độc giả hết hạn thẻ: \n");
    if (fIn != NULL) {
        while(!feof(fIn)) {
            fscanf(fIn, "%[^-] - ", user.id);
            fscanf(fIn, "%[^-] - ", user.nameuser);
            fscanf(fIn, "%[^-] - ", user.cmnd);
            fscanf(fIn, "%[^-] - ", user.birthday);
            fscanf(fIn, "%[^-] - ", user.sex);
            fscanf(fIn, "%[^-] - ", user.email);
            fscanf(fIn, "%[^-] - ", user.address);
            fscanf(fIn, "%[^-] - ", user.createday);
            fscanf(fIn, "%[^\n]\n", user.dueday);
            memcpy(yearpay, &user.dueday[0], 4);
            yearpay[4] = '\0';
            memcpy(monthpay, &user.dueday[5], 2);
            monthpay[2] = '\0';
            memcpy(daypay, &user.dueday[8], 2);
            daypay[2] = '\0';
            if (strtol(yearpay, &ptr, 10) < today.todayyear) {
                printf("_ %s- %s\n", user.id, user.nameuser);
                isavailable = true;
            } else if (strtol(yearpay, &ptr, 10) == today.todayyear && strtol(monthpay, &ptr, 10) < today.todaymonth) {
                printf("_ %s- %s\n", user.id, user.nameuser);
                isavailable = true;
            } else if (strtol(yearpay, &ptr, 10)  == today.todayyear && strtol(monthpay, &ptr, 10) == today.todaymonth && strtol(daypay, &ptr, 10) < today.todayday) {
                printf("_ %s- %s\n", user.id, user.nameuser);
                isavailable = true;
            }
        }
    }
    fclose(fIn);
    if(!isavailable)
        printf("Trống!\n");
}