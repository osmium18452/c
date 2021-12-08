#include <stdio.h>
#include <stdlib.h>

int main() {

    int C1 = 0;
    int C2 = 0;
    int num = 0;
    bool *x = NULL;
    int **m = NULL;
    int *w = NULL;

    printf("capability of first ship:");
    scanf("%d", &C1);

    printf("capability of second ship:");
    scanf("%d", &C2);


    printf("cargo num:");
    scanf("%d", &num);

    x = (bool *) malloc((num + 1) * sizeof(bool));
    w = (int *) malloc((num + 1) * sizeof(int));

    m = (int **) malloc((num + 1) * sizeof(int *));
    for (int i = 0; i <= num; i++) {
        m[i] = (int *) malloc((C1 + 1) * sizeof(int));
    }
    printf("cargo weight\n");

    for (int i = 1; i <= num; i++) {
        scanf("%d", w + i);
    }

    for (int i = 1; i <= num; i++) {
        m[i][0] = 0;
    }

    for (int i = 1; i < C1 + 1; i++) {
        if (w[num] > i) {
            m[num][i] = 0;
            x[num] = false;
        } else {
            m[num][i] = w[num];
            x[num] = true;
        }
    }

    for (int i1 = num - 1; i1 >= 1; i1--) {
        for (int j = 1; j <= C1; j++) {
            if (w[i1] > j) {
                m[i1][j] = m[i1 + 1][j];
                x[i1] = false;
            } else {
                int temW = w[i1] + m[i1 + 1][j - w[i1]];
                if (temW > m[i1 + 1][j]) {
                    m[i1][j] = temW;
                    x[i1] = true;
                } else {
                    m[i1][j] = m[i1 + 1][j];
                    x[i1] = false;
                }
            }
        }
    }
    int max = m[1][1];
    for (int i = 1; i <= C1; i++) {
        if (m[1][i] > max && m[1][i] <= C1)
            max = m[1][i];
    }
    int totalW = 0;
    for (int i = 1; i <= num; i++) {
        totalW += w[i];
    }
    if (totalW - max <= C2) printf("yes");
    else printf("no");

    return 0;
}
