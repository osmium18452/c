#include<stdio.h>

int calc(int day){
    if (day==10){
        return 1;
    } else {
        return 2*calc(day+1)+2;
    }
}

int main() {
    printf("%d",calc(1));
    return 0;
}
