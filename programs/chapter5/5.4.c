#include <stdio.h>
#define reserve(a,n) {int tmp=1;for (int i=0;i<n;i++)tmp*=10;((double)((int)((a)*tmp)))/tmp;}
int main(){
    double a;
    int n;
    scanf("%lf%d",&a,&n);
    printf("%lf",(reserve(a,n)));
    return 0;
}
