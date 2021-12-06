#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int pow=1;
    double sum=0;
    for (int j=1;j<=n;j++){
        pow*=2;
        sum+=((double)(j&1?-1:1)*pow)/((double )(pow+(j&1?1:-1))*(2*pow+(j&1?-1:1)));
    }
    printf("%f",sum);
    return 0;
}
