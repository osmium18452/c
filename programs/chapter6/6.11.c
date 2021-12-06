#include<stdio.h>

#define maxn 1000

int main() {
    int a[maxn],b[maxn],c[maxn],n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int cnt=0;
    for (int i=0;i<n;i++){
        int pos=-1;
        for (int j=0;j<cnt;j++){
            if (b[j]==a[i]) pos=j;
        }
        if (pos==-1) {
            b[cnt]=a[i];
            c[cnt++]=1;
        } else c[pos]++;
    }
    for (int i=0;i<cnt;i++){
        printf("%d %d\n",b[i],c[i]);
    }
    return 0;
}
