#include <stdio.h>
#define maxn 100

int main(){
    int m,n,mat[maxn][maxn];
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%d",mat[i]+j);
        }
    }
    for (int i=0;i<n;i++){
        printf("%d ",mat[i][i]);
        printf("\n");
    }
    for (int i=0;i<n;i++){
        printf("%d ",mat[i][n-i-1]);
        printf("\n");
    }
    return 0;
}
