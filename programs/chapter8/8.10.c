#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[52];
    for (int i = 0; i < 52; i++) {
        a[i] = i;
    }
    for (int &i : a) {
//        srand(time(0));
        int rd = rand() % 52;
        int t = a[rd];
        a[rd] = i;
        i = t;
    }
    for (int i = 0; i < 52; i++) {
        if (a[i] % 4 == 0) {
            printf("spade");
        } else if (a[i] % 4 == 1) {
            printf("heart");
        } else if (a[i] % 4 == 2) {
            printf("diamond");
        } else if (a[i] % 4 == 3) {
            printf("club");
        }
        if (a[i] % 13 == 0) {
            printf("A");
        } else if (a[i] % 13 < 10) {
            printf("%d", a[i] % 13 + 1);
        } else if (a[i] % 13 == 10) {
            printf("J");
        } else if (a[i] % 13 == 11) {
            printf("Q");
        } else if (a[i] % 13 == 12) {
            printf("K");
        }
        if (i == 12 || i == 25 || i == 38) {
            printf("\n");
        } else printf(" ");
    }
    return 0;
}
