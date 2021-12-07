#include <stdio.h>

struct DATE {
    int year, month, day;

    DATE(int y, int m, int d) {
        this->year = y;
        this->month = m;
        this->day = d;
    }

    DATE() {
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }

    int getWeekDay() {
        return (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    }

    bool operator<(const DATE &a) {
        return this->year == a.year ? (this->month == a.month ? (this->day < a.day) : (this->month < a.month)) : (
                this->year < a.year);
    }

    int to_day(DATE date) {
        int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int day = 0;
        int i;
        for (i = 1; i < date.year; i++) {
            day += (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) ? 366 : 365;
        }
        if (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0) mon[2]++;
        for (i = 1; i < date.month; i++) {
            day += mon[i];
        }
        return day + date.day;
    }

    DATE to_date(int n) {
        int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year=1;
        while ((((year%4==0&&year%100!=0)||year%400==0)&&n>366)||n>365){
            year++;
            n-=(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 366 : 365;
        }
        int month=1;
        while(n>mon[month]){
            n-=mon[month];
            month++;
        }
        return DATE(year,month,n);
    }

    int operator-(const DATE &a) {
        return to_day(*this) - to_day(a);
    }

    DATE operator+(const int &a) {
        return to_date(to_day(*this)+a);
    }
};

int main() {
    DATE date(2021, 4, 5);
    DATE d2(2020, 4, 4);
    if (d2 < date) printf("%d\n", date.getWeekDay());
    printf("%d\n", date - d2);
    DATE d3=d2+10;
    printf("%d %d %d\n",d3.year,d3.month,d3.day);
    return 0;
}
