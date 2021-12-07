#include <stdio.h>
#include <string.h>

int operate(int a,int b,int (*fun)(int x,int y)){
    return fun(a,b);
}

int max(int a,int b){
    return a>b?a:b;
}

int sum(int a,int b){
    return a+b;
}

int diff(int a,int b){
    return a-b;
}

int main() {
    int a=1,b=2;
    printf("%d\n",operate(a,b,max));
    printf("%d\n",operate(a,b,sum));
    printf("%d\n",operate(a,b,diff));
    return 0;
}
