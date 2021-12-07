### [1.](../programs/chapter8/8.1.c)

```c
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
```

### [2.](../programs/chapter8/8.2.c)

```c
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
```

### [3.](../programs/chapter8/8.3.c)

```c
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
```

### [4.](../programs/chapter8/8.4.c)

```c
struct intdouble {
    bool intel;
    double d;
    int i;

    bool operator<(const intdouble &a) {
        if (this->intel && a.intel) return this->i < a.i;
        else if (!this->intel && !a.intel) return this->d < a.d;
        else if (!this->intel && a.intel) return this->d < (double) a.i;
        else if (this->intel && !a.intel) return (double) this->i < a.d;
    }

    void print(){
        if (this->intel) printf("%d ", this->i);
        else printf("%lf ",this->d);
    }
};
```

### [5.](../programs/chapter8/8.5.c)

```c
#include <stdio.h>
#include <string.h>
#define maxstr 100
struct stdtch{
    bool student;
    char name[maxstr],number[maxstr],gender[maxstr],clortl[maxstr];
    int wageorgrade;
};

void count(stdtch* a,int n,int *ta,int *fail){
    *ta=0;
    *fail=0;
    for (int i=0;i<n;i++){
        if (a[i].student){
            fail+=a[i].wageorgrade<60?1:0;
        } else {
            ta+=strcmp(a[i].clortl,"ta")==0?1:0;
        }
    }
}

int main() {
    stdtch a[100];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%s%s%s%s%d",a[i].name,a[i].number,a[i].gender,a[i].clortl,&a[i].wageorgrade);
    }
    int ta,fail;
    count(a,n,&ta,&fail);
    return 0;
}
```

### [6.](../programs/chapter8/8.6.c)

```c
#include <stdio.h>

struct DATE {
    int year, month, day;

    DATE(int y, int m, int d) {
        this->year = y;
        this->month = m;
        this->day = d;
    }

    DATE() {
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }

    int getWeekDay() {
        return (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    }

    bool operator<(const DATE &a) {
        return this->year == a.year ? (this->month == a.month ? (this->day < a.day) : (this->month < a.month)) : (
                this->year < a.year);
    }

    int to_day(DATE date) {
        int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int day = 0;
        int i;
        for (i = 1; i < date.year; i++) {
            day += (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) ? 366 : 365;
        }
        if (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0) mon[2]++;
        for (i = 1; i < date.month; i++) {
            day += mon[i];
        }
        return day + date.day;
    }

    DATE to_date(int n) {
        int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year=1;
        while ((((year%4==0&&year%100!=0)||year%400==0)&&n>366)||n>365){
            year++;
            n-=(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 366 : 365;
        }
        int month=1;
        while(n>mon[month]){
            n-=mon[month];
            month++;
        }
        return DATE(year,month,n);
    }

    int operator-(const DATE &a) {
        return to_day(*this) - to_day(a);
    }

    DATE operator+(const int &a) {
        return to_date(to_day(*this)+a);
    }
};

int main() {
    DATE date(2021, 4, 5);
    DATE d2(2020, 4, 4);
    if (d2 < date) printf("%d\n", date.getWeekDay());
    printf("%d\n", date - d2);
    DATE d3=d2+10;
    printf("%d %d %d\n",d3.year,d3.month,d3.day);
    return 0;
}
```

### [7.](../programs/chapter8/8.7.c)

```c
#include <stdio.h>
#include <math.h>

#define infmin 0.00001
#define pi 3.1415926

double abso(double a) {
    a > 0 ? a : -a;
}

double min(double a, double b) {
    return a > b ? b : a;
}

struct POINT {
    double x, y;

    POINT() {
        this->x = 0;
        this->y = 0;
    }

    POINT(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

struct LINE {
    POINT s, e;

    LINE() {
        this->s.x = 0;
        this->s.y = 0;
        this->e.x = 0;
        this->e.y = 0;
    }

    LINE(POINT a, POINT b) {
        this->s.x = a.x;
        this->s.y = a.y;
        this->e.x = b.x;
        this->e.y = b.y;
    }
};

struct RECT {
    POINT lt, rb;
};
struct CIRCLE {
    POINT c;
    double r;
};

//(1)

double distance(POINT a, POINT b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool inrec(POINT a, RECT b) {
    return (a.x > b.lt.x && a.x < b.rb.x && a.y > b.rb.y && a.y < b.lt.y);
}

bool incircle(POINT a, CIRCLE b) {
    return (distance(a, b.c) < b.r);
}

bool online(POINT a, LINE l) {
    return (distance(a, l.e) + distance(a, l.s) - distance(l.e, l.s) < infmin);
}

double distance(POINT a, LINE l) {
    double cross = (l.s.x - l.e.x) * (a.x - l.e.x) + (l.s.y - l.e.y) * (a.y - l.e.y);
    if (cross <= 0) return sqrt((a.x - l.e.x) * (a.x - l.e.x) + (a.y - l.e.y) * (a.y - l.e.y));

    double d2 = (l.s.x - l.e.x) * (l.s.x - l.e.x) + (l.s.y - l.e.y) * (l.s.y - l.e.y);
    if (cross >= d2) return sqrt((a.x - l.s.x) * (a.x - l.s.x) + (a.y - l.s.y) * (a.y - l.s.y));

    double r = cross / d2;
    double px = l.e.x + (l.s.x - l.e.x) * r;
    double py = l.e.y + (l.s.y - l.e.y) * r;
    return sqrt((a.x - px) * (a.x - px) + (py - a.y) * (py - a.y));
}

double distance(POINT a, CIRCLE b) {
    return abso(distance(a, b.c) - b.r);
}

double distance(POINT a, RECT b) {
    return min(min(min(distance(a, LINE(b.lt, POINT(b.rb.x, b.lt.y))), distance(a, LINE(b.lt, POINT(b.lt.x, b.rb.y)))),
                   distance(a, LINE(b.rb, POINT(b.lt.x, b.rb.y)))), distance(a, LINE(b.rb, POINT(b.rb.x, b.lt.y))));
}

//(2)

POINT direction(LINE a) {
    return POINT(a.s.x - a.e.x, a.s.y - a.e.y);
}

bool parallel(LINE a, LINE b) {
    return direction(a).x * direction(b).y - direction(a).y * direction(b).x < infmin;
}

bool inter(LINE a, LINE b, POINT *c) {
    if (parallel(a, b)) return false;
    else {
        *c = POINT(((a.s.x - a.e.x) * (b.s.y * b.e.x - b.s.x * b.e.y) -
                    (b.s.x - b.e.x) * (a.s.y * a.s.x - a.s.x * a.e.y)) /
                   ((a.s.y - a.e.y) * (b.s.x - b.e.x) - (b.s.y - b.e.y) * (a.s.x - a.e.x)),
                   ((a.s.y - a.e.y) * (b.s.y * b.e.x - b.s.x * b.e.y) -
                    (b.s.y - b.e.y) * (a.s.y * a.e.x - a.s.x * a.e.y)) /
                   ((a.s.y - a.e.y) * (b.s.x - b.e.x) - (b.s.y - b.e.y) * (a.s.x - a.e.x)));
        return true;
    }
}

bool inter(LINE a, RECT b, POINT *c, POINT *d) {
    LINE l1 = LINE(b.lt, POINT(b.lt.x, b.rb.y));
    LINE l2 = LINE(b.lt, POINT(b.rb.x, b.lt.y));
    LINE l3 = LINE(b.rb, POINT(b.lt.x, b.rb.y));
    LINE l4 = LINE(b.rb, POINT(b.rb.x, b.lt.y));
    POINT p1, p2, p3, p4;
    inter(a, l1, &p1);
    inter(a, l2, &p2);
    inter(a, l3, &p3);
    inter(a, l4, &p4);
    if (online(p1, l1)) {
        *c = p1;
        if (online(p2, l2)) {
            *d = p2;
            return true;
        } else if (online(p3, l3)) {
            *d = p3;
            return true;
        } else if (online(p4, l4)) {
            *d = p4;
            return true;
        }
    } else if (online(p2, l2)) {
        *c = p1;
        if (online(p3, l3)) {
            *d = p3;
            return true;
        } else if (online(p4, l4)) {
            *d = p4;
            return true;
        }
    } else if (online(p3, l3)) {
        *c = p1;
        if (online(p4, l4)) {
            *d = p4;
            return true;
        }
    }
}

inline POINT Vector(POINT A, POINT B) {
    return {B.x - A.x, B.y - A.y};
}

double cross(POINT A, POINT B, POINT P) {
    POINT AB = Vector(A, B);
    POINT AP = Vector(A, P);
    return AB.x * AP.y - AB.y * AP.x;
}

inline double dis2(POINT a, POINT b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

double disLine(POINT A, POINT B, POINT P) {
    return fabs(cross(A, B, P)) / sqrt(dis2(A, B));
}

double dot(POINT A, POINT B, POINT P) {
    POINT AB = Vector(A, B);
    POINT AP = Vector(A, P);
    return AB.x * AP.x + AB.y * AP.y;
}

POINT Vbase(POINT A, POINT B, POINT O, double r) {
    double base = sqrt(r * r - disLine(A, B, O) * disLine(A, B, O));
    POINT AB = Vector(A, B);
    POINT e = {AB.x / sqrt(dis2(A, B)), AB.y / sqrt(dis2(A, B))};
    return {e.x * base, e.y * base};
}

POINT prxy(POINT A, POINT B, POINT O) {
    POINT AO = Vector(A, O);
    POINT AB = Vector(A, B);
    double l = dot(A, B, O) / sqrt(dis2(A, B));
    POINT e = {AB.x / sqrt(dis2(A, B)), AB.y / sqrt(dis2(A, B))};
    POINT Apr = {e.x * l, e.y * l};
    return {A.x + Apr.x, A.y + Apr.y};
}

bool inter(LINE a, CIRCLE b, POINT *c, POINT *d) {
    double dis = distance(b.c, a);
    if (dis < b.r) {
        POINT Base = Vbase(a.e, a.s, b.c, b.r);
        POINT pr = prxy(a.e, a.s, b.c);
        POINT x1 = {Base.x + pr.x, Base.y + pr.y};
        POINT x2 = {pr.x - Base.x, pr.y - Base.y};
        return true;
    } else return false;
}

//(3)

double area(RECT a) {
    return fabs((a.lt.x - a.rb.x) * (a.lt.y - a.rb.y));
}
// (4)
double area(CIRCLE a){
    return pi*a.r*a.r;
}

bool inter(CIRCLE a,CIRCLE b){
    double d=distance(a.c,b.c);
    if (d>a.r+b.r) return true;
    if (d<min(a.r,b.r)) return true;
    else return false;
}

bool contain(CIRCLE a,CIRCLE b){
    double d=distance(a.c,b.c);
    if (d<min(a.r,b.r)) return true;
}

int main() {

    return 0;
}
```

### [8.](../programs/chapter8/8.8.c)

```c
void Fill(CDC *pDC, POINT Seed,
          COLORREF BoundaryColor,
          COLORREF FillColor) {
    queue <POINT> Q;
    int maxsize = 0;
    Q.push(Seed);
    while (Q.size() > 0) {
        POINT p = Q.front();
        Q.pop();
        COLORREF pColor = pDC->GetPixel(p);
        if (pColor == FillColor || pColor == BoundaryColor) continue;
        pDC->SetPixel(p, FillColor);
        POINT ps[4] = {{p.x - 1, p.y},
                       {p.x + 1, p.y},
                       {p.x,     p.y + 1},
                       {p.x,     p.y - 1}};
        for (int i = 0; i < 4; i++) {
            pColor = pDC->GetPixel(ps[i]);
            if (pColor != BoundaryColor && pColor != FillColor)
                Q.push(ps[i]);
        }
    }
}
```

### [9.](../programs/chapter8/8.9.c)

```c
#include <stdio.h>
#include <string.h>

enum fruit {
    apple, orange, banana, grape, pear
};
bool visited[5];
int cnt;

void dfs(int curr,int n) {
    if (n == 3) {
        for (int i = 0; i < 5; i++) {
            if (visited[i]) printf("%s ",
                                   i == apple ? "apple" : (i == orange ? "orange" : (i == banana ? "banana" : (i ==
                                                                                                               grape
                                                                                                               ? "grape"
                                                                                                               : "pear"))));
        }
        putchar('\n');
        cnt++;
        return;
    }
    for (int i = curr; i < 5; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i,n + 1);
            visited[i] = false;
        }
    }
}

int main() {
    memset(visited, 0, sizeof(visited));
    cnt=0;
    dfs(0,0);
    printf("%d",cnt);
    return 0;
}
```

### [10.](../programs/chapter8/8.10.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[52];
    for (int i = 0; i < 52; i++) {
        a[i] = i;
    }
    for (int &i : a) {
//        srand(time(0));
        int rd = rand() % 52;
        int t = a[rd];
        a[rd] = i;
        i = t;
    }
    for (int i = 0; i < 52; i++) {
        if (a[i] % 4 == 0) {
            printf("spade");
        } else if (a[i] % 4 == 1) {
            printf("heart");
        } else if (a[i] % 4 == 2) {
            printf("diamond");
        } else if (a[i] % 4 == 3) {
            printf("club");
        }
        if (a[i] % 13 == 0) {
            printf("A");
        } else if (a[i] % 13 < 10) {
            printf("%d", a[i] % 13 + 1);
        } else if (a[i] % 13 == 10) {
            printf("J");
        } else if (a[i] % 13 == 11) {
            printf("Q");
        } else if (a[i] % 13 == 12) {
            printf("K");
        }
        if (i == 12 || i == 25 || i == 38) {
            printf("\n");
        } else printf(" ");
    }
    return 0;
}
```

### [11.](../programs/chapter8/8.11.c)

```c
#include <stdio.h>
#include <string.h>

#define maxn 1000
#define maxstr 100
struct timetable {
    char from[maxstr], to[maxstr];
    int distance, price, trainNo;
};

timetable timetable[maxn];

int main() {
    int n;
    for (int i = 0; i < n; i++)
        scanf("%s%s%d%d%d", timetable[i].from, timetable[i].to, &timetable[i].distance, &timetable[i].price,
              &timetable[i].trainNo);
    char from[maxstr], to[maxstr];
    scanf("%s%s", from, to);
    for (int i = 0; i < n; i++) {
        if (strcmp(from, timetable[i].from) == 0 && strcmp(to, timetable[i].to) == 0) {
            printf("yes\ndistance: %d price: %d train number: %d\n", timetable[i].distance, timetable[i].price,
                   timetable[i].trainNo);
            return 0;
        }
    }
    printf("no\n");
    return 0;
}
```
