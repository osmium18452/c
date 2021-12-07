#include <stdio.h>

#define maxn 1000

void reverse(int *a,int n){
    for (int i=0;i<n/2;i++){
        int t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
}

int main() {
    int a[maxn];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",a+i);
    reverse(a,n);
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}

