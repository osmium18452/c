#include <stdio.h>

#define maxn 100

int main() {
    int i, row, col, n, a[maxn][maxn] = {0};
    scanf("%d", &n);
    if (n % 2 == 0) n = n + 1;
    row = 0;
    col = (n - 1) / 2;
    a[row][col] = 1;

    for (i = 2; i <= n * n; i++) {
        if (a[(row - 1 + n) % n][(col + 1) % n] == 0) {
            row = (row - 1 + n) % n;
            col = (col + 1) % n;
        } else {
            row = (row + 1) % n;
        }
        a[row][col] = i;
    }

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++)
            printf("%4d", a[row][col]);
        printf("\n");
    }
}

