#include<stdio.h>

int main() {
    int sum=0;
    for (int i=1;i<10;i++) {
        for (int j=0;j<10;j++){
            for (int k=0;k<10;k++){
                if (i!=j&&i!=k&&k!=j){
                    sum++;
                }
            }
        }
    }
    printf("%d",sum);
    return 0;
}
