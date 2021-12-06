#include <stdio.h>

int main() {
    double sum=2.,prevsum=0.;
    for (int n=1;(prevsum-sum>0?prevsum-sum:sum-prevsum)>0.000001;n++){
        prevsum=sum;
        sum*=(double)(n+(n&1))/(double )(n+((~n)&1));
    }
    printf("%.6f",sum);
    return 0;
}
