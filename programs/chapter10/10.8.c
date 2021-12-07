#include <stdio.h>

int main() {
    FILE *f = fopen("in.txt", "rb");
    char c;
    int columncnt = 0;
    printf("+------------------------------------\n| ");
    while (true) {
        c = fgetc(f);
        if (c == EOF) {
            break;
        } else {
            if (columncnt % 4 == 0 && columncnt != 0 && columncnt % 16 != 0) printf(" ");
            if (columncnt % 16 == 0 && columncnt != 0) printf("\n| ");
            printf("%02X", c);
            columncnt++;
        }
    }
    return 0;
}