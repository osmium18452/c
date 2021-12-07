#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("in.txt", "r", stdin);
    int cnt = 1;
    char a[1000];
    while (fgets(a, 999, stdin)) {
        printf("%d %s", cnt, a);
        cnt++;
    }
    return 0;
}

