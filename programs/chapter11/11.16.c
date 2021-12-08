#include <stdio.h>

#define maxn 10000

int main() {
    int n, k;
    char a[maxn];
    scanf("%d%d", &n, &k);
    scanf("%s", a);
    a[n] = '\0';
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            if (a[j] < a[j - 1]) {
                for (int l = j; l <= n - i + 1; l++) {
                    a[l - 1] = a[l];
                }
                break;
            }
        }
    }
    printf("%s", a);
    return 0;
}
