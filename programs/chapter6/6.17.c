#include <stdio.h>
#define maxn 1000
void remove(char* s){
    while (s[0]==' ') s++;
    int pos=0;
    while (s[pos]!='\0') pos++;
    pos--;
    while (s[pos]==' ') s[pos--]='\0';
}
int main(){
    char s[maxn];
    scanf("%s",s);
    remove(s);
    printf("%s",s);
    return 0;
}
