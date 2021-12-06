#include <math.h>
#include <stdio.h>
double normcfd(double a,double delta,double x){
    return .5+.5*erf((x-a)/(delta*sqrt(2)));
}
int main(){
    double a,delta,x;
    scanf("%lf%lf%lf",&a,&delta,&x);
    printf("%lf",normcfd(a,delta,x));
    return 0;
}
