#include <stdio.h>

#define maxn 1000

int main() {
    int a[maxn];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i=0;i<n/2;i++){
        if (*(a+i)!=*(a+n-i-1)) {
            printf("not symmetric");
            return 0;
        }
    }
    printf("symmetric");
    return 0;
}
