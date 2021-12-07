### [1.](../programs/chapter7/7.1.c)

```c
#include <stdio.h>

#define maxn 1000

void reverse(int *a,int n){
    for (int i=0;i<n/2;i++){
        int t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
}

int main() {
    int a[maxn];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",a+i);
    reverse(a,n);
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}

```

### [2.](../programs/chapter7/7.2.c)

```c
#include <stdio.h>

#define maxn 1000

void sum(int *a,int n, int *odd, int *even){
    *odd=0,*even=0;
    for (int i=0;i<n;i++){
        if (i&1) *odd+=a[i];
        else *even+=a[i];
    }
}

int main() {
    int a[maxn];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int odd,even;
    sum(a,n,&odd,&even);
    printf("%d %d",odd,even);
    return 0;
}
```

### [3.](../programs/chapter7/7.3.c)

```c
#include <stdio.h>

#define maxn 1000

int main() {
    int a[maxn];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i=0;i<n/2;i++){
        if (*(a+i)!=*(a+n-i-1)) {
            printf("not symmetric");
            return 0;
        }
    }
    printf("symmetric");
    return 0;
}
```

### [4.](../programs/chapter7/7.4.c)

```c
#include <stdio.h>

#define maxn 100

int cal(int a[][maxn], int n, int r1, int r2) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += *(a[r1] + i) * (*(a[r2] + i));
    }
    return ans;
}

int main() {
    int a[maxn][maxn];
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    int r1, r2;
    scanf("%d%d", &r1, &r2);
    printf("%d", cal(a, n, r1, r2));
    return 0;
}

```

### [5.](../programs/chapter7/7.5.c)

```c
#include <stdio.h>
#include <string.h>

#define maxn 100

void insert(char* s1,char* s2,int pos){
    int len1=strlen(s1);
    int len2=strlen(s2);
    for (int i=len1;i>pos-1;i--){
        s1[i+len2]=s1[i];
    }
    for (int i=0;i<len2;i++){
        s1[i+pos]=s2[i];
    }
}

int main() {
    char s1[maxn],s2[maxn];
    int pos;
    scanf("%s%s%d",s1,s2,&pos);
    insert(s1,s2,pos);
    printf("%s",s1);
    return 0;
}
```

### [6.](../programs/chapter7/7.6.c)

```c
#include<conio.h>
#include<stdio.h>
#include<string.h>

void fun(char *str) {
    char s[100];
    int j = 0, n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] % 2 != 0) {
            s[j] = str[i];
            j++;
        }
    }
    s[j] = '\0';
    for (int i = 0; s[i] != 0; i++) {
        str[i] = s[i];
        str[i+1]='\0';
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    fun(str);
    printf("%s\n", str);
return 0;
}
```

### [7.](../programs/chapter7/7.7.c)

```c
#include<stdio.h>

void strencode(char *s) {
    while (*s) {
        if (*s >= 'a' && *s <= 'z') *s -= 3;
        if (*s > 'A' && *s <= 'Z') *s += 3;
        s++;
    }
}

int main() {
    char str[100];
    scanf("%s", str);
    strencode(str);
    printf("%s\n", str);
    return 0;
}
```

### [8.](../programs/chapter7/7.8.c)

```c
#include <stdio.h>
#include <string.h>

int match(char *s1, char *s2) {
    int ans = 0;
    int len = strlen(s2);
    while (*s1) {
        for (int i = 0; i<len;i++){
            if (s1[i]!=s2[i]) break;
            if (s1[i]=='\0') return ans;
            if (i==len-1) ans++;
        }
        s1++;
    }
    return ans;
}

int main() {
    char s1[100],s2[100];
    scanf("%s%s", s1,s2);
    printf("%d\n", match(s1,s2));
    return 0;
}
```

### [9.](../programs/chapter7/7.9.c)

```c
#include <stdio.h>
#include <string.h>

int match(char *s1, char *s2) {
    int len1=strlen(s1),len2=strlen(s2);
    for (int i=0;i<len1;i++){
        for (int j=0;j<len2;j++){
            if (s2[j]!='?'&&s1[i+j]!=s2[j]) break;
            if (j==len2-1) return i;
        }
    }
    return -1;
}

int main() {
    char s1[100],s2[100];
    scanf("%s%s", s1,s2);
    printf("%d\n", match(s1,s2));
    return 0;
}
```

### [10.](../programs/chapter7/7.10.c)

```c
#include <stdio.h>
#include <string.h>

int max(char *s) {
    int len = strlen(s);
    int max = 1;
    int cnt = 1;
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) cnt++;
        else cnt = 1;
        if (cnt > max) max = cnt;
    }
    return max;
}

int main() {
    char s[1000];
    scanf("%s", s);
    printf("%d", max(s));
    return 0;
}
```

### [11.](../programs/chapter7/7.11.c)

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[10][100];
    for (int i = 0; i < 10; i++) {
        scanf("%s", s[i]);
    }
    char *sorted[10];
    for (int i = 0; i < 10; i++) {
        sorted[i] = s[i];
    }
    for (int i = 0; i < 10; i++) {
        int pos = i;
        for (int j = i; j < 10; j++) {
            if (strcmp(sorted[pos], sorted[j]) > 0) pos = j;
        }
        char *t = sorted[pos];
        sorted[pos] = sorted[i];
        sorted[i] = t;
    }
    for (int i = 0; i < 10; i++) {
        printf("%s\n", sorted[i]);
    }
    return 0;
}
```

### [12.](../programs/chapter7/7.12.c)

```c
#include <stdio.h>
#include <string.h>

char s[] = "a;lksd\0jflkdjla \0fldas;jfdhfsad;f dljas\0jdsa jlf laskfjl\0sdflsadf sdaj fl\0asdjkf\0";
char *p[100];

int find() {
    int len=sizeof(s);
    char* pos=s;
    int cnt=0;
    for (int i=0;i<len;i++){
        if (s[i]=='\0') p[cnt++]=pos,pos=s+i+1;
    }
    return cnt;
}

int main() {
    int cnt=find();
    for (int i=0;i<cnt;i++){
        printf("%s\n",p[i]);
    }
    return 0;
}
```

### [13.](../programs/chapter7/7.13.c)

```c
#include <stdio.h>
#include <string.h>

void visitint(void *p) {
    printf("%d ", *((int *) p));
}

void visitchar(void *p) {
    printf("%c ", *((char *) p));
}

void visitdouble(void *p) {
    printf("%lf ", *((double *) p));
}

void traverse(void *p, int n, void(*visit)(void *ep)) {
    for (int i = 0; i < n; i++) {
        visit((char*) p + i * (visit == visitchar ? sizeof(char) : (visit == visitint ? sizeof(int) : sizeof(double))));
    }
}


int main() {
    int a[]={1,2,3,4,5,6,7,8,9};
    traverse(a,9,visitint);
    printf("\n");
    double b[]={1.,2.,3.,4.,5.,6.,7.,8.,9.};
    traverse(b,9,visitdouble);
    printf("\n");
    char s[]="abcdefghi";
    traverse(s,9,visitchar);
    return 0;
}
```

### [14.](../programs/chapter7/7.14.c)

```c
#include <stdio.h>
#include <string.h>

int locate(int a[],int n,int e,bool (*compare)(int *ep1,int * ep2)){
    for (int i=0;i<n;i++) {
        if (compare(a+i,&e)) return i;
    }
    return -1;
}

bool gt(int *a,int *b){
    return *a>*b;
}

bool eq(int *a,int *b){
    return *a==*b;
}

int main() {
    int a[]={1,2,3,4,5,6,7,8,9};
    printf("%d",locate(a,9,5,eq));
    return 0;
}
```

### [15.](../programs/chapter7/7.15.c)

```c
#include <stdio.h>
#include <string.h>

int operate(int a,int b,int (*fun)(int x,int y)){
    return fun(a,b);
}

int max(int a,int b){
    return a>b?a:b;
}

int sum(int a,int b){
    return a+b;
}

int diff(int a,int b){
    return a-b;
}

int main() {
    int a=1,b=2;
    printf("%d\n",operate(a,b,max));
    printf("%d\n",operate(a,b,sum));
    printf("%d\n",operate(a,b,diff));
    return 0;
}
```

### [16.](../programs/chapter7/7.16.c)

```c
#include <stdio.h>
#include <string.h>

int * find(int* a,int n,int b){
    for (int i=0;i<n;i++){
        if (a[i]==b) return a+i;
    }
    return NULL;
}

int main() {
    int a[]={1,2,3,4,5,67,89,3};
    printf("%d\n",find(a,sizeof(a)/sizeof(int),3)==NULL?-1:*find(a,sizeof(a)/sizeof(int),3));
    printf("%d\n",find(a,sizeof(a)/sizeof(int),100)==NULL?-1:*find(a,sizeof(a)/sizeof(int),100));
    return 0;
}
```

### 17.

[(1)](../programs/chapter7/7.17.1.c)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[]) {
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    if (strcmp(argv[3],"min")==0) printf("%d",a>b?b:a);
    else if (strcmp(argv[3],"max")==0) printf("%d",a>b?a:b);
    else printf("illegal paramater");
    return 0;
}
```

[(2)](../programs/chapter7/7.17.2.c)

```c
#include <stdio.h>
#include <string.h>

void front(char* s){
    while (*s=='*'){
        for (int i=0;s[i]!='\0';i++){
            s[i]=s[i+1];
        }
    }
}
void middle(char* s){
    while (*s=='*') s++;
    while (*s!='*') s++;
    while (*s=='*'){
        for (int i=0;s[i]!='\0';i++){
            s[i]=s[i+1];
        }
    }
}

void back(char* s){
    for (int i=strlen(s)-1;s[i]=='*';i--){
        s[i]=0;
    }
}

int main(int argc,char* argv[]) {
    char s[]="***123***456***";
    back(s);
    printf("%s",s);
    return 0;
}
```

### [18.](../programs/chapter7/7.18.c)

```c
#include <stdio.h>
#include <string.h>

void select(int *a,int n){
    for (int i=0;i<n;i++){
        int pos=i;
        for (int j=i;j<n;j++) if (a[j]<a[pos]) pos=j;
        int t=a[i];
        a[i]=a[pos];
        a[pos]=t;
    }
}

void insert(int *a,int n){
    for (int i=0;i<n;i++){
        for (int j=i;j>=0;j--){
            if (a[j-1]>a[j]) {
                int t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
            else break;
        }
    }
}

void qsort(int *a,int l,int r){
    int i=l,j=r;
    int key=a[l];
    while (i<j){
        while (i<j&&a[j]>=key){
            j--;
        }
        if (i<j){
            a[i]=a[j];
            i++;
        }
        while (i<j&&a[i]<key){
            i++;
        }
        if (i<j){
            a[j]=a[i];
            j--;
        }
        a[i]=key;
        qsort(a,l,i-1);
        qsort(a,i+1,r);
    }
}

int main(int argc,char* argv[]) {
    int a[]={1,5,4,3,2,8,6,4,9,7,3,3};
    qsort(a,0,11);
    for (int i=0;i<12;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
```

### [19.](../programs/chapter7/7.19.c)

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void calc(int **a,int **b,int **c,int m,int n,int k){
        for (int i=0;i<m;i++){
            for (int j=0;j<k;j++){
                for (int l=0;l<n;l++){
                    *(*(c+i)+j)+=(*(*(a+i)+l))*(*(*(b+l)+j));
                }
            }
        }
}

int main(int argc, char *argv[]) {
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    int **a = (int **) malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        *(a + i) = (int *) malloc(sizeof(int) * n);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", *(a + i) + j);
        }
    }
    int **b = (int **) malloc(sizeof (int)*n);
    for (int i=0;i<n;i++){
        *(b+i)=(int*) malloc(sizeof(int)*n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", *(b + i) + j);
        }
    }
    int **c=(int**) malloc(sizeof(int)*m);
    for (int i=0;i<m;i++){
        *(c+i)=(int*) malloc(sizeof(int)*k);
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<k;j++){
            *(*(c+i)+j)=0;
        }
    }

    calc(a,b,c,m,n,k);
    for (int i=0;i<m;i++){
        for (int j=0;j<k;j++){
            printf("%d%c",*(*(c+i)+j),j==k-1?'\n':' ');
        }
    }
    return 0;
}
```

### [20.](../programs/chapter7/7.20.c)

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxstr 100
#define maxn 1000
struct node {
    int bookno;
    node *next;
};
struct list {
    char s[maxstr];
    node *next;
};

int main() {
    freopen("../in.txt", "r", stdin);
    int bookno;
    char s[maxstr];
    list list[maxn];
    int cnt = 0;
    while (~scanf("%d", &bookno)) {
        gets(s);
        int slen = strlen(s);
        char buf[maxstr];
        int r = 0, l = 0;
        for (int i = 0; i <= slen; i++) {
            if (s[i] == ' ' || s[i] == '\0') {
                l = r;
                r = i;
                if (r - l - 1 > 0) {
                    memset(buf, 0, sizeof(buf));
                    strncpy(buf, s + l + 1, r - l - 1);
                    bool found = 0;
                    for (int j = 0; j < cnt; j++) {
                        if (strcmp(list[j].s, buf) == 0) {
                            found = 1;
                            node *p = list[j].next;
                            bool foundbookno = false;
                            if (p->bookno == bookno) foundbookno = true;
                            while (p->next != NULL) {
                                if (p->bookno == bookno) foundbookno = true;
                                p = p->next;
                            }
                            if (!foundbookno) {
                                p->next = (node *) malloc(sizeof(node));
                                p->next->next = NULL;
                                p->next->bookno = bookno;
                                break;
                            }
                        }
                    }
                    if (!found) {
                        strcpy(list[cnt].s, buf);
                        list[cnt].next = (node *) malloc(sizeof(node));
                        list[cnt].next->next = NULL;
                        list[cnt].next->bookno = bookno;
                        cnt++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        printf("%s ", list[i].s);
        node *p = list[i].next;
        while (p != NULL) {
            printf("%d ", p->bookno);
            p = p->next;
        }
        printf("\n");
    }
    return 0;
}
```
