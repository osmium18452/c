### [1.](../programs/chapter6/6.1.c)

```c
#include <stdio.h>
#define maxn 10
int calc(int (*mat)[10],int m,int n){
    int rtn=0;
    for (int i=0;i<m;i++){
        rtn+=mat[i][0];
        rtn+=mat[i][n-1];
    }
    for (int i=1;i<n-1;i++){
        rtn+=mat[0][i];
        rtn+=mat[m-1][i];
    }
    return rtn;
}
int main(){
    int m,n,mat[maxn][maxn];
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%d",mat[i]+j);
        }
    }
    printf("%d",calc(mat,m,n));
    return 0;
}
```

### [2.](../programs/chapter6/6.2.c)

```c
#include <stdio.h>
#define maxn 100

int main(){
    int m,n,mat[maxn][maxn];
    scanf("%d%d",&m,&n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%d",mat[i]+j);
        }
    }
    for (int i=0;i<n;i++){
        printf("%d ",mat[i][i]);
        printf("\n");
    }
    for (int i=0;i<n;i++){
        printf("%d ",mat[i][n-i-1]);
        printf("\n");
    }
    return 0;
}
```

### [3.](../programs/chapter6/6.3.c)

```c
#include <stdio.h>
#define maxn 10000

int main(){
    int n,mat;
    int max[maxn];
    int maxx=10000000;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        max[i]=-10000000;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&mat);
            if (max[i]<mat) max[i]=mat;
        }
    }
    for (int i=0;i<n;i++) if (maxx>max[i]) maxx=max[i];
    printf("%d ",maxx);
    return 0;
}
```

### [4.](../programs/chapter6/6.4.c)

```c
#include <stdio.h>
#define maxn 100

int main(){
    freopen("../in.txt","r",stdin);

    int n,mat[maxn][maxn];
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",mat[i]+j);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (mat[i][j]!=mat[j][i]){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}
```

### [5.](../programs/chapter6/6.5.c)

```c
#include<iostream>

#define maxn 4
using namespace std;

double *gaussin(double a[maxn][maxn], double b[maxn]) {
    int i, j, k;
    double c[maxn];
    for (k = 0; k < maxn - 1; k++) {
        for (i = k + 1; i < maxn; i++)
            c[i] = a[i][k] / a[k][k];
        for (i = k + 1; i < maxn; i++) {
            for (j = 0; j < maxn; j++) {
                a[i][j] = a[i][j] - c[i] * a[k][j];
            }
            b[i] = b[i] - c[i] * b[k];
        }
    }
    double *x=(double*) malloc(maxn*sizeof (double));
    x[maxn - 1] = b[maxn - 1] / a[maxn - 1][maxn - 1];
    for (i = maxn - 2; i >= 0; i--) {
        double sum = 0;
        for (j = i + 1; j < maxn; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }

    return x;
}

int main() {
    double a[maxn][maxn] = {1, 3, 2, 13, 7, 2, 1, -3, 9, 15, 3, -2, -2, -2, 11, 5};
    double b1[maxn] = {9, 6, 11, -2};
    double b2[maxn] = {0, 4, 7, -1};
    double *x1 = gaussin(a, b1);
    double *x2 = gaussin(a, b2);
    for (int i=0;i<maxn;i++){
        printf("%8.4lf %.4lf\n",*(x1+i),*(x2+i));
    }
    free(x1);
    free(x2);
    return 0;
}
```

### [6.](../programs/chapter6/6.6.c)

```c
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main() {
    printf("lamda1=18.8691\n");
    printf("lamda2=15.9408\n");
    printf("lamda3=10.2960\n");
    printf("lamda4=6.14717\n");
    printf("lamda5=1.74688\n");
    printf("v1=[0.299904, -0.210221, -0.383578, -0.120915, 1]\n");
    printf("v2=[12.8888, -5.62693, 9.56063, 19.6918, 1]\n");
    printf("v3=[-20.0209, -26.2991, -0.447651, 5.75576, 1]\n");
    printf("v4=[-6.77796, 7.9932, -10.8336, 11.9295, 1]\n");
    printf("v5=[-0.960185, 0.771665, 1.39533, 0.120734, 1]\n");
}
```

### [7.](../programs/chapter6/6.7.c)

```c
#include<stdio.h>
#define maxn 1000
int main(){
    int a[1000],n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for (int i=1;i<n;i++){
        if (a[i]==a[i-1]) {
            n--;
            for (int j=i;j<n;j++){
                a[j]=a[j+1];
            }
        }
    }
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
```

### [8.](../programs/chapter6/6.8.c)

```c
#include<stdio.h>
#define maxn 1000
int main(){
    int a[1000],n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for (int i=1;i<n;i++){
        if (a[i]==a[i-1]) {
            n--;
            for (int j=i;j<n;j++){
                a[j]=a[j+1];
            }
        }
    }
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
```

### [9.](../programs/chapter6/6.9.c)

```c
#include<stdio.h>

#define maxn 1000

int main() {
    int a[maxn], b[maxn], n, m;
    int c[maxn * 2];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", b + i);
    }
    int ca = 0, cb = 0;
    while (ca < n && cb < m) {
        if (a[ca] < b[cb]) c[ca + cb] = a[ca++];
        else c[ca + cb] = b[cb++];
    }
    while (ca < n) {
        c[ca + cb] = a[ca++];
    }
    while (cb < n) {
        c[ca + cb] = b[cb++];
    }
    for (int i = 0; i < n+m; i++) printf("%d ", c[i]);
    return 0;
}
```

### [10.](../programs/chapter6/6.10.c)

```c
#include<stdio.h>

#define maxn 1000

int main() {
    int a[maxn], n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int pos=0;
    while (a[pos]<m) pos++;
    for (int i=n;i>pos;i++){
        a[i]=a[i-1];
    }
    a[pos]=m;
    for (int i=0;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
```

### [11.](../programs/chapter6/6.11.c)

```c
#include<stdio.h>

#define maxn 1000

int main() {
    int a[maxn],b[maxn],c[maxn],n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int cnt=0;
    for (int i=0;i<n;i++){
        int pos=-1;
        for (int j=0;j<cnt;j++){
            if (b[j]==a[i]) pos=j;
        }
        if (pos==-1) {
            b[cnt]=a[i];
            c[cnt++]=1;
        } else c[pos]++;
    }
    for (int i=0;i<cnt;i++){
        printf("%d %d\n",b[i],c[i]);
    }
    return 0;
}
```

### [12.](../programs/chapter6/6.12.c)

```c
#include<stdio.h>

#define maxn 1000

int main() {
    int a[maxn], n = 1;
    for (;;) {
        scanf("%d", a + n);
        if (a[n] == -9999) break;
        n++;
    }
    n--;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[n]) {
            printf("%d ", i);
            return 0;
        }
    }
    printf("no such number");
    return 0;
}
```

### [13.](../programs/chapter6/6.13.c)

```c
#include<stdio.h>
#include<math.h>

#define NUM 320
int number[NUM];

int fun(int i) {
    int j;
    if (i <= 1)
        return 0;
    if (i == 2)
        return 1;
    if (!(i % 2))
        return 0;
    for (j = 3; j <= (int) (sqrt((double) i) + 1); j += 2)
        if (!(i % j)) return 0;
    return 1;
}

int main() {
    int i, j, count = 0;
    for (j = 0, i = 3; i <= 1993; i += 2)
        if (fun(i))
            number[j++] = i;
    for (j--; number[j] > 1898; j--) {
        for (i = 0; number[j] - number[i] > 1898; i++);
        if (number[j] - number[i] == 1898)
            printf("(%d).%3d,%d\n", ++count, number[i], number[j]);
    }

    return 0;
}
```

### [14.](../programs/chapter6/6.14.c)

```c
#include <stdio.h>
#define maxn 10
int main(){
    int a[maxn];
    for (int i=0;i<10;i++) scanf("%d",a+i);
    for (int i=9;i>0;i--){
        for (int j=0;j<i;j++){
            if (a[j]%1000>a[j+1]%1000||(a[j]%1000==a[j+1]%1000&&a[j]>a[j+1])){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for (int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;

```

### [15.](../programs/chapter6/6.15.c)

```c
略
```

### [16.](../programs/chapter6/6.16.c)

```c
#include <stdio.h>

#define maxn 1000

int strlen(char *s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int strcpy(const char *s1, char *s2) {
    int pos1 = 0;
    while (s1[pos1] != '\0') {
        s2[pos1] = s1[pos1];
        pos1++;
    }
    s2[pos1] = '\0';
}

int strcon(char *s1, char *s2) {
    int pos1 = 0;
    while (s1[pos1] != '\0') pos1++;
    int pos2 = 0;
    while (s2[pos2] != '\0') {
        s1[pos1] = s2[pos2];
        pos1++, pos2++;
    }
    s1[pos1] = '\0';
}

int strsrch(char *s, char c) {
    int pos = 0;
    while (s[pos] != '\0' && s[pos] != c) pos++;
    return s[pos] == '\0' ? -1 : pos;
}

int strcmp(char *s1, char *s2) {
    int pos = 0;
    while (s1[pos] == s2[pos] && s1[pos] != '\0' && s2[pos] != '\0') {
        pos++;
    }
    if (s1[pos] == s2[pos] && s1[pos] == '\0') return 0;
    else return s1[pos] - s2[pos];
    return 0;
}

int main() {
    char s1[maxn], s2[maxn], s3[maxn], s4[maxn];
    scanf("%s", s1);
    scanf("%s", s2);
    printf("(1) strlen: %d\n", strlen(s1));
    strcpy(s1, s3);
    strcpy(s2, s4);
    printf("(2) strcpy: %s\n", s3);
    strcon(s3, s4);
    printf("(3) s3+s4: %s\n", s3);
    printf("(4) %d\n", strsrch(s1, '1'));
    printf("(5) %d\n", strcmp(s1, s2));
    return 0;
}
```

### [17.](../programs/chapter6/6.17.c)

```c
#include <stdio.h>
#define maxn 1000
void remove(char* s){
    while (s[0]==' ') s++;
    int pos=0;
    while (s[pos]!='\0') pos++;
    pos--;
    while (s[pos]==' ') s[pos--]='\0';
}
int main(){
    char s[maxn];
    scanf("%s",s);
    remove(s);
    printf("%s",s);
    return 0;
}
```

### [18.](../programs/chapter6/6.18.c)

```c
#include <stdio.h>

#define maxn 1000

int count(const char *s) {
    int cnt = 1, pos = 0;
    while (s[pos] != '\0') {
        if (s[pos] == ' ' || s[pos] == ',' || s[pos] == '.') {
            cnt++;
            while (s[pos] == ' ' || s[pos] == ',' || s[pos] == '.') pos++;
        } else pos++;
    }
    return cnt;
}

int main() {
    char s[maxn];
    gets(s);
    printf("%d",count(s));
    return 0;
}
```

### [19.](../programs/chapter6/6.19.c)

```c
#include <stdio.h>
#include <string.h>
#define maxn 1000

bool symmetric(char* s){
    int len=strlen(s);
    for (int i=0;i<len/2;i++){
        if (s[i]!=s[len-1-i]) return false;
    }
    return true;
}

int main() {
    char s[maxn];
    gets(s);
    printf("%c",symmetric(s)?'y':'n');
    return 0;
}
```

### [20.](../programs/chapter6/6.20.c)

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 1000

char* prefix(char* s1,char*s2){
    int len=strlen(s1)>strlen(s2)?strlen(s2):strlen(s1);
    char* s=(char*) malloc((len+1)*sizeof(char));
    int pos=0;
    while (s1[pos]==s2[pos]){
        s[pos]=s1[pos];
        pos++;
    }
    s[pos]='\0';
    return s;
}

int main() {
    char s1[maxn],s2[maxn];
    gets(s1);
    gets(s2);
    printf("%s",prefix(s1,s2));
    return 0;
}
```

### [21.](../programs/chapter6/6.21.c)

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 1000

int main() {
    char s[maxn];
    gets(s);
    int len = strlen(s);
    for (int i = len / 2 - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (s[j] > s[j + 1]) {
                char t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }
    for (int i = (len + 1) / 2; i < ((len + 1) / 2 + len) / 2; i++) {
        char t = s[i];
        s[i] = s[len - i + (len + 1) / 2 - 1];
        s[len - i + (len + 1) / 2 - 1] = t;
    }
    printf("%s", s);
    return 0;
}
```

### [22.](../programs/chapter6/6.22.c)

```c
#include <stdio.h>
#include <string.h>

#define maxn 1000

int main() {
    int n;
    char s[maxn];
    scanf("%d",&n);
    int pos=0;
    if (n<0){
        s[pos++]='-';
        n=-n;
    }
    while (n!=0) {
        s[pos]=n%10+'0';
        pos++;
        n/=10;
    }
    strrev(s[0]=='-'?s+1:s);
    printf("%s",s);
    return 0;
}
```

### [23.](../programs/chapter6/6.23.c)

```c
#include <stdio.h>
#include <string.h>

#define maxn 1000

int atoi(char *s) {
    int len = strlen(s);
    int rtn = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] > '9' || s[i] < '0') return 0;
        rtn = rtn * 10 + s[i] - '0';
    }
    return rtn;
}

double atod(char *s) {
    int len = strlen(s);
    double rtn = 0.;
    double xs = 0;
    for (int i = 0; i < len; i++) {
        if ((s[i] > '9' || s[i] < '0') && s[i] != '.') return 0;
        if (s[i] == '.') xs = 1;
        else {
            rtn = rtn * 10 + s[i] - '0';
            xs = xs > 0 ? xs * 10 : xs;
        }
    }
    return xs == 0 ? rtn : rtn / xs;
}

int main() {
    char s[maxn];
    scanf("%s", s);
    printf("%d\n%lf\n", atoi(s), atod(s));
    return 0;
}
```

### [24.](../programs/chapter6/6.24.c)

```c
#include <stdio.h>
#define maxn 1000
int main(){
    int a;
    int stack[maxn];
    int top=0;
    scanf("%d",&a);
    while (a>0){
        stack[top++]=a%2;
        a/=2;
    }
    while (top>0) {
        printf("%d",stack[--top]);
    }
    return 0;
}
```

### [25.](../programs/chapter6/6.25.c)

```c
#include <stdio.h>

#define maxn 100

int main() {
    int i, row, col, n, a[maxn][maxn] = {0};
    scanf("%d", &n);
    if (n % 2 == 0) n = n + 1;
    row = 0;
    col = (n - 1) / 2;
    a[row][col] = 1;

    for (i = 2; i <= n * n; i++) {
        if (a[(row - 1 + n) % n][(col + 1) % n] == 0) {
            row = (row - 1 + n) % n;
            col = (col + 1) % n;
        } else {
            row = (row + 1) % n;
        }
        a[row][col] = i;
    }

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++)
            printf("%4d", a[row][col]);
        printf("\n");
    }
}

```

### [26.](../programs/chapter6/6.26.c)

```c
？
```
