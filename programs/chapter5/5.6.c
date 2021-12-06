#include <stdio.h>
#define tax(s) {\
double tmp;\
if ((s)<=500) tmp=(s)*0.05-0;\
else if ((s)<=2000) tmp=(s)*0.10-25;\
else if ((s)<=5000) tmp=(s)*0.15-125;\
else if ((s)<=20000) tmp=(s)*0.20-375;\
else if ((s)<=40000) tmp=(s)*0.25-1375;\
else if ((s)<=60000) tmp=(s)*0.30-3375;\
else if ((s)<=80000) tmp=(s)*0.35-6375;\
else if ((s)<=100000) tmp=(s)*0.40-10375;\
else tmp=(s)*0.45-15375;\
tmp;\
}
int main(){
    double s;
    scanf("%lf",&s);
    printf("%lf",(tax(s)));
    return 0;
}
