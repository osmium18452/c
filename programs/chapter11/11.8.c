#include<stdio.h>

#define maxn 1000

void Show(int *a, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

void Merge(int *a, int left, int m, int right) {
    int aux[maxn] = {0};
    int i;
    int j;
    int k;

    for (i = left, j = m + 1, k = 0; k <= right - left; k++) {
        if (i == m + 1) {
            aux[k] = a[j++];
            continue;
        }
        if (j == right + 1) {
            aux[k] = a[i++];
            continue;
        }
        if (a[i] < a[j]) {
            aux[k] = a[i++];
        } else {
            aux[k] = a[j++];
        }
    }
    for (i = left, j = 0; i <= right; i++, j++) {
        a[i] = aux[j];
    }
}

void MergeSort(int *a, int start, int end) {
    if (start < end) {
        int i;
        i = (end + start) / 2;
        MergeSort(a, start, i);
        MergeSort(a, i + 1, end);
        Merge(a, start, i, end);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[maxn];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    MergeSort(a, 0, n - 1);
    Show(a, n);
    return 0;
}
