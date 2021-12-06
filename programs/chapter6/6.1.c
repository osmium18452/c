#include <stdio.h>
#define maxn 10
int calc(int (*mat)[10],int m,int n){
    int rtn=0;
    for (int i=0;i<m;i++){
        rtn+=mat[i][0];
        rtn+=mat[i][n-1];
    }
    for (int i=1;i<n-1;i++){
        rtn+=mat[0][i];
        rtn+=mat[m-1][i];
    }
    return rtn;
}
int main(){
    int m,n,mat[maxn][maxn];
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%d",mat[i]+j);
        }
    }
    printf("%d",calc(mat,m,n));
    return 0;
}
