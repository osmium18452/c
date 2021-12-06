#include <stdio.h>

#define maxn 1000

int strlen(char *s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int strcpy(const char *s1, char *s2) {
    int pos1 = 0;
    while (s1[pos1] != '\0') {
        s2[pos1] = s1[pos1];
        pos1++;
    }
    s2[pos1] = '\0';
}

int strcon(char *s1, char *s2) {
    int pos1 = 0;
    while (s1[pos1] != '\0') pos1++;
    int pos2 = 0;
    while (s2[pos2] != '\0') {
        s1[pos1] = s2[pos2];
        pos1++, pos2++;
    }
    s1[pos1] = '\0';
}

int strsrch(char *s, char c) {
    int pos = 0;
    while (s[pos] != '\0' && s[pos] != c) pos++;
    return s[pos] == '\0' ? -1 : pos;
}

int strcmp(char *s1, char *s2) {
    int pos = 0;
    while (s1[pos] == s2[pos] && s1[pos] != '\0' && s2[pos] != '\0') {
        pos++;
    }
    if (s1[pos] == s2[pos] && s1[pos] == '\0') return 0;
    else return s1[pos] - s2[pos];
    return 0;
}

int main() {
    char s1[maxn], s2[maxn], s3[maxn], s4[maxn];
    scanf("%s", s1);
    scanf("%s", s2);
    printf("(1) strlen: %d\n", strlen(s1));
    strcpy(s1, s3);
    strcpy(s2, s4);
    printf("(2) strcpy: %s\n", s3);
    strcon(s3, s4);
    printf("(3) s3+s4: %s\n", s3);
    printf("(4) %d\n", strsrch(s1, '1'));
    printf("(5) %d\n", strcmp(s1, s2));
    return 0;
}
