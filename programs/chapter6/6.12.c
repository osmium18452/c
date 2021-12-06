#include<stdio.h>

#define maxn 1000

int main() {
    int a[maxn], n = 1;
    for (;;) {
        scanf("%d", a + n);
        if (a[n] == -9999) break;
        n++;
    }
    n--;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[n]) {
            printf("%d ", i);
            return 0;
        }
    }
    printf("no such number");
    return 0;
}
