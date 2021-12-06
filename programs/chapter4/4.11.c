int encode (int n){
    int a,b,c,d;
    a=n/1000;
    b=(n/100)%10;
    c=(n/10)%10;
    d=n%10;
    a=(a+5)%10;
    b=(b+5)%10;
    c=(c+5)%10;
    d=(d+5)%10;
    return a*1000+b*100+c*10+d;
}
