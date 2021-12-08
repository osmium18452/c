#include <stdio.h>
#define maxn 1000
#define inf 10000000
int main(){
    int a[maxn];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int max=-inf,max2=-inf;
    for (int i=0;i<n;i++) {
        if (a[i]>=max) {
            max2=max;
            max=a[i];
        } else if (a[i]>max2){
            max2=a[i];
        }
    }
    printf("%d %d",max,max2);
    return 0;
}
