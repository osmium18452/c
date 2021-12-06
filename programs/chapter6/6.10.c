#include<stdio.h>

#define maxn 1000

int main() {
    int a[maxn], n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int pos=0;
    while (a[pos]<m) pos++;
    for (int i=n;i>pos;i++){
        a[i]=a[i-1];
    }
    a[pos]=m;
    for (int i=0;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
