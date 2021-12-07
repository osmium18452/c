#include <stdio.h>
#include <string.h>

int * find(int* a,int n,int b){
    for (int i=0;i<n;i++){
        if (a[i]==b) return a+i;
    }
    return NULL;
}

int main() {
    int a[]={1,2,3,4,5,67,89,3};
    printf("%d\n",find(a,sizeof(a)/sizeof(int),3)==NULL?-1:*find(a,sizeof(a)/sizeof(int),3));
    printf("%d\n",find(a,sizeof(a)/sizeof(int),100)==NULL?-1:*find(a,sizeof(a)/sizeof(int),100));
    return 0;
}
