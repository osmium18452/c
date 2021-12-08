#include <stdio.h>

int queue[100000];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    unsigned int head = 0, tail = 0;
    queue[tail++] = n;
    while (true) {
        int now = queue[head++];
        if (now == m) {
            int cnt = 0;
            printf("%d=", m);
            while ((head & 0x80000000) == 0) head *= 2;
            head *= 2;
            while (head != 0) {
                if ((head & 0x80000000) == 0) printf("f(");
                else printf("g(");
                cnt++;
                head *= 2;
            }
            printf("%d", n);
            while (cnt > 0) {
                printf(")");
                cnt--;
            }
            break;
        } else {
            queue[tail++] = now * 3;
            queue[tail++] = now / 2;
        }
    }
    return 0;
}
