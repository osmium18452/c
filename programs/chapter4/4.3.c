#include<stdio.h>

double root(double x,int n){
    double ymin=0,ymax=x,ymid=x/2;
    while (ymax-ymin>0.000001) {
        ymid=(ymin+ymax)/2;
        double prod=1;
        for (int i=0;i<n;i++) prod*=ymid;
        if (prod>x) ymax=ymid;
        else ymin=ymid;
    }
    return ymid;
}

int main() {
    double x;
    int n;
    scanf("%lf%d",&x,&n);
    printf("%lf",root(x,n));
    return 0;
}
