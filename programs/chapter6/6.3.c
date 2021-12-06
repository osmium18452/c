#include <stdio.h>
#define maxn 10000

int main(){
    int n,mat;
    int max[maxn];
    int maxx=10000000;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        max[i]=-10000000;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&mat);
            if (max[i]<mat) max[i]=mat;
        }
    }
    for (int i=0;i<n;i++) if (maxx>max[i]) maxx=max[i];
    printf("%d ",maxx);
    return 0;
}
