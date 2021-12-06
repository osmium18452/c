#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    for (int i=0;i<len/2;i++){
        if (s[i]!=s[len-i]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
