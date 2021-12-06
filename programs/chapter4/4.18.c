#include <stdio.h>
#include <math.h>

void list() {
    double x;
    scanf("%lf", &x);
    printf("1. acos(x)\n");
    printf("2. asin(x)\n");
    printf("3. atan(x)\n");
    printf("4. cos(x)\n");
    printf("5. sin(x)\n");
    printf("6. tan(x)\n");
    printf("7. cosh(x)\n");
    printf("8. sinh(x)\n");
    printf("9. tanh(x)\n");
    printf("10. exp(x)\n");
    printf("11. log(x)\n");
    printf("12. fabs(x)\n");
    printf("13. sqrt(x)\n");
    printf("14. log10(x)\n");
    printf("15. exit\n");
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 15) {
            break;
        } else if (n == 1) {
            printf("%lf\n", acos(x));
        } else if (n == 2) {
            printf("%lf\n", asin(x));
        } else if (n == 3) {
            printf("%lf\n", atan(x));
        } else if (n == 4) {
            printf("%lf\n", cos(x));
        } else if (n == 5) {
            printf("%lf\n", sin(x));
        } else if (n == 6) {
            printf("%lf\n", tan(x));
        } else if (n == 7) {
            printf("%lf\n", cosh(x));
        } else if (n == 8) {
            printf("%lf\n", sinh(x));
        } else if (n == 9) {
            printf("%lf\n", tanh(x));
        } else if (n == 10) {
            printf("%lf\n", exp(x));
        } else if (n == 11) {
            printf("%lf\n", log(x));
        } else if (n == 12) {
            printf("%lf\n", fabs(x));
        } else if (n == 13) {
            printf("%lf\n", sqrt(x));
        } else if (n == 14) {
            printf("%lf\n", log10(x));
        }
    }
}

int main() {
    list();
    return 0;
}
