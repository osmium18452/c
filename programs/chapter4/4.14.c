#include <stdio.h>
int move(int value,int n){
    if (n>0){
        return ((unsigned int)value>>n)|((unsigned int) value<<(32-n));
    } else {
        return ((value<<n)|(value>>(32-n)));
    }
}
int main() {
    int value,n;
    scanf("%d%d",&value,&n);
    printf("%x",move (value,n));
    return 0;
}
