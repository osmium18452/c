#include <stdio.h>
#include <string.h>

#define maxn 1000

int main() {
    int n;
    char s[maxn];
    scanf("%d",&n);
    int pos=0;
    if (n<0){
        s[pos++]='-';
        n=-n;
    }
    while (n!=0) {
        s[pos]=n%10+'0';
        pos++;
        n/=10;
    }
    strrev(s[0]=='-'?s+1:s);
    printf("%s",s);
    return 0;
}
