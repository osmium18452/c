#include <cstdio>

int main(){
    int year,month,day;
    scanf("%d-%d-%d",&year,&month,&day);
    bool flag=(year%4==0&&year%400!=0);
    if (month==1) printf("%d",day);
    else if (month==2) printf("%d",day+31);
    else if (month==3) printf("%d",day+31+28+(flag?1:0));
    else if (month==4) printf("%d",day+31+28+31+(flag?1:0));
    else if (month==5) printf("%d",day+31+28+31+30+(flag?1:0));
    else if (month==6) printf("%d",day+31+28+31+30+31+(flag?1:0));
    else if (month==7) printf("%d",day+31+28+31+30+31+30+(flag?1:0));
    else if (month==8) printf("%d",day+31+28+31+30+31+30+31+(flag?1:0));
    else if (month==9) printf("%d",day+31+28+31+30+31+30+31+31+(flag?1:0));
    else if (month==10) printf("%d",day+31+28+31+30+31+30+31+31+30+(flag?1:0));
    else if (month==11) printf("%d",day+31+28+31+30+31+30+31+31+30+31+(flag?1:0));
    else if (month==12) printf("%d",day+31+28+31+30+31+30+31+31+30+31+30+(flag?1:0));
    return 0;
}
