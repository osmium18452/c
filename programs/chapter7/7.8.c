#include <stdio.h>
#include <string.h>

int match(char *s1, char *s2) {
    int ans = 0;
    int len = strlen(s2);
    while (*s1) {
        for (int i = 0; i<len;i++){
            if (s1[i]!=s2[i]) break;
            if (s1[i]=='\0') return ans;
            if (i==len-1) ans++;
        }
        s1++;
    }
    return ans;
}

int main() {
    char s1[100],s2[100];
    scanf("%s%s", s1,s2);
    printf("%d\n", match(s1,s2));
    return 0;
}
