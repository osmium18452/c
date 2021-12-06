#include<stdio.h>
#define maxn 1000
int main(){
    int a[1000],n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for (int i=1;i<n;i++){
        if (a[i]==a[i-1]) {
            n--;
            for (int j=i;j<n;j++){
                a[j]=a[j+1];
            }
        }
    }
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
