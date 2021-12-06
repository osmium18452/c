#include<stdio.h>

#define maxn 1000

int main() {
    int a[maxn], b[maxn], n, m;
    int c[maxn * 2];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", b + i);
    }
    int ca = 0, cb = 0;
    while (ca < n && cb < m) {
        if (a[ca] < b[cb]) c[ca + cb] = a[ca++];
        else c[ca + cb] = b[cb++];
    }
    while (ca < n) {
        c[ca + cb] = a[ca++];
    }
    while (cb < n) {
        c[ca + cb] = b[cb++];
    }
    for (int i = 0; i < n+m; i++) printf("%d ", c[i]);
    return 0;
}
