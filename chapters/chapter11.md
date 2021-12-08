### 1.

程序段1: 2 <br>
程序段2: 3 `*` n


### 2.

程序段1: `O(n^2)` <br>
程序段2: `O(n*2^n)` <br>
程序段3: `O(n^(3/2))`

### 3.

程序段1: `O(n^(1/2))` <br>
程序段2: `O(log(n))` <br>
程序段3: `O(n^2)`

### 4.

程序段1: `O(1)` <br>
程序段2: `O(1)` <br>
程序段3: `O(1)`

### 5.

冒泡排序： `O(n^2)` <br>
选择排序： `O(n^2)` <br>
插入排序： `O(n^2)` <br>
快速排序： `O(nlogn)` <br>
顺序查找： `O(n)` <br>
二分查找： `O(logn)`

### 6.

`O(2^n)`

### [7.](../programs/chapter11/11.7.c)

```c
#include<stdio.h>
#include<math.h>
#define eps 1e-4
#define INF_MIN -200;
#define INF_MAX 200;
int main() {

    double a;
    double b;
    double c;
    double d;
    double x_01;
    double x_02;
    double l;
    double r;
    double mid;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    x_01 = (-b - sqrt(b * b - 3 * a * c)) / (3 * a);
    x_02 = (-b + sqrt(b * b - 3 * a * c)) / (3 * a);
    if (a > 0) {

        l = INF_MIN;
        r = x_01;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)l = mid;
            else r = mid;
        }
        printf("%.2f ", l);
        l = x_01;
        r = x_02;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)r = mid;
            else l = mid;
        }
        printf("%.2f ", l);
        l = x_02;
        r = INF_MAX;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)l = mid;
            else r = mid;
        }
        printf("%.2f", l);
    } else if (a < 0) {

        l = INF_MIN;
        r = x_02;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)r = mid;
            else l = mid;
        }
        printf("%.2f ", l);
        l = x_02;
        r = x_01;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)l = mid;
            else r = mid;
        }
        printf("%.2f ", l);
        l = x_01;
        r = INF_MAX;
        while (l + eps < r) {

            mid = (l + r) / 2;
            if (a * mid * mid * mid + b * mid * mid + c * mid + d < 0)r = mid;
            else l = mid;
        }
        printf("%.2f", l);
    }
}
```

### [8.](../programs/chapter11/11.8.c)

```c
#include<stdio.h>

#define maxn 1000

void Show(int *a, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

void Merge(int *a, int left, int m, int right) {
    int aux[maxn] = {0};
    int i;
    int j;
    int k;

    for (i = left, j = m + 1, k = 0; k <= right - left; k++) {
        if (i == m + 1) {
            aux[k] = a[j++];
            continue;
        }
        if (j == right + 1) {
            aux[k] = a[i++];
            continue;
        }
        if (a[i] < a[j]) {
            aux[k] = a[i++];
        } else {
            aux[k] = a[j++];
        }
    }
    for (i = left, j = 0; i <= right; i++, j++) {
        a[i] = aux[j];
    }
}

void MergeSort(int *a, int start, int end) {
    if (start < end) {
        int i;
        i = (end + start) / 2;
        MergeSort(a, start, i);
        MergeSort(a, i + 1, end);
        Merge(a, start, i, end);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[maxn];
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    MergeSort(a, 0, n - 1);
    Show(a, n);
    return 0;
}
```

### 9.

1. 将硬币等分成两组，留下较轻的一组
2. 将较轻的一组再分成两组，留下较轻的一组
3. 将2中较轻的一组分成两组，留下较轻的一组
4. 剩下两个中较轻的一个就是假的

### [10.](../programs/chapter11/11.10.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int C1 = 0;
    int C2 = 0;
    int num = 0;
    bool *x = NULL;
    int **m = NULL;
    int *w = NULL;

    printf("capability of first ship:");
    scanf("%d", &C1);

    printf("capability of second ship:");
    scanf("%d", &C2);


    printf("cargo num:");
    scanf("%d", &num);

    x = (bool *) malloc((num + 1) * sizeof(bool));
    w = (int *) malloc((num + 1) * sizeof(int));

    m = (int **) malloc((num + 1) * sizeof(int *));
    for (int i = 0; i <= num; i++) {
        m[i] = (int *) malloc((C1 + 1) * sizeof(int));
    }
    printf("cargo weight\n");

    for (int i = 1; i <= num; i++) {
        scanf("%d", w + i);
    }

    for (int i = 1; i <= num; i++) {
        m[i][0] = 0;
    }

    for (int i = 1; i < C1 + 1; i++) {
        if (w[num] > i) {
            m[num][i] = 0;
            x[num] = false;
        } else {
            m[num][i] = w[num];
            x[num] = true;
        }
    }

    for (int i1 = num - 1; i1 >= 1; i1--) {
        for (int j = 1; j <= C1; j++) {
            if (w[i1] > j) {
                m[i1][j] = m[i1 + 1][j];
                x[i1] = false;
            } else {
                int temW = w[i1] + m[i1 + 1][j - w[i1]];
                if (temW > m[i1 + 1][j]) {
                    m[i1][j] = temW;
                    x[i1] = true;
                } else {
                    m[i1][j] = m[i1 + 1][j];
                    x[i1] = false;
                }
            }
        }
    }
    int max = m[1][1];
    for (int i = 1; i <= C1; i++) {
        if (m[1][i] > max && m[1][i] <= C1)
            max = m[1][i];
    }
    int totalW = 0;
    for (int i = 1; i <= num; i++) {
        totalW += w[i];
    }
    if (totalW - max <= C2) printf("yes");
    else printf("no");

    return 0;
}
```

### [11.](../programs/chapter11/11.11.c)

```c
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    double x, y;
};

bool same(double a, double b) {
    if (fabs(a - b) <= 1e-5) return true;
    return false;
}

bool cmpx(node a, node b) {
    if (!same(a.x, b.x)) return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(node a, node b) {
    if (!same(a.y, b.y)) return a.y < b.y;
    return a.x < b.x;
}

const int maxn = 200000 + 6;
node arr[maxn];
#define sqr(A) ((A)*(A))

double dist(node a, node b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double mind(int L, int R) {
    sort(arr + L, arr + R + 1, cmpx);
    double ans = 1e300;
    if (R - L + 1 <= 3) {
        for (int i = L; i <= R; i++) {
            for (int j = i + 1; j <= R; j++) {
                ans = min(ans, dist(arr[i], arr[j]));
            }
        }
    } else {
        int mid = (L + R) / 2;
        double midx = arr[mid].x;
        ans = min(ans, mind(L, mid));
        ans = min(ans, mind(mid + 1, R));
        vector<node> avai;
        avai.clear();
        for (int i = L; i <= R; i++) {
            if (fabs(arr[i].x - midx) <= ans) avai.push_back(arr[i]);
        }
        double dnow = 1e300;
        sort(avai.begin(), avai.end(), cmpy);
        for (int i = 0; i < avai.size(); i++) {
            for (int j = i + 1; j < avai.size(); j++) {
                double d = dist(avai[i], avai[j]);
                if (d > ans && !same(d, ans)) break;

                dnow = min(dnow, d);
            }
        }
        ans = min(ans, dnow);
        avai.clear();
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &arr[i].x, &arr[i].y);
    double ans = mind(1, n);
    printf("%.4lf\n", ans);
    return 0;
}
```

### [12.](../programs/chapter11/11.12.c)

```c
#include <stdio.h>
#include <stdlib.h>
#define maxn 200

void InitTable(int *table, int table_rank) {
    for (int i = 0; i < table_rank; ++i) {
        for (int j = 0; j < table_rank; ++j)
            *(table + i * table_rank + j) = 0;
    }
    for (int i = 0; i < table_rank; ++i) {
        *(table + i * table_rank + 0) = i + 1;
    }
}

void GSchedule(int *table, int table_rank,
               int r1, int c1, int r2, int c2, int n) {
    if (n >= 2) {
        for (int i = 0; i < n; ++i) {
            if (*(table + (r2 - i) * table_rank + c2) == 0)
                *(table + (r2 - i) * table_rank + c2)
                        = *(table + (r1 + i) * table_rank + c1);
            else
                *(table + (r1 + i) * table_rank + c1)
                        = *(table + (r2 - i) * table_rank + c2);
        }
        int mr = (r2 - r1) / 2;
        int mc = (c2 - c1) / 2;
        n /= 2;
        GSchedule(table, table_rank, r1, c1, r1 + mr, c1 + mc, n);
        GSchedule(table, table_rank, r1, c1 + mc + 1, r1 + mr, c2, n);
        GSchedule(table, table_rank, r1 + mr + 1, c1, r2, c1 + mc, n);
        GSchedule(table, table_rank, r1 + mr + 1, c1 + mc + 1, r2, c2, n);
    }
}

void GameSchedule(int *table, int table_rank) {
    InitTable(table, table_rank);
    GSchedule(table, table_rank,
              0, 0, table_rank - 1, table_rank - 1, table_rank);
}


void PrintTable(int *table, int table_rank) {
    for (int i = 0; i < table_rank; ++i) {
        for (int j = 0; j < table_rank; ++j)
            printf("%d ",*(table + i * table_rank + j));
        printf("\n");
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    int *table = (int*) malloc(sizeof (int)*n*n);
    GameSchedule(table, n);
    PrintTable(table, n);
    free(table);
    return 0;
}

```

### [13.](../programs/chapter11/11.13.c)

```c
#include <stdio.h>
#define maxn 1000
#define inf 10000000
int main(){
    int a[maxn];
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int max=-inf,max2=-inf;
    for (int i=0;i<n;i++) {
        if (a[i]>=max) {
            max2=max;
            max=a[i];
        } else if (a[i]>max2){
            max2=a[i];
        }
    }
    printf("%d %d",max,max2);
    return 0;
}
```

### [14.](../programs/chapter11/11.14.c)

```c
#include <stdio.h>

#define maxn 1000
#define len(a) (sizeof(a) / sizeof(a[0]))

int lis(int arr[], int len) {
    int longest[maxn];
    for (int i = 0; i < len; i++)
        longest[i] = 1;

    for (int j = 1; j < len; j++) {
        for (int i = 0; i < j; i++) {
            if (arr[j] > arr[i] && longest[j] < longest[i] + 1) {
                longest[j] = longest[i] + 1;
            }
        }
    }

    int max = 0;
    for (int j = 0; j < len; j++) {
        if (longest[j] > max) max = longest[j];
    }
    return max;
}

int main() {
    int arr[] = {1, 4, 5, 6, 2, 3, 8};
    int ret = lis(arr, len(arr));
    printf("%d", ret);
    return 0;
}
```

### [15.](../programs/chapter11/11.15.c)

```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    cnt += n / 100;
    n = n % 100;
    cnt += n / 50;
    n = n % 50;
    cnt += n / 20;
    n = n % 20;
    cnt += n / 10;
    n = n % 10;
    cnt += n / 5;
    n = n % 5;
    cnt += n / 2;
    cnt += n % 2;
    printf("%d", cnt);
}
```

### [16.](../programs/chapter11/11.16.c)

```c
#include <stdio.h>

#define maxn 10000

int main() {
    int n, k;
    char a[maxn];
    scanf("%d%d", &n, &k);
    scanf("%s", a);
    a[n] = '\0';
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n - i + 1; j++) {
            if (a[j] < a[j - 1]) {
                for (int l = j; l <= n - i + 1; l++) {
                    a[l - 1] = a[l];
                }
                break;
            }
        }
    }
    printf("%s", a);
    return 0;
}
```

### [17.](../programs/chapter11/11.17.c)

```c

```

### [18.](../programs/chapter11/11.18.c)

```c

```


