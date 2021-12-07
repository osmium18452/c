#include <stdio.h>
#include <string.h>
#define maxstr 100
struct stdtch{
    bool student;
    char name[maxstr],number[maxstr],gender[maxstr],clortl[maxstr];
    int wageorgrade;
};

void count(stdtch* a,int n,int *ta,int *fail){
    *ta=0;
    *fail=0;
    for (int i=0;i<n;i++){
        if (a[i].student){
            fail+=a[i].wageorgrade<60?1:0;
        } else {
            ta+=strcmp(a[i].clortl,"ta")==0?1:0;
        }
    }
}

int main() {
    stdtch a[100];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s%s%s%s%d",a[i].name,a[i].number,a[i].gender,a[i].clortl,&a[i].wageorgrade);
    }
    int ta,fail;
    count(a,n,&ta,&fail);
    return 0;
}
