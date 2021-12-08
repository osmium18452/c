#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    cnt += n / 100;
    n = n % 100;
    cnt += n / 50;
    n = n % 50;
    cnt += n / 20;
    n = n % 20;
    cnt += n / 10;
    n = n % 10;
    cnt += n / 5;
    n = n % 5;
    cnt += n / 2;
    cnt += n % 2;
    printf("%d", cnt);
}
