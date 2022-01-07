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

void rentTicket(Ticket &ticket, int &countrent) {
    char newline[MAX];
    char yearrent[5], monthrent[3], dayrent[3];
    int valueyearrent, valuemonthrent, valuedayrent;
    int yearpay, monthpay, daypay;
    char stringyearpay[5], stringmonthpay[3], stringdaypay[3];
    char *ptr;
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

    memcpy(yearrent, &ticket.rentday[0], 4);
    yearrent[4] = '\0';
    valueyearrent = strtol(yearrent, &ptr, 10);
    memcpy(monthrent, &ticket.rentday[5], 2);
    monthrent[2] = '\0';
    valuemonthrent = strtol(monthrent, &ptr, 10);
    memcpy(dayrent, &ticket.rentday[8], 2);
    dayrent[2] = '\0';
    valuedayrent = strtol(dayrent, &ptr, 10);

    if (valuemonthrent != 12 && valuedayrent + 6 >= dayInMonth(valuemonthrent, valueyearrent)) {
        daypay = 7 - (dayInMonth(valuemonthrent, valueyearrent) - valuedayrent);
        monthpay = valuemonthrent + 1;
        yearpay = valueyearrent;
    } else if (valuemonthrent == 12 && valuedayrent + 6 >= dayInMonth(valuemonthrent, valueyearrent)) {
        daypay = 7 - (dayInMonth(valuemonthrent, valueyearrent) - valuedayrent);
        monthpay = 1;
        yearpay = valueyearrent + 1;
    } else {
        daypay = valuedayrent + 7;
        monthpay = valuemonthrent;
        yearpay = valueyearrent;
    }
    sprintf(stringyearpay, "%i", yearpay);
    sprintf(stringmonthpay, "%i", monthpay);
    sprintf(stringdaypay, "%i", daypay);
    if (monthpay < 10 && daypay < 10)
        snprintf(ticket.payday, sizeof(ticket.payday), "%s 0%s 0%s", stringyearpay, stringmonthpay, stringdaypay);
    else if (monthpay < 10 && daypay > 9)
        snprintf(ticket.payday, sizeof(ticket.payday), "%s 0%s %s", stringyearpay, stringmonthpay, stringdaypay);
    else if (monthpay > 9 && daypay < 10)
        snprintf(ticket.payday, sizeof(ticket.payday), "%s %s 0%s", stringyearpay, stringmonthpay, stringdaypay);
    else
        snprintf(ticket.payday, sizeof(ticket.payday), "%s %s %s", stringyearpay, stringmonthpay, stringdaypay);

    printf("\nĐộc giả mượn sách thành công!\n");
    printf("Phiếu mượn của độc giả có mã là: %s\n", ticket.rentid);
    countrent++;
    FILE *fOut;
    fOut = fopen("ticket.txt", "a+");
    if (fOut != NULL) {
        fprintf(fOut, "\n%s", ticket.rentuserid);
        fprintf(fOut, " - %s", ticket.rentbookid);
        fprintf(fOut, " - %s", ticket.rentid);
        fprintf(fOut, " - %s", ticket.rentday);
        fprintf(fOut, " - %s", ticket.payday);
    }
    fclose(fOut);
}

void returnTicket(Ticket &ticket, int &countrent) {
    int position;
    int count = 0;
    int ch;
    int edited = 0;
    printf("Lập phiếu trả sách cho độc giả\n");
    printf("Mời nhập mã phiếu mượn: ");
    scanf("%d", &position);
    FILE *fIn, *fOut;
    fIn = fopen("ticket.txt", "r");
    fOut = fopen("ticket-edited.txt", "w");
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
        printf("\nĐộc giả trả sách thành công!\n");
    else
        printf("\nMã phiếu mượn không tồn tại!\n");
}

void rentedbooks(int &countrent) {
    int ch;
    countrent = 1;
    FILE *fIn;
    fIn = fopen("ticket-edited.txt", "r");
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
    bool isavailable = false;
    FILE *fIn;
    fIn = fopen("ticket-edited.txt", "r");
    printf("Danh sách các độc giả bị trễ hạn:  \n");
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
                isavailable = true;
            } else if (strtol(yearpay, &ptr, 10) == today.todayyear && strtol(monthpay, &ptr, 10) < today.todaymonth) {
                printf("_ Mã độc giả: %s\n", ticket.rentuserid);
                isavailable = true;
            } else if (strtol(yearpay, &ptr, 10)  == today.todayyear && strtol(monthpay, &ptr, 10) == today.todaymonth && strtol(daypay, &ptr, 10) < today.todayday) {
                printf("_ Mã độc giả: %s\n", ticket.rentuserid);
                isavailable = true;
            }
        }
    }
    fclose(fIn);
    if(!isavailable)
        printf("Trống!\n");
}