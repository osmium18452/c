#include <stdio.h>
int getbit(int n,int k){
    return (n>>(k-1))&1;
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%x",getbit(n,k));
    return 0;
}
