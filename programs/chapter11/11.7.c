
#include<stdio.h>
#include<math.h>
#define eps 1e-4
#define INF_MIN -200;
#define INF_MAX 200;
int main() {

    double a;
    double b;
    double c;
    double d;
    double x_01;
    double x_02;
    double l;
    double r;
    double mid;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    x_01 = (-b - sqrt(b * b - 3 * a * c)) / (3 * a);
    x_02 = (-b + sqrt(b * b - 3 * a * c)) / (3 * a);
    if (a > 0) {

        l = INF_MIN;
        r = x_01;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)l = mid;
            else r = mid;
        }
        printf("%.2f ", l);
        l = x_01;
        r = x_02;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)r = mid;
            else l = mid;
        }
        printf("%.2f ", l);
        l = x_02;
        r = INF_MAX;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)l = mid;
            else r = mid;
        }
        printf("%.2f", l);
    } else if (a < 0) {

        l = INF_MIN;
        r = x_02;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)r = mid;
            else l = mid;
        }
        printf("%.2f ", l);
        l = x_02;
        r = x_01;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)l = mid;
            else r = mid;
        }
        printf("%.2f ", l);
        l = x_01;
        r = INF_MAX;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)r = mid;
            else l = mid;
        }
        printf("%.2f", l);
    }
}