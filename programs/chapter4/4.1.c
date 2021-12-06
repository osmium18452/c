#include<stdio.h>

double f(double x) {
    return (1 / (1 + x * x));
}

double calc(double a, double b) {
    int i, l;
    double n = 0.001, s = 0;
    l = (int)((b - a) *1000);
    printf("%d\n",l);
    for (i = 0; i < l; i++) {
        s += (f(a + n * i) + f(a + n * (i + 1))) * n / 2;
    }
    return s;
}

int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%lf", calc(a, b));
    return 0;
}
