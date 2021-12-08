#include <stdio.h>

#define maxn 1000
#define len(a) (sizeof(a) / sizeof(a[0]))

int lis(int arr[], int len) {
    int longest[maxn];
    for (int i = 0; i < len; i++)
        longest[i] = 1;

    for (int j = 1; j < len; j++) {
        for (int i = 0; i < j; i++) {
            if (arr[j] > arr[i] && longest[j] < longest[i] + 1) {
                longest[j] = longest[i] + 1;
            }
        }
    }

    int max = 0;
    for (int j = 0; j < len; j++) {
        if (longest[j] > max) max = longest[j];
    }
    return max;
}

int main() {
    int arr[] = {1, 4, 5, 6, 2, 3, 8};
    int ret = lis(arr, len(arr));
    printf("%d", ret);
    return 0;
}