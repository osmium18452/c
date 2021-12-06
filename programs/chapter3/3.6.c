#include <cstdio>
#include <cstring>

char unit[]={"仟佰拾万千百十亿千百十万千百十元点角分"};
char num[]={"零壹贰叁肆伍陆柒捌玖"};
int main(){
    printf("%s",unit);
    char s[100];
    scanf("%s",s);
    int length=strlen(s);
    int pos=-1;
    for (int i=0;i<length;i++){
        if (s[i]=='.') pos=i;
        break;
    }
    if (pos>0&&pos<length-3) printf("not rmb");
    else if (pos>15||(pos==-1&&length>15)) printf("you're rich. i don't know how to express.");
    else {
        for (int i=0;i<length;i++){
            if (i==pos) continue;
            else printf("%c%c",num[s[i]-'0'],unit[17-length+pos+i]);
        }
        printf("整");
    }
    return 0;
}
