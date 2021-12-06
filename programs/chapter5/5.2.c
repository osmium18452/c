#include<stdio.h>
#define volume(a,b,c) (a)*(b)*(c)

int main() {
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%lf",volume(a,b,c));
    return 0;
}
