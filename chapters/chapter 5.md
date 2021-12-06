### [1.](../programs/chapter5/5.1.c)

```c
#include<stdio.h>
#define exchange(a,b){int t;t=a;a=b;b=t;}

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    exchange(a,b);
    printf("%d %d",a,b);
    return 0;
}
```

### [2.](../programs/chapter5/5.2.c)

```c
#include<stdio.h>
#define volume(a,b,c) (a)*(b)*(c)

int main() {
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%lf",volume(a,b,c));
    return 0;
}
```

### [3.](../programs/chapter5/5.3.c)

```c
#include <math.h>
#include <stdio.h>
#define area(a,b,c) sqrt((((a)+(b)+(c))/2)*((((a)+(b)+(c))/2)-(a))*((((a)+(b)+(c))/2)-(b))*((((a)+(b)+(c))/2)-(c)))
int main(){
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%lf",area(a,b,c));
    return 0;
}
```

### [4.](../programs/chapter5/5.4.c)

```c
#include <stdio.h>
#define reserve(a,n) {int tmp=1;for (int i=0;i<n;i++)tmp*=10;((double)((int)((a)*tmp)))/tmp;}
int main(){
    double a;
    int n;
    scanf("%lf%d",&a,&n);
    printf("%lf",(reserve(a,n)));
    return 0;
}
```

### 5.

```c
#define cmtoinch(n) (n)*0.3937
#define mtofeet(n) (n)*3.28048
#define kmtomile(n) (n)*0.62137
#define octokg(n) (n)*28.3495
#define pdtokg(n) (n)*.4535
#define gltoliter(n) (n)*3.7854
```

### [6.](../programs/chapter5/5.6.c)

```c
#include <stdio.h>
#define tax(s) {\
double tmp;\
if ((s)<=500) tmp=(s)*0.05-0;\
else if ((s)<=2000) tmp=(s)*0.10-25;\
else if ((s)<=5000) tmp=(s)*0.15-125;\
else if ((s)<=20000) tmp=(s)*0.20-375;\
else if ((s)<=40000) tmp=(s)*0.25-1375;\
else if ((s)<=60000) tmp=(s)*0.30-3375;\
else if ((s)<=80000) tmp=(s)*0.35-6375;\
else if ((s)<=100000) tmp=(s)*0.40-10375;\
else tmp=(s)*0.45-15375;\
tmp;\
}
int main(){
    double s;
    scanf("%lf",&s);
    printf("%lf",(tax(s)));
    return 0;
}
```

### [7.](../programs/chapter5/5.7.c)

```c
#include <stdio.h>
#include <stdarg.h>

double avg(int first, ...) {
    int count = 0, sum = 0, i;
    va_list arg_ptr;
    va_start(arg_ptr, first);
    i = first;
    while (i != -1) {
        sum += i;
        count++;
        i = va_arg(arg_ptr, int);
    }
    va_end(arg_ptr);
    return count > 0 ? (double) sum / count : 0;
}
int main(){
    printf("%lf\n",avg(1,2,3,-1));
    printf("%lf\n",avg(7,8,9,10,-1));
    printf("%lf\n",avg(-1));
    return 0;
}

```

### [8.](../programs/chapter5/5.8.c)

```c
#include <stdio.h>
#ifdef RELEASE
int main(){
    double ans=0.,init=10.;
    for (int i=0;i<10;i++){
        ans+=init;
        init/=2;
        if (i==9) printf("total: %lf current: %lf\n",ans,init);
        ans+=init;
    }
    return 0;
}
#endif
#ifdef DEBUG
int main(){
    double ans=0.,init=10.;
    for (int i=0;i<10;i++){
        ans+=init;
        init/=2;
        if (i==9) printf("total: %lf current: %lf\n",ans,init);
        ans+=init;
        printf("time: %d total: %lf current: %lf\n",i,ans,init);
    }
    return 0;
}
#endif
```
