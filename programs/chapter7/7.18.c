#include <stdio.h>
#include <string.h>

void select(int *a,int n){
    for (int i=0;i<n;i++){
        int pos=i;
        for (int j=i;j<n;j++) if (a[j]<a[pos]) pos=j;
        int t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }
}

void insert(int *a,int n){
    for (int i=0;i<n;i++){
        for (int j=i;j>=0;j--){
            if (a[j-1]>a[j]) {
                int t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
            else break;
        }
    }
}

void qsort(int *a,int l,int r){
    int i=l,j=r;
    int key=a[l];
    while (i<j){
        while (i<j&&a[j]>=key){
            j--;
        }
        if (i<j){
            a[i]=a[j];
            i++;
        }
        while (i<j&&a[i]<key){
            i++;
        }
        if (i<j){
            a[j]=a[i];
            j--;
        }
        a[i]=key;
        qsort(a,l,i-1);
        qsort(a,i+1,r);
    }
}

int main(int argc,char* argv[]) {
    int a[]={1,5,4,3,2,8,6,4,9,7,3,3};
    qsort(a,0,11);
    for (int i=0;i<12;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
