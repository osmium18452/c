#include <stdio.h>
#include <string.h>

int main() {
    char s[10][100];
    for (int i = 0; i < 10; i++) {
        scanf("%s", s[i]);
    }
    char *sorted[10];
    for (int i = 0; i < 10; i++) {
        sorted[i] = s[i];
    }
    for (int i = 0; i < 10; i++) {
        int pos = i;
        for (int j = i; j < 10; j++) {
            if (strcmp(sorted[pos], sorted[j]) > 0) pos = j;
        }
        char *t = sorted[pos];
        sorted[pos] = sorted[i];
        sorted[i] = t;
    }
    for (int i = 0; i < 10; i++) {
        printf("%s\n", sorted[i]);
    }
    return 0;
}
