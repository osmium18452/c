#include <stdio.h>

#define maxn 1000

int count(const char *s) {
    int cnt = 1, pos = 0;
    while (s[pos] != '\0') {
        if (s[pos] == ' ' || s[pos] == ',' || s[pos] == '.') {
            cnt++;
            while (s[pos] == ' ' || s[pos] == ',' || s[pos] == '.') pos++;
        } else pos++;
    }
    return cnt;
}

int main() {
    char s[maxn];
    gets(s);
    printf("%d",count(s));
    return 0;
}
