#include<stdio.h>
#define exchange(a,b){int t;t=a;a=b;b=t;}

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    exchange(a,b);
    printf("%d %d",a,b);
    return 0;
}
