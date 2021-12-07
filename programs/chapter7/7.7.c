#include<stdio.h>

void strencode(char *s) {
    while (*s) {
        if (*s >= 'a' && *s <= 'z') *s -= 3;
        if (*s > 'A' && *s <= 'Z') *s += 3;
        s++;
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    strencode(str);
    printf("%s\n", str);
    return 0;
}
