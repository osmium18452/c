#include <math.h>
#include <stdio.h>
#define area(a,b,c) sqrt((((a)+(b)+(c))/2)*((((a)+(b)+(c))/2)-(a))*((((a)+(b)+(c))/2)-(b))*((((a)+(b)+(c))/2)-(c)))
int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%lf",area(a,b,c));
    return 0;
}
