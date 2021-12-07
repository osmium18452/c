#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calc(int **a,int **b,int **c,int m,int n,int k){
        for (int i=0;i<m;i++){
            for (int j=0;j<k;j++){
                for (int l=0;l<n;l++){
                    *(*(c+i)+j)+=(*(*(a+i)+l))*(*(*(b+l)+j));
                }
            }
        }
}

int main(int argc, char *argv[]) {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    int **a = (int **) malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int) * n);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", *(a + i) + j);
        }
    }
    int **b = (int **) malloc(sizeof (int)*n);
    for (int i=0;i<n;i++){
        *(b+i)=(int*) malloc(sizeof(int)*n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", *(b + i) + j);
        }
    }
    int **c=(int**) malloc(sizeof(int)*m);
    for (int i=0;i<m;i++){
        *(c+i)=(int*) malloc(sizeof(int)*k);
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<k;j++){
            *(*(c+i)+j)=0;
        }
    }

    calc(a,b,c,m,n,k);
    for (int i=0;i<m;i++){
        for (int j=0;j<k;j++){
            printf("%d%c",*(*(c+i)+j),j==k-1?'\n':' ');
        }
    }
    return 0;
}
