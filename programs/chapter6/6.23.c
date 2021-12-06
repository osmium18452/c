#include <stdio.h>
#include <string.h>

#define maxn 1000

int atoi(char *s) {
    int len = strlen(s);
    int rtn = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] > '9' || s[i] < '0') return 0;
        rtn = rtn * 10 + s[i] - '0';
    }
    return rtn;
}

double atod(char *s) {
    int len = strlen(s);
    double rtn = 0.;
    double xs = 0;
    for (int i = 0; i < len; i++) {
        if ((s[i] > '9' || s[i] < '0') && s[i] != '.') return 0;
        if (s[i] == '.') xs = 1;
        else {
            rtn = rtn * 10 + s[i] - '0';
            xs = xs > 0 ? xs * 10 : xs;
        }
    }
    return xs == 0 ? rtn : rtn / xs;
}

int main() {
    char s[maxn];
    scanf("%s", s);
    printf("%d\n%lf\n", atoi(s), atod(s));
    return 0;
}
