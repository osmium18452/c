#include <stdio.h>
#include <string.h>

struct ele {
    char s[100];

    bool operator<(const ele s1) {
        if (strcmp(this->s, s1.s) < 0) return true;
        else return false;
    }
};

int main() {
    freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    ele a[1000];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i].s);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                char tmp[100];
                strcpy(tmp, a[j].s);
                strcpy(a[j].s, a[j + 1].s);
                strcpy(a[j + 1].s, tmp);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i].s);
    }
    return 0;
}

