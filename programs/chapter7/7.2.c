#include <stdio.h>

#define maxn 1000

void sum(int *a,int n, int *odd, int *even){
    *odd=0,*even=0;
    for (int i=0;i<n;i++){
        if (i&1) *odd+=a[i];
        else *even+=a[i];
    }
}

int main() {
    int a[maxn];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int odd,even;
    sum(a,n,&odd,&even);
    printf("%d %d",odd,even);
    return 0;
}
