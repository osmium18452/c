#include <stdio.h>
#include <string.h>

int match(char *s1, char *s2) {
    int len1=strlen(s1),len2=strlen(s2);
    for (int i=0;i<len1;i++){
        for (int j=0;j<len2;j++){
            if (s2[j]!='?'&&s1[i+j]!=s2[j]) break;
            if (j==len2-1) return i;
        }
    }
    return -1;
}

int main() {
    char s1[100],s2[100];
    scanf("%s%s", s1,s2);
    printf("%d\n", match(s1,s2));
    return 0;
}
