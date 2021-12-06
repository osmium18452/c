### [1.](../programs/chapter4/4.1.c)

```c
#include<stdio.h>

double f(double x) {
    return (1 / (1 + x * x));
}

double calc(double a, double b) {
    int i, l;
    double n = 0.001, s = 0;
    l = (int)((b - a) *1000);
    printf("%d\n",l);
    for (i = 0; i < l; i++) {
        s += (f(a + n * i) + f(a + n * (i + 1))) * n / 2;
    }
    return s;
}

int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%lf", calc(a, b));
    return 0;
}
```

### [2.](../programs/chapter4/4.2.c)

```c
int factorial(int n){
    int prod=1;
    for (int i=1;i<=n;i++) prod*=i;
    return prod;
}
int c(int m,int n){
    return factorial(m)/(factorial(n)*factorial(n-m));
}
```

### [3.](../programs/chapter4/4.3.c)

```c
#include<stdio.h>

double root(double x,int n){
    double ymin=0,ymax=x,ymid=x/2;
    while (ymax-ymin>0.000001) {
        ymid=(ymin+ymax)/2;
        double prod=1;
        for (int i=0;i<n;i++) prod*=ymid;
        if (prod>x) ymax=ymid;
        else ymin=ymid;
    }
    return ymid;
}

int main() {
    double x;
    int n;
    scanf("%lf%d",&x,&n);
    printf("%lf",root(x,n));
    return 0;
}
```

### [4.](../programs/chapter4/4.4.c)

```c
#include<stdio.h>

double calc(){
    static double sum=0;
    static int cnt=0;
    double x;
    if (~scanf("%lf",&x)){
        cnt++;
        sum+=x;
        return calc()+(x-sum/cnt)*(x-sum/cnt);
    }
    return 0;
}

int main() {
    printf("%lf",calc());
    return 0;
}
```

### [5.](../programs/chapter4/4.5.c)

```c
#include<stdio.h>

int calc(int day){
    if (day==10){
        return 1;
    } else {
        return 2*calc(day+1)+2;
    }
}

int main() {
    printf("%d",calc(1));
    return 0;
}
```

### [6.](../programs/chapter4/4.6.c)

```c
#include<stdio.h>

int ack(int m,int n){
    if (m==0) return n-1;
    else if (n==0) return ack(m-1,1);
    else return ack(m-1,ack(m,n-1));
}

int main() {
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d",ack(m,n));
    return 0;
}
```

### 7.

没初始条件

### [8.](../programs/chapter4/4.8.c)

```c
#include<stdio.h>

int yang(int i,int j){
    if (j==0||j==i) return 1;
    else return yang (i-1,j)+yang(i-1,j-1);
}
int main() {
    int layer;
    scanf("%d",&layer);
    for (int i=1;i<=layer;i++)
    {
        for(int j=1;j<=i;j++){
            printf("%d%c",yang(i,j),j==i?'\n':' ');
        }
    }
    return 0;
}
```

### 9.

略

### [10.](../programs/chapter4/4.10.c)

```c
#include <stdio.h>
int change(int m,int c){
    int remain=c-m;
    int sum=0;
    int a[]={1,2,5,10,20,50,100,200,500,1000,2000,5000};
    for (int i=11;i>=0;i--){
        sum+=remain/a[i];
        remain=remain-remain/a[i]*a[i];
    }
    return sum;
}
int main() {
    double m,c;
    int ma,ca;
    scanf("%lf%lf",&m,&c);
    ma=m*100,ca=c*100;
    printf("%d",change(ma,ca));
    return 0;
}
```

### [11.](../programs/chapter4/4.11.c)

```c
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
```

### [12.](../programs/chapter4/4.12.c)

```c
#include <stdio.h>
inline unsigned char xchg(unsigned char n){
    return (n>>4)|(n<<4);
}
int main() {
    unsigned char n;
    scanf("%c",&n);
    printf("%x %x",n,xchg(n));
    return 0;
}
```

### [13.](../programs/chapter4/4.13.c)

```c
#include <stdio.h>
int getbit(int n,int k){
    return (n>>(k-1))&1;
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%x",getbit(n,k));
    return 0;
}
```

### [14.](../programs/chapter4/4.14.c)

```c
#include <stdio.h>
int move(int value,int n){
    if (n>0){
        return ((unsigned int)value>>n)|((unsigned int) value<<(32-n));
    } else {
        return ((value<<n)|(value>>(32-n)));
    }
}
int main() {
    int value,n;
    scanf("%d%d",&value,&n);
    printf("%x",move (value,n));
    return 0;
}
```

### [15.](../programs/chapter4/4.15.c)

```c
int getceil(double n){
    return n>0?(n==(int) n?(int)n:(int)n+1):(int)n;
}
```

### [16.](../programs/chapter4/4.16.c)

```c
int getfloor(double n){
    return n>0?(int)n:(n==(int)n?(int) n:(int) n-1);
}
```

### [17.](../programs/chapter4/4.17.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess(){
    srand(time(0));
    int number=rand()%101;
    int gue;
    for (int i=0;i<5;i++){
        scanf("%d",&gue);
        if (gue==number) {
            printf("ok\n");
            return ;
        } else {
            if (gue>number) printf("bigger\n");
            else printf("smaller\n");
        }
    }
    printf("good game. the number is %d", number);
}
int main() {
    guess();
    return 0;
}
```

### [18.](../programs/chapter4/4.18.c)

```c
#include <stdio.h>
#include <math.h>

void list() {
    double x;
    scanf("%lf", &x);
    printf("1. acos(x)\n");
    printf("2. asin(x)\n");
    printf("3. atan(x)\n");
    printf("4. cos(x)\n");
    printf("5. sin(x)\n");
    printf("6. tan(x)\n");
    printf("7. cosh(x)\n");
    printf("8. sinh(x)\n");
    printf("9. tanh(x)\n");
    printf("10. exp(x)\n");
    printf("11. log(x)\n");
    printf("12. fabs(x)\n");
    printf("13. sqrt(x)\n");
    printf("14. log10(x)\n");
    printf("15. exit\n");
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 15) {
            break;
        } else if (n == 1) {
            printf("%lf\n", acos(x));
        } else if (n == 2) {
            printf("%lf\n", asin(x));
        } else if (n == 3) {
            printf("%lf\n", atan(x));
        } else if (n == 4) {
            printf("%lf\n", cos(x));
        } else if (n == 5) {
            printf("%lf\n", sin(x));
        } else if (n == 6) {
            printf("%lf\n", tan(x));
        } else if (n == 7) {
            printf("%lf\n", cosh(x));
        } else if (n == 8) {
            printf("%lf\n", sinh(x));
        } else if (n == 9) {
            printf("%lf\n", tanh(x));
        } else if (n == 10) {
            printf("%lf\n", exp(x));
        } else if (n == 11) {
            printf("%lf\n", log(x));
        } else if (n == 12) {
            printf("%lf\n", fabs(x));
        } else if (n == 13) {
            printf("%lf\n", sqrt(x));
        } else if (n == 14) {
            printf("%lf\n", log10(x));
        }
    }
}

int main() {
    list();
    return 0;
}
```

### [19.](../programs/chapter4/4.19.c)

```c
#include<stdio.h>

int main() {
    int n, k, x, y, cc, pc;
    pc = cc = 0;
    printf("How many mountains are there?\n\n");
    scanf("%d", &n);
    printf("How many mountains are allowed to move each time?\n");
    scanf("%d", &k);
    do {
        printf("How many mountains do you wish move away?\n");
        scanf("%d", &x);
        if (x < 1 || x > k || x > n) {
            printf("Illegal number,type in another please!\n");
            continue;
        }
        n -= x;
        printf("There are %d mountains left now.\n", n);
        if (!n) {
            printf("I win.\n\n");
            cc++;
        } else {
            y = (n - 1) % (k + 1);
            if (!y)
                y = 1;
            n -= y;
            printf("Copmputer move %d mountains away.\n", y);
            if (n)
                printf(" There are %d mountains left now.\n", n);
            else {
                printf("You win\n\n");
                pc++;
            }
        }
    } while (n);
    return 0;
}

```

### [20.](../programs/chapter4/4.20.c)

```c
#include <math.h>
#include <stdio.h>
double normcfd(double a,double delta,double x){
    return .5+.5*erf((x-a)/(delta*sqrt(2)));
}
int main(){
    double a,delta,x;
    scanf("%lf%lf%lf",&a,&delta,&x);
    printf("%lf",normcfd(a,delta,x));
    return 0;
}
```
