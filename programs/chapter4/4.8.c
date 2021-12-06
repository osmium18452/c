#include<stdio.h>

int yang(int i,int j){
    if (j==0||j==i) return 1;
    else return yang (i-1,j)+yang(i-1,j-1);
}
int main() {
    int layer;
    scanf("%d",&layer);
    for (int i=1;i<=layer;i++)
    {
        for(int j=1;j<=i;j++){
            printf("%d%c",yang(i,j),j==i?'\n':' ');
        }
    }
    return 0;
}
