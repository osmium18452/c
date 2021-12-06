#include<stdio.h>

int main() {
    double sum=0;
    int i=1;
    while (sum<13.){
        if (sum>12.) printf("%d ",i);
        sum+=1./(double)i;
        i++;
    }
    return 0;
}
