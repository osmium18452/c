## 第三章

### 1.

(1)

①`printf("%d %u %o %x\n%d %u %o %x\n%d %u %o %x\n",128,128,128,128,-128,-128,-128,-128,3456789,3456789,3456789,3456789);`
<br>
②`printf("%f %e\n%f %e\n", 3.1415926, 3.1415926, 12345678.123456789, 12345678.123456789);`<br>
③`printf("%c %d\n%c %d\n", 'X', 'X', 65, 65);`<br>
④`printf("\%")`<br>

(2)

①`printf("%-5d %-5d %-5d %5d %5d %5d", 456, -123, 987654, 456, -123, 987654);`<br>
②`printf("%-10.6e\n%-10.6e\n%10.6e\n%10.6e\n", (double) 666666, (double) 55555, (double) 666666, (double) 55555);`<br>
③`printf("%-14.6e\n%-14.6e\n%14.6e\n%14.6e\n", 3.1415926, 12.3456, 3.1415926, 12.3456);`<br>
④

``` c
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int width,accuracy;
    char format[100000]="%";
    char buffer[100];
    scanf("%d%d",&width,&accuracy);
    itoa(width,buffer,10);
    strcat(format,buffer);
    strcat(format,".");
    itoa(accuracy,buffer,10);
    strcat(format,buffer);
    strcat(format,"f %");
    itoa(width,buffer,10);
    strcat(format,buffer);
    strcat(format,".");
    itoa(accuracy,buffer,10);
    strcat(format,buffer);
    strcat(format,"f ");
    printf(format,98.16054,77.676767);
    return 0;
}
```

(3)

①`printf("%010.1f %010.1f %010.1f %010.1f",1234.,-1234.,12345.5,-1234.5);`<br>
②`printf("%9.1f %9.1f %9.1f %9.1f",1234.,-1234.,12345.5,-1234.5);`<br>
③`printf("%+8d %+8d",1234,-1234);`<br>
④`printf("0%o 0x%x 0%o 0x%x 0%o 0x%x 0%o 0x%x", 202, 202, 117, 117, 80, 80, 230, 230);`<br>

### 2.

(1)

①`scanf("%d%o%x",&a,&b,&c);`<br>
②`scanf("%lf%lf",&d1,&d2);`<br>
③`scanf("%c%d",&c1,&c2);`

(2)

①`scanf("%3d%3d%3d",&e1,&e2,&e3);`<br>
②`scanf("%lf%d",&f1,&f2);`<br>
③`scanf("%2d345%d",&g1,&g2);`

(3)

①`scanf("%d %d %d %d",&h1,&h2,&h3,&h4);`<br>
②`scanf("%d,%d,%d%d",&i1,&i2,&i3,&i4);`<br>
③`scanf("%d:%d:%d.%d",&j1,&j2,&j3,&j4);`<br>
⑤`scanf("%d%c%d%c",&k1,&k2,&k3,&k4);`<br>
⑥`scanf("%d %c %d %c",&m1,&m2,&m3,&m4);`<br>
⑦`scanf("a=%d,b=%c,c=%d,d=%c",&n1,&n2,&n3,&n4);`

### [3.](../programs/chapter3/3.3.c)

```c
#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    a = getchar();
    b = getchar();
    c = getchar();
    d = getchar();
    putchar(d);
    putchar(c);
    putchar(b);
    putchar(a);
}
```

### [4.](../programs/chapter3/3.4.c)

```c
#include <cstdio>

int main(){
    char c=getchar();
    if (c>='0'&&c<='9') printf("number");
    else if (c>='A'&&c<='Z') printf("upper case letter");
    else if (c>='a'&&c<='z') printf("lower case letter");
    else if (c=='+'||c=='-'||c=='*'||c=='/') printf("arithmetic operator");
    else if (c=='<'||c=='>') printf("relation operator");
    else if (c=='!') printf("logical operator");
    else printf("other character");
}

```

### [5.](../programs/chapter3/3.5.c)

```c
#include <cstdio>

int main(){
    int year,month,day;
    scanf("%d-%d-%d",&year,&month,&day);
    bool flag=(year%4==0&&year%400!=0);
    if (month==1) printf("%d",day);
    else if (month==2) printf("%d",day+31);
    else if (month==3) printf("%d",day+31+28+(flag?1:0));
    else if (month==4) printf("%d",day+31+28+31+(flag?1:0));
    else if (month==5) printf("%d",day+31+28+31+30+(flag?1:0));
    else if (month==6) printf("%d",day+31+28+31+30+31+(flag?1:0));
    else if (month==7) printf("%d",day+31+28+31+30+31+30+(flag?1:0));
    else if (month==8) printf("%d",day+31+28+31+30+31+30+31+(flag?1:0));
    else if (month==9) printf("%d",day+31+28+31+30+31+30+31+31+(flag?1:0));
    else if (month==10) printf("%d",day+31+28+31+30+31+30+31+31+30+(flag?1:0));
    else if (month==11) printf("%d",day+31+28+31+30+31+30+31+31+30+31+(flag?1:0));
    else if (month==12) printf("%d",day+31+28+31+30+31+30+31+31+30+31+30+(flag?1:0));
    return 0;
}

```

### [6.](../programs/chapter3/3.6.c)

```c
#include <cstdio>
#include <cstring>

char unit[]={"仟佰拾万千百十亿千百十万千百十元点角分"};
char num[]={"零壹贰叁肆伍陆柒捌玖"};
int main(){
    printf("%s",unit);
    char s[100];
    scanf("%s",s);
    int length=strlen(s);
    int pos=-1;
    for (int i=0;i<length;i++){
        if (s[i]=='.') pos=i;
        break;
    }
    if (pos>0&&pos<length-3) printf("not rmb");
    else if (pos>15||(pos==-1&&length>15)) printf("you're rich. i don't know how to express.");
    else {
        for (int i=0;i<length;i++){
            if (i==pos) continue;
            else printf("%c%c",num[s[i]-'0'],unit[17-length+pos+i]);
        }
        printf("整");
    }
    return 0;
}

```

### [7.](../programs/chapter3/3.7.c)

```c

#include
<stdio.h>
#include
<math.h>

int main() {
double x0, x, f, fd;
x0 = 1.5;
do {
f = 2 * x0 * x0 * x0 + 4 * x0 * x0 -7 * x0 - 6;
fd = 6 * x0 * x0 + 8 * x0 -7;
x = x0 - f / fd;
x0 = x;
} while (fabs(f / fd) >= 0.00001);
printf("%f", x);
return 0;
}
```

### [8.](../programs/chapter3/3.8.c)

```c

#include
<stdio.h>
#include
<math.h>

int main() {
double xmid, xmax=10., xmin=-10., fmid, fmax, fmin;
do{
xmid=(xmax+xmin)/2;
fmid=xmid*xmid-6*xmid-1;
fmax=xmax*xmax-6*xmax-1;
fmin=xmin*xmin-6*xmin-1;
if (fmid*fmin>0) xmin=xmid;
else xmax=xmid;
} while (xmax-xmin>0.000001);
printf("%f %f %f", xmid, xmax, xmin);
return 0;
}
```

### [9.](../programs/chapter3/3.9.c)

```c

#include
<stdio.h>

int main() {
double sum=0;
int i=1;
while (sum<13.){
if (sum>12.) printf("%d ", i);
sum+=1./(double)i;
i++;
}
return 0;
}
```

### [10.](../programs/chapter3/3.10.c)

```c

#include
<stdio.h>

int main() {
for (int p = 2; p < 5; p++) {
for (int q = p; q < 12; q++) {
for (int r = q; r < 12; r++) {
for (int s = r; s < 12; s++) {
if (p * q * r + p * q * s + p * r * s + q * r * s == p * q * r * s) {
printf("%d %d %d %d\n", p, q, r, s);
}
}
}
}
}
return 0;
}
```

### [11.](../programs/chapter3/3.11.c)

```c

#include
<stdio.h>

int main() {
int sum=0;
for (int i=1;i<10;i++) {
for (int j=0;j<10;j++){
for (int k=0;k<10;k++){
if (i!=j&&i!=k&&k!=j){
sum++;
}
}
}
}
printf("%d", sum);
return 0;
}
```

### [12.](../programs/chapter3/3.12.c)

```c

#include
<stdio.h>

int main() {
char s[100];
scanf("%s", s);
int sum=0;
for (int i=0;s[i]!='\0';i++){
sum+=s[i]-'0';
}
printf("%d", sum);
return 0;
}
```

### [13.](../programs/chapter3/3.13.c)

```c

#include
<stdio.h>
#include
<string.h>

int main() {
char s[100];
scanf("%s", s);
int len=strlen(s);
for (int i=0;i<len/2;i++){
if (s[i]!=s[len-i]) {
printf("NO");
return 0;
}
}
printf("YES");
return 0;
}
```

### [14.](../programs/chapter3/3.14.c)

```c

#include
<stdio.h>
#include
<string.h>

int main() {
for (int a=1;a<7;a++){
for (int b=0;b<7;b++){
for (int c=1;c<7;c++){
if (a*49+b*7+c==c*81+b*9+a){
printf("%d", a*49+b*7+c);
}
}
}
}
return 0;
}
```

### [15.](../programs/chapter3/3.15.c)

```c

#include
<stdio.h>

int main() {
double sum=2., prevsum=0.;
for (int n=1;(prevsum-sum>0?prevsum-sum:sum-prevsum)>0.000001;n++){
prevsum=sum;
sum*=(double)(n+(n&1))/(double )(n+((~n)&1));
}
printf("%.6f", sum);
return 0;
}
```

### [16.](../programs/chapter3/3.16.c)

```c

#include
<stdio.h>

int main() {
int sum=0, prod=1;
int n;
scanf("%d", &n);
for (int i=1;i<=n;i++){
prod*=i;
sum+=prod;
}
printf("%d", sum);
return 0;
}
```

### [17.](../programs/chapter3/3.17.c)

```c

#include
<stdio.h>

int main() {
int sum=0, prod=0;
int x, a;
scanf("%d%d", &x, &a);
for (int i=1;i<=x;i++){
prod=prod*10+a;
sum+=prod;
}
printf("%d", sum);
return 0;
}
```

### [19.](../programs/chapter3/3.19.c)

```c

#include
<stdio.h>

int main() {
int n;
scanf("%d", &n);
int pow=1;
double sum=0;
for (int j=1;j<=n;j++){
pow*=2;
sum+=((double)(j&1?-1:1)*pow)/((double )(pow+(j&1?1:-1))*(2*pow+(j&1?-1:1)));
}
printf("%f", sum);
return 0;
}
```

### [20.](../programs/chapter3/3.20.c)

```c


#include
<stdio.h>

int main() {
int a1=1, a2=1, a3;
int sn, sn_1=2;
for (int i=3;i<1000;i++){
a3=a1+a2;
sn=sn_1+a3;
if (sn>=100&&sn_1<100) printf("%d ", i);
if (sn>=1000&&sn_1<1000) printf("%d ", i);
if (sn>=10000&&sn_1<10000) {
printf("%d ", i);
break;
}
sn_1=sn;
a1=a2;
a2=a3;
}
return 0;
}
```

### [21.](../programs/chapter3/3.21.c)

```c

#include
<stdio.h>

int main() {
double C, F;
for (int i=-50;i<200;i++){
F=(double )i;
C=9*(F-32)/5;
printf("F: %f C: %f\n", F, C);
}
return 0;
}
```

### [22.](../programs/chapter3/3.22.c)

```c


#include
<stdio.h>

int main() {
printf("**    ** ******** **       **       ********\n");
printf("**    ** ******** **       **       ********\n");
printf("**    ** **       **       **       **    **\n");
printf("******** ******** **       **       **    **\n");
printf("******** ******** **       **       **    **\n");
printf("**    ** **       **       **       **    **\n");
printf("**    ** ******** ******** ******** ********\n");
printf("**    ** ******** ******** ******** ********\n");
return 0;
}
```

### [23.](../programs/chapter3/3.23.c)

```c

#include
<stdio.h>

int main() {
for (int i=0;i<8;i++){
for (int j=0;j<8;j++){
printf("%c", (i+j)&1?219:' ');
}
printf("\n");
}
return 0;
}
```

### [24.](../programs/chapter3/3.24.c)

```c

#include
<stdio.h>

int main() {
printf("       |**                                                           **\n");
printf("       |    **                                                   **    \n");
printf("       |        **                                           **        \n");
printf("       |           **                                     **           \n");
printf("       |             **                                 **             \n");
printf("       |               **                             **               \n");
printf("-------+----------------**---------------------------**----------------\n");
printf("       |                 **                         **                 \n");
printf("       |                   **                     **                   \n");
printf("       |                     **                 **                     \n");
printf("       |                        **            **                       \n");
printf("       |                           **      **                          \n");
printf("       |                              ****                             \n");
return 0;
}
```

### [25.](../programs/chapter3/3.25.c)

```c

#include
<stdio.h>

int main() {
double capital=0.;
for (int i=0;i<5;i++){
capital=(capital+1000)/(1+12*.00063);
}
printf("%.2f", capital);
return 0;
}
```

### [26.](../programs/chapter3/3.26.c)

```c

#include
<stdio.h>

int main() {
int a=1;
for (int i=9;i>=1;i--){
a=2*a+2;
}
printf("%d", a);
return 0;
}
```

### [27.](../programs/chapter3/3.27.c)

```c

#include
<stdio.h>

int main() {
int steps = 7;
while (true) {
if (steps % 2 == 1 && steps % 3 == 2 && steps % 5 == 4 && steps % 6 == 5){
printf("%d", steps);
break;
} else {
steps+=7;
}
}
return 0;
}
```

### [28.](../programs/chapter3/3.28.c)

```c

#include
<stdio.h>
int main()
{
int x, y, z;
for (x=0; x<=1; x++)
for (y=0; y<=1; y++)
for (z=0; z<=1; z++)
if (((x&&!y) || (!x&&y)) && ((y&&!z) || (!y&&z)) && ((z&&x==0&&y==0) || (!z&&x+y!=0)))
{
printf("zs told %s.\n", x?"the truth":"a lie");
printf("ls told %s.\n", y?"the truth":"a lie");
printf("ww told %s.\n", z?"the truth":"a lie");

}
return 0;
}
```

### [29.](../programs/chapter3/3.29.c)

```c

#include
<stdio.h>
int main()
{
char a, b, c;
for (a = 'x'; a <= 'z'; a++) {
for (b = 'x'; b <= 'z'; b++) {
if (a != b) {   //避免参赛队员重复比赛
for (c = 'x'; c <= 'z'; c++) {
if (a != c && b != c) {      //避免参赛队员重复比赛
if (a != 'x' && c != 'x' && c != 'z') {   //根据题意判断
printf("a with %c, b with %c, c with %c", a, b, c);
}
}
}
}
}
}
return 0;
}
```

### [30.](../programs/chapter3/3.30.c)

```c

#include
<stdio.h>
int main()
{
int m, n, number=0;
printf(" red white black\n");
printf("......................\n");
for ( m=0; m<=3; m++ )
for ( n=0; n<=3; n++ )
if (8-m-n<=6)
printf(" %2d: %d %d %d\n", ++number, m, n, 8-m-n);
return 0;
}
```

