#include<stdio.h>

int main() {
    for (int p = 2; p < 5; p++) {
        for (int q = p; q < 12; q++) {
            for (int r = q; r < 12; r++) {
                for (int s = r; s < 12; s++) {
                    if (p * q * r + p * q * s + p * r * s + q * r * s == p * q * r * s) {
                        printf("%d %d %d %d\n", p, q, r, s);
                    }
                }
            }
        }
    }
    return 0;
}
