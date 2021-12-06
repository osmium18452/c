#include <stdio.h>
#include <string.h>
#define maxn 1000

bool symmetric(char* s){
    int len=strlen(s);
    for (int i=0;i<len/2;i++){
        if (s[i]!=s[len-1-i]) return false;
    }
    return true;
}

int main() {
    char s[maxn];
    gets(s);
    printf("%c",symmetric(s)?'y':'n');
    return 0;
}
