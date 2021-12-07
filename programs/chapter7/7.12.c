#include <stdio.h>
#include <string.h>

char s[] = "a;lksd\0jflkdjla \0fldas;jfdhfsad;f dljas\0jdsa jlf laskfjl\0sdflsadf sdaj fl\0asdjkf\0";
char *p[100];

int find() {
    int len=sizeof(s);
    char* pos=s;
    int cnt=0;
    for (int i=0;i<len;i++){
        if (s[i]=='\0') p[cnt++]=pos,pos=s+i+1;
    }
    return cnt;
}

int main() {
    int cnt=find();
    for (int i=0;i<cnt;i++){
        printf("%s\n",p[i]);
    }
    return 0;
}
