#include <stdio.h>
#include <string.h>

int max(char *s) {
    int len = strlen(s);
    int max = 1;
    int cnt = 1;
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) cnt++;
        else cnt = 1;
        if (cnt > max) max = cnt;
    }
    return max;
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d", max(s));
    return 0;
}
