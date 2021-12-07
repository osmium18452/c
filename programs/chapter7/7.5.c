#include <stdio.h>
#include <string.h>

#define maxn 100

void insert(char* s1,char* s2,int pos){
    int len1=strlen(s1);
    int len2=strlen(s2);
    for (int i=len1;i>pos-1;i--){
        s1[i+len2]=s1[i];
    }
    for (int i=0;i<len2;i++){
        s1[i+pos]=s2[i];
    }
}

int main() {
    char s1[maxn],s2[maxn];
    int pos;
    scanf("%s%s%d",s1,s2,&pos);
    insert(s1,s2,pos);
    printf("%s",s1);
    return 0;
}
