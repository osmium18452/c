#include <stdio.h>

#define maxn 100

int cal(int a[][maxn], int n, int r1, int r2) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += *(a[r1] + i) * (*(a[r2] + i));
    }
    return ans;
}

int main() {
    int a[maxn][maxn];
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    int r1, r2;
    scanf("%d%d", &r1, &r2);
    printf("%d", cal(a, n, r1, r2));
    return 0;
}

