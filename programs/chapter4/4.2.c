int factorial(int n){
    int prod=1;
    for (int i=1;i<=n;i++) prod*=i;
    return prod;
}
int c(int m,int n){
    return factorial(m)/(factorial(n)*factorial(n-m));
}
