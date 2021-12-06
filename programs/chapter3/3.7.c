#include<stdio.h>
#include<math.h>

int main() {
    double x0, x, f, fd;
    x0 = 1.5;
    do {
        f = 2 * x0 * x0 * x0 + 4 * x0 * x0 -7 * x0 - 6;
        fd = 6 * x0 * x0 + 8 * x0 -7;
        x = x0 - f / fd;
        x0 = x;
    } while (fabs(f / fd) >= 0.00001);
    printf("%f", x);
    return 0;
}
