#include <stdio.h>
#define maxn 10
int main(){
    int a[maxn];
    for (int i=0;i<10;i++) scanf("%d",a+i);
    for (int i=9;i>0;i--){
        for (int j=0;j<i;j++){
            if (a[j]%1000>a[j+1]%1000||(a[j]%1000==a[j+1]%1000&&a[j]>a[j+1])){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for (int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;

