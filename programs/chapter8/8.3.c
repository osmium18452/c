#include <stdio.h>

int gcd(int a,int b){
    if (a<b){
        int t=a;
        a=b;
        b=t;
    }
    if (a % b !=0) return gcd(b,a%b);
    else return b;
}

struct fraction{
    int m,n;
    fraction(int m,int n){
        this->n=n;
        this->m=m;
    }
    fraction(){
        this->m=0;
        this->n=1;
    }
    fraction operator * (const fraction &a){
        fraction rtn;
        rtn.m= this->m*a.m;
        rtn.n=this->n*a.n;
        int g=gcd(rtn.m,rtn.n);
        rtn.m/=g;
        rtn.n/=g;
        return rtn;
    }
    fraction operator / (const fraction &a){
        fraction rtn;
        rtn.m= this->m*a.n;
        rtn.n=this->n*a.m;
        int g=gcd(rtn.m,rtn.n);
        rtn.m/=g;
        rtn.n/=g;
        return rtn;
    }
    fraction operator + (const fraction &a){
        fraction rtn;
        rtn.m= this->m*a.n+this->n*a.m;
        rtn.n=this->n*a.n;
        int g=gcd(rtn.m,rtn.n);
        rtn.m/=g;
        rtn.n/=g;
        return rtn;
    }
    fraction operator - (const fraction &a){
        fraction rtn;
        rtn.m= this->m*a.n-this->n*a.m;
        rtn.n=this->n*a.n;
        int g=gcd(rtn.m,rtn.n);
        rtn.m/=g;
        rtn.n/=g;
        return rtn;
    }
};
int main(){
    fraction a(5,2),b(3,5),c;
    c=a*b;
    printf("%d/%d\n",c.m,c.n);
    c=a/b;
    printf("%d/%d\n",c.m,c.n);
    c=a+b;
    printf("%d/%d\n",c.m,c.n);
    c=a-b;
    printf("%d/%d\n",c.m,c.n);
    return 0;
}
