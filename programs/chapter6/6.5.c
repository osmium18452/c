#include<iostream>

#define maxn 4
using namespace std;

double *gaussin(double a[maxn][maxn], double b[maxn]) {
    int i, j, k;
    double c[maxn];
    for (k = 0; k < maxn - 1; k++) {
        for (i = k + 1; i < maxn; i++)
            c[i] = a[i][k] / a[k][k];
        for (i = k + 1; i < maxn; i++) {
            for (j = 0; j < maxn; j++) {
                a[i][j] = a[i][j] - c[i] * a[k][j];
            }
            b[i] = b[i] - c[i] * b[k];
        }
    }
    double *x=(double*) malloc(maxn*sizeof (double));
    x[maxn - 1] = b[maxn - 1] / a[maxn - 1][maxn - 1];
    for (i = maxn - 2; i >= 0; i--) {
        double sum = 0;
        for (j = i + 1; j < maxn; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    return x;
}

int main() {
    double a[maxn][maxn] = {1, 3, 2, 13, 7, 2, 1, -3, 9, 15, 3, -2, -2, -2, 11, 5};
    double b1[maxn] = {9, 6, 11, -2};
    double b2[maxn] = {0, 4, 7, -1};
    double *x1 = gaussin(a, b1);
    double *x2 = gaussin(a, b2);
    for (int i=0;i<maxn;i++){
        printf("%8.4lf %.4lf\n",*(x1+i),*(x2+i));
    }
    free(x1);
    free(x2);
    return 0;
}
