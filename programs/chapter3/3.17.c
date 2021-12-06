#include <stdio.h>

int main() {
    int sum=0,prod=0;
    int x,a;
    scanf("%d%d",&x,&a);
    for (int i=1;i<=x;i++){
        prod=prod*10+a;
        sum+=prod;
    }
    printf("%d",sum);
    return 0;
}
