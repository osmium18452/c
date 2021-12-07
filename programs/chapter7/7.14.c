#include <stdio.h>
#include <string.h>

int locate(int a[],int n,int e,bool (*compare)(int *ep1,int * ep2)){
    for (int i=0;i<n;i++) {
        if (compare(a+i,&e)) return i;
    }
    return -1;
}

bool gt(int *a,int *b){
    return *a>*b;
}

bool eq(int *a,int *b){
    return *a==*b;
}

int main() {
    int a[]={1,2,3,4,5,6,7,8,9};
    printf("%d",locate(a,9,5,eq));
    return 0;
}
