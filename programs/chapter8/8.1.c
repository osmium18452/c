#include <stdio.h>
#define maxn 1000
#define maxstr 100
struct student{
    char stdno[maxstr],name[maxstr];
    int a,b,c;
};
int main(){
    student student[maxn];
    for (int i=0;i<30;i++){
        scanf("%s%s%d%d%d",student[i].stdno,student[i].name,&student[i].a,&student[i].b,&student[i].c);
    }
    int avga=0,avgb=0,avgc=0;
    int maxa=0,maxb=0,maxc=0;
    int maxapos=0,maxbpos=0,maxcpos=0;
    for (int i=0;i<30;i++){
        avga+=student[i].a;
        avgb+=student[i].b;
        avgc+=student[i].b;
        if (maxa<student[i].a) {
            maxa=student[i].a;
            maxapos=i;
        }
        if (maxb<student[i].b) {
            maxb=student[i].b;
            maxbpos=i;
        }
        if (maxc<student[i].c) {
            maxc=student[i].c;
            maxcpos=i;
        }
    }
    printf("avg a: %lf, avg b: %lf, avg c: %lf\n",(double )avga/30.,(double )avgb/30.,(double )avgc/30.);
    printf("max a student no: %s, max a student name: %s",student[maxapos].stdno,student[maxapos].name);
    printf("max b student no: %s, max b student name: %s",student[maxbpos].stdno,student[maxbpos].name);
    printf("max c student no: %s, max c student name: %s",student[maxcpos].stdno,student[maxcpos].name);
    return 0;
}
