#include<stdio.h>

double calc(){
    static double sum=0;
    static int cnt=0;
    double x;
    if (~scanf("%lf",&x)){
        cnt++;
        sum+=x;
        return calc()+(x-sum/cnt)*(x-sum/cnt);
    }
    return 0;
}

int main() {
    printf("%lf",calc());
    return 0;
}
