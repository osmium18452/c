#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 1000

int main() {
    char s[maxn];
    gets(s);
    int len = strlen(s);
    for (int i = len / 2 - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (s[j] > s[j + 1]) {
                char t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }
    for (int i = (len + 1) / 2; i < ((len + 1) / 2 + len) / 2; i++) {
        char t = s[i];
        s[i] = s[len - i + (len + 1) / 2 - 1];
        s[len - i + (len + 1) / 2 - 1] = t;
    }
    printf("%s", s);
    return 0;
}
