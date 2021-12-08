#include <stdio.h>

int n, k, a[20], b[20], min = 1000000000;

void s(int x) {
    if (x == n) {
        int Max = b[0];
        for (int i = 1; i <= k; i++)
            if (b[i] > Max)
                Max = b[i];
        if (Max < min)
            min = Max;
        return;
    }
    for (int i = 0; i < k; i++) {
        if (b[i] + a[x] > min)
            continue;
        b[i] += a[x];
        s(x + 1);
        b[i] -= a[x];
    }
}

int main() {
    int i;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", a + i);
    for (i = 0; i < k; i++)
        b[i] = 0;
    s(0);
    printf("%d", min);
    return 0;
}


