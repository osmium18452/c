### 1.

参见例题

### 2.

参见例题

### 3.

参见例题

### 4.

[单链表：](../programs/chapter9/9.4.1.c)
```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    node *next;
    int a;
};
struct head {
    node *next;
};

void invert(head *h) {
    node *rec = h->next;
    while (rec->next != NULL) {
        node *p = rec->next;
        rec->next = rec->next->next;
        p->next = h->next;
        h->next = p;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    head h;
    h.next = NULL;
    while (n--) {
        int a;
        scanf("%d", &a);
        node *p = (node *) malloc(sizeof(node));
        p->next=h.next;
        h.next=p;
        p->a=a;
    }
    printf("the original chain: ");
    node* p=h.next;
    while (p!=NULL){
        printf("%d ",p->a);
        p=p->next;
    }
    putchar('\n');
    invert(&h);
    printf("the inverted chain: ");
    p=h.next;
    while (p!=NULL){
        printf("%d ",p->a);
        p=p->next;
    }
    putchar('\n');
    return 0;
}
```
[双链表：](../programs/chapter9/9.4.2.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    node *next;
    node *prev;
    int a;
};
struct head {
    node *next;
    node *prev;
};

void invert(head *h) {
    node *rec = h->next;
    while (rec->next != NULL) {
        node *p = rec->next;
        rec->next = rec->next->next;
        p->next = h->next;
        p->prev=h->prev;
        h->next->prev=p;
        h->next = p;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    head h;
    h.next = NULL;
    while (n--) {
        int a;
        scanf("%d", &a);
        node *p = (node *) malloc(sizeof(node));
        p->next = h.next;
        p->prev=h.prev;
        if (h.next!=NULL) h.next->prev=p;
        h.next = p;
        p->a = a;
    }
    printf("the original chain: ");
    node *p = h.next;
    while (p != NULL) {
        printf("%d ", p->a);
        p = p->next;
    }
    putchar('\n');
    invert(&h);
    printf("the inverted chain: ");
    p = h.next;
    while (p != NULL) {
        printf("%d ", p->a);
        p = p->next;
    }
    putchar('\n');
    return 0;
}
```

### [5.](../programs/chapter9/9.5.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    node *next;
    int a;
};
struct head {
    node *next;
};

void invert(head *h) {
    node *rec = h->next;
    while (rec->next != NULL) {
        node *p = rec->next;
        rec->next = rec->next->next;
        p->next = h->next;
        h->next = p;
    }
}


void insert(head *h, int a) {
    node *p = (node *) malloc(sizeof(node));
    p->next = h->next;
    h->next = p;
    p->a = a;
}

void sort(head *h) {
    node *sorted = h->next;
    while (sorted != NULL) sorted = sorted->next;
    while (sorted != h->next) {
        node *p = h->next;
        while (p->next != sorted) {
            if (p->a > p->next->a) {
                int t = p->a;
                p->a = p->next->a;
                p->next->a = t;
            }
            p=p->next;
        }
        sorted = p;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    head h;
    h.next = NULL;
    while (n--) {
        int a;
        scanf("%d", &a);
        insert(&h, a);
    }
    invert(&h);
    printf("the original chain: ");
    node *p = h.next;
    while (p != NULL) {
        printf("%d ", p->a);
        p = p->next;
    }
    putchar('\n');
    sort(&h);
    printf("the sorted chain: ");
    p = h.next;
    while (p != NULL) {
        printf("%d ", p->a);
        p = p->next;
    }
    putchar('\n');
    return 0;
}
```

### [6.](../programs/chapter9/9.6.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    node *next,*prev;
    int a;
};
struct head {
    node *next;
};

void invert(head *h) {
    node *rec = h->next;
    while (rec->next != NULL) {
        node *p = rec->next;
        rec->next = rec->next->next;
        p->next = h->next;
        p->prev=NULL;
        h->next->prev=p;
        h->next = p;
    }

}


void insert(head *h, int a) {
    node *p = (node *) malloc(sizeof(node));
    p->next = h->next;
    if (p->next!=NULL) p->next->prev=p;
    p->prev=NULL;
    h->next = p;
    p->a = a;
}

void sort(head *h) {
    node *sorted = h->next;
    while (sorted != NULL) sorted = sorted->next;
    while (sorted != h->next) {
        node *p = h->next;
        while (p->next != sorted) {
            if (p->a < p->next->a) {
                int t = p->a;
                p->a = p->next->a;
                p->next->a = t;
            }
            p=p->next;
        }
        sorted = p;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    head h;
    h.next = NULL;
    while (n--) {
        int a;
        scanf("%d", &a);
        insert(&h, a);
    }
    invert(&h);
    printf("the original chain: ");
    node *p = h.next;
    while (p != NULL) {
        printf("%d ", p->a);
        p = p->next;
    }
    putchar('\n');
    sort(&h);
    printf("the sorted chain: ");
    p = h.next;
    while (p != NULL) {
        printf("%d ", p->a);
        p = p->next;
    }
    putchar('\n');
    return 0;
}
```

### [7.](../programs/chapter9/9.7.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    node *next;
    int a;
};
struct head {
    node *next;
};

void invert(head *h) {
    node *rec = h->next;
    while (rec->next != NULL) {
        node *p = rec->next;
        rec->next = rec->next->next;
        p->next = h->next;
        h->next = p;
    }
}


void insert(head *h, int a) {
    node *p = (node *) malloc(sizeof(node));
    p->next = h->next;
    h->next = p;
    p->a = a;
}

void pop(head *h) {
    h->next = h->next->next;
}

head *merge(head *h1, head *h2, head *h3) {
    node *p1, *p2;
    h3->next = NULL;
    p1 = h1->next;
    p2 = h2->next;
    while (p1 != NULL && p2 != NULL) {
        if (p1->a < p2->a) {
            pop(h1);
            p1->next = h3->next;
            h3->next = p1;
            p1 = h1->next;
        } else {
            pop(h2);
            p2->next = h3->next;
            h3->next = p2;
            p2 = h2->next;
        }
    }
    while (p1 != NULL) {
        pop(h1);
        p1->next = h3->next;
        h3->next = p1;
        p1 = h1->next;
    }
    while (p2 != NULL) {
        pop(h2);
        p2->next = h3->next;
        h3->next = p2;
        p2 = h2->next;
    }
    invert(h3);
}

int main() {
    int n, m;
    scanf("%d", &n);
    head h1;
    h1.next = NULL;
    while (n--) {
        int a;
        scanf("%d", &a);
        insert(&h1, a);
    }
    scanf("%d", &m);
    head h2;
    h2.next = NULL;
    while (m--) {
        int a;
        scanf("%d", &a);
        insert(&h2, a);
    }
    invert(&h1);
    invert(&h2);
    head h3;
    merge(&h1, &h2, &h3);
    printf("the merged chain: ");
    node *p = h3.next;
    while (p != NULL) {
        printf("%d ", p->a);
        p = p->next;
    }
    putchar('\n');
    return 0;
}

```

### 8.

略

### [9.](../programs/chapter9/9.9.c)

```c
#include <stdio.h>
struct node{
    bool visited;
    node* next;
};
node* createList();
bool findLoop(node* head){
    node* p=head;
    while (p!=NULL){
        if (p->visited) {
            return true;
        } else {
            p->visited= true;
            p=p->next;
        }
    }
    return false;
}
int main(){
    node* head=createList();
    if (findLoop(head)) printf("yes\n");
    else printf("no\n");
    return 0;
}

```

### [10.](../programs/chapter9/9.10.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    node *next;
};

node *find(node *head, int a) {
    while (head != NULL) {
        if (head->data == a) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    node *a = NULL, *b = NULL;
    for (int i = 0; i < n; i++) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &p->data);
        p->next = a;
        a = p;
    }
    for (int i = 0; i < m; i++) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &p->data);
        p->next = b;
        b = p;
    }
    node *c = NULL, *d = NULL;
    node *p = a;
    while (p != NULL) {
        if (find(b, p->data) == NULL) {
            node *q = (node *) malloc(sizeof(node));
            q->next = c;
            q->data = p->data;
            c = q;
        }
        p = p->next;
    }
    p = b;
    while (p != NULL) {
        if (find(a, p->data) == NULL) {
            node *q = (node *) malloc(sizeof(node));
            q->next = d;
            q->data = p->data;
            d = q;
        }
        p = p->next;
    }
    node *ans = NULL;
    p = c;
    while (p != NULL) {
        node *q = (node *) malloc(sizeof(node));
        q->data = p->data;
        q->next = ans;
        ans = q;
        p = p->next;
    }
    p = d;
    while (p != NULL) {
        if (find(ans, p->data) == NULL) {
            node *q = (node *) malloc(sizeof(node));
            q->data = p->data;
            q->next = ans;
            ans = q;
        }
        p = p->next;
    }
    p = ans;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
    return 0;
}

```

### [11.](../programs/chapter9/9.11.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int studentNum, age;
    char name[10], sex[10];
    node *next;
};

int main() {
    int n;
    scanf("%d", &n);
    node *head = NULL;
    for (int i = 0; i < n; i++) {
        node *q = (node *) malloc(sizeof(node));
        q->next = head;
        scanf("%d%s%s%d", &q->studentNum, q->name, q->sex, &q->age);
        head = q;
    }
    int age;
    scanf("%d", &age);
    node *p, *q;
    p=NULL;
    q=head;
    while (q!=NULL){
        if (q->age==age){
            if (p==NULL){
                q=head->next;
                free(head);
                head=q;
            } else {
                p->next=q->next;
                free(q);
                q=p->next;
            }
        } else{
            p=q;
            q=q->next;
        }
    }
    p=head;
    while (p!=NULL){
        printf("%d %s %s %d\n",p->studentNum,p->name,p->sex,p->age);
        p=p->next;
    }
    return 0;
}

```

### [12.](../programs/chapter9/9.12.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int studentNum, postCode, qq;
    char name[10], sex[10], birthDay[10], address[30], tel[11];
    node *next;
};

void add(node **head) {
    node *p = (node *) malloc(sizeof(node));
    scanf("%d%s%s%s%d%s%d%s", &p->studentNum, p->name, p->sex, p->birthDay, &p->postCode, p->address, &p->qq, p->tel);
    p->next = *head;
    *head = p;
}

void del(node *head) {
    node *p, *q;
    int stdNum;
    scanf("%d", stdNum);
    p = NULL;
    q = head;
    while (q != NULL) {
        if (q->studentNum == stdNum) {
            if (p == NULL) {
                q = head->next;
                free(head);
                head = q;
            } else {
                p->next = q->next;
                free(q);
                q = p->next;
            }
        } else {
            p = q;
            q = q->next;
        }
    }
}

void find(node *head) {
    node *p = head;
    int stdNum;
    bool found = 0;
    scanf("%d", stdNum);
    while (p != NULL) {
        if (p->studentNum == stdNum) {
            printf("%d %s %s %s %d %s %d %s\n", p->studentNum, p->name, p->sex, p->birthDay, p->postCode, p->address,
                   p->qq, p->tel);
            found = true;
        } else p = p->next;
    }
    if (!found) {
        printf("not found\n");
    }
}

void print(node *head) {
    node *p = head;
    while (p != NULL) {
        printf("%d %s %s %s %d %s %d %s\n", p->studentNum, p->name, p->sex, p->birthDay, p->postCode, p->address,
               p->qq, p->tel);
        p=p->next;
    }
}

int main() {
    node *head = NULL;
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        else if (n == 1) add(&head);
        else if (n == 2) del(head);
        else if (n == 3) find(head);
        else if (n == 4) print(head);
    }
}


```

### [13.](../programs/chapter9/9.13.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int code;
    char city[20];
    node *next;
};

void search(node *head, char *s) {
    node *q = head;
    while (q != NULL) {
        if (strcmp(s, q->city) == 0) {
            printf("%d\n", q->code);
            return;
        }
    }
    printf("not found\n");
}

void insert(node **head, int code, char *city) {
    node *q = (node *) malloc(sizeof(node));
    q->code=code;
    strcpy(q->city,city);
    q->next=*head;
    *head=q;
}

int main() {
    node *head;
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            char s[20];
            scanf("%s", s);
            search(head, s);
        } else if (n == 2) {
            char s[20];
            int code;
            scanf("%d%s", &code, s);
            insert(&head, code, s);
        } else if (n == 0) {
            break;
        }
    }
    return 0;
}

```

### [14.](../programs/chapter9/9.14.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 1000

struct node {
    int val;
    int x;
    node *next, *previous;
};

node *head[maxn];

void insert(int x, int y, int val) {
    node *q = head[y];
    if (q == NULL) {
        node *p = (node *) malloc(sizeof(node));
        p->x = x;
        p->val = val;
        p->next = NULL;
        p->previous = NULL;
        head[y] = p;
    } else {
        while (q->x < x && q != NULL) {
            q = q->next;
        }
        if (q == NULL) {
            q = head[y];
            while (q->x < x && q->next != NULL) {
                q = q->next;

            }
            node *p = (node *) malloc(sizeof(node));
            p->x = x;
            p->val = val;
            p->next = NULL;
            p->previous = q;
            q->next = p;
        } else {
            node *p = (node *) malloc(sizeof(node));
            p->x = x;
            p->val = val;
            p->next = q;
            p->previous = q->previous;
            q->previous->next = p;
            q->previous = p;
        }
    }
}

int sum(int x1, int y1, int x2, int y2) {
    int ans = 0;
    for (int i = y1; i <= y2; i++) {
        node *q = head[i];
        while (q->x < x1) {
            q = q->next;
        }
        while (q->x <= x2) {
            ans += q->val;
            q = q->next;
        }
    }
    return ans;
}

double avg(int x1, int y1, int x2, int y2) {
    double ans = 0;
    int cnt = 0;
    for (int i = y1; i <= y2; i++) {
        node *q = head[i];
        while (q->x < x1) {
            q = q->next;
        }
        while (q->x <= x2) {
            ans += q->val;
            q = q->next;
            cnt++;
        }
    }
    return ans / cnt;
}

int main() {
    memset(head, 0, sizeof(head));
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        } else if (n == 1) {
            int x, y, val;
            scanf("%d%d%d", &x, &y, &val);
            insert(x, y, val);
        } else if (n == 2) {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            sum(x1, y1, x2, y2);
        } else if (n == 3) {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            avg(x1, y1, x2, y2);
        }
    }
    return 0;
}
```
