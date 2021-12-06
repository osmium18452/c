#include <stdio.h>
int change(int m,int c){
    int remain=c-m;
    int sum=0;
    int a[]={1,2,5,10,20,50,100,200,500,1000,2000,5000};
    for (int i=11;i>=0;i--){
        sum+=remain/a[i];
        remain=remain-remain/a[i]*a[i];
    }
    return sum;
}
int main() {
    double m,c;
    int ma,ca;
    scanf("%lf%lf",&m,&c);
    ma=m*100,ca=c*100;
    printf("%d",change(ma,ca));
    return 0;
}
