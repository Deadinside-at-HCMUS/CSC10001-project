#pragma once

#include <ctime>

struct Today {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char* dt = ctime(&now);
    int todayyear = 1900 + ltm->tm_year;
    int todaymonth = 1 + ltm->tm_mon;
    int todayday = ltm->tm_mday;
};
