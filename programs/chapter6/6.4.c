#include <stdio.h>
#define maxn 100

int main(){
    freopen("../in.txt","r",stdin);

    int n,mat[maxn][maxn];
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",mat[i]+j);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (mat[i][j]!=mat[j][i]){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}
