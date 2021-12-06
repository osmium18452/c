#include <stdio.h>

int main() {
    int sum=0,prod=1;
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        prod*=i;
        sum+=prod;
    }
    printf("%d",sum);
    return 0;
}
