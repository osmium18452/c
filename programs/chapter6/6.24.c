#include <stdio.h>
#define maxn 1000
int main(){
    int a;
    int stack[maxn];
    int top=0;
    scanf("%d",&a);
    while (a>0){
        stack[top++]=a%2;
        a/=2;
    }
    while (top>0) {
        printf("%d",stack[--top]);
    }
    return 0;
}
