#include <stdio.h>
struct COMPLEX{
    COMPLEX(){
        this->r=0;
        this->i=0;
    }
    COMPLEX(double r,double i){
        this->r=r;
        this->i=i;
    }
    double r,i;
    COMPLEX operator + (const COMPLEX &a){
        COMPLEX rtn;
        rtn.i=this->i+a.i;
        rtn.r=this->r+a.r;
        return rtn;
    }
    COMPLEX operator - (const COMPLEX &a){
        COMPLEX rtn;
        rtn.i=this->i-a.i;
        rtn.r=this->r-a.r;
        return rtn;
    }
    COMPLEX operator * (const COMPLEX &a){
        COMPLEX rtn;
        rtn.r=this->r*a.r-this->i*a.i;
        rtn.i=this->r*a.i+this->i*a.r;
        return rtn;
    }
    COMPLEX operator / (const COMPLEX &a){
        COMPLEX rtn;
        rtn.r=(this->r*a.r+this->i*a.i)/(a.r*a.r+a.i*a.i);
        rtn.i=(this->i*a.r-this->r*a.i)/(a.r*a.r+a.i*a.i);
        return rtn;
    }
};
int main(){
    COMPLEX a(1,1),b(2,2),c;
    c=a+b;
    printf("%.3lf+%.3lfi\n",c.r,c.i);
    c=a-b;
    printf("%.3lf+%.3lfi\n",c.r,c.i);
    c=a*b;
    printf("%.3lf+%.3lfi\n",c.r,c.i);
    c=a/b;
    printf("%.3lf+%.3lfi\n",c.r,c.i);
    return 0;
}
