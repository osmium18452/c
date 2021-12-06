#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 1000

char* prefix(char* s1,char*s2){
    int len=strlen(s1)>strlen(s2)?strlen(s2):strlen(s1);
    char* s=(char*) malloc((len+1)*sizeof(char));
    int pos=0;
    while (s1[pos]==s2[pos]){
        s[pos]=s1[pos];
        pos++;
    }
    s[pos]='\0';
    return s;
}

int main() {
    char s1[maxn],s2[maxn];
    gets(s1);
    gets(s2);
    printf("%s",prefix(s1,s2));
    return 0;
}
