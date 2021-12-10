### [1.](../programs/chapter12/12.1.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    node *next;
};

int main() {
    node *head = NULL, *tail = NULL;
    int n;
    scanf("%d", &n);
    head = (node *) malloc(sizeof(node));
    scanf("%d", &(head->val));
    head->next = NULL;
    tail = head;
    for (int i = 1; i < n; i++) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &(p->val));
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    int k;
    scanf("%d", &k);
    node *p = head;
    node *prev = NULL;
    while (p != NULL && k >= p->val) {
        prev = p;
        p = p->next;
    }
    if (prev == NULL) {
        p = (node *) malloc(sizeof(node));
        p->val = k;
        p->next = head;
        head = p;
    } else if (p == NULL) {
        tail->next = (node *) malloc(sizeof(node));
        tail->next->next = NULL;
        tail->next->val = k;
        tail = tail->next;
    } else {
        prev->next = (node *) malloc(sizeof(node));
        prev->next->next = p;
        prev->next->val = k;
    }
    p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}
```

### [2.](../programs/chapter12/12.2.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    node *next;
};

int main() {
    int n;
    scanf("%d", &n);
    node *head = NULL;
    while (n--) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &(p->val));
        p->next = head;
        head = p;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    node *p = head;
    node *prev = NULL;
    while (p != NULL) {
        if (p->val >= x && p->val <= y) {
            if (p == head) {
                p = p->next;
                free(head);
                head = p;
            } else if (p->next == NULL) {
                prev->next = NULL;
                free(p);
                break;
            } else {
                prev->next = p->next;
                free(p);
                p = prev->next;
            }
        } else {
            prev = p;
            p = p->next;
        }
    }

    p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}
```

### [3.](../programs/chapter12/12.3.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
int val;
node *next;
};

void del(node *head, int n) {
node *p = head, *q = NULL;
while (p != NULL) {
if (p->val == n) {
if (p->next==NULL&&p==head) break;
if (p->next == NULL) {
if (q!=NULL) q->next = NULL;
free(p);
break;
} else if (p == head) {
q = p;
p = p->next;
} else {
q->next = p->next;
free(p);
p = q->next;
}
} else {
q = p;
p = p->next;
}
}
}

int main() {
int n;
scanf("%d", &n);
node *head = NULL;
while (n--) {
node *p = (node *) malloc(sizeof(node));
scanf("%d", &(p->val));
p->next = head;
head = p;
}
node *p = head, *q;
head = NULL;
while (p != NULL) {
q = p->next;
p->next = head;
head = p;
p = q;
}
p = head;
while (p != NULL) {
del(p, p->val);
p = p->next;
}

p = head;
while (p != NULL) {
printf("%d ", p->val);
p = p->next;
}
return 0;
}
```

### [4.](../programs/chapter12/12.4.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    float coef;
    int exp;
    struct node *next;
};


node *CreateList(int n)
{
    node *head = (node *) malloc(sizeof(node)), *p, *pre = head;
    float coef;
    int exp;
    head->next = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%f%d", &coef, &exp);
        p->coef = coef;
        p->exp = exp;
        p->next = NULL;

        pre->next = p;
        pre = p;
    }
    return head;
}

int printflist(node *head)
{
    node *p = head->next;
    while (p->next != NULL) {
        printf("%1.1f*X^%d+", p->coef, p->exp);
        p = p->next;
    }
    printf("%1.1f*X^%d\n", p->coef, p->exp);
    return 0;
}


int InverseList(node *head)
{
    node *p = head->next, *q;
    head->next = NULL;
    while (p) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
    return 0;
}

node *MultiplisePoly(node *head_a, node *head_b)
{
    node *head_c, *pa = head_a, *pb = head_b, *pc, *newnode;
    int exp_max;
    if (pa->next != NULL && pb->next != NULL)
        exp_max = pa->next->exp + pb->next->exp;
    else return NULL;

    head_c = (node *) malloc(sizeof(node));
    head_c->coef = 0.0;
    head_c->exp = 0;
    head_c->next = NULL;
    pc = head_c;
    InverseList(head_b);
    float ceof = 0.0;
    for (int k = exp_max; k >= 0; k--) {
        pa = head_a->next;
        while (pa != NULL && pa->exp > k)
            pa = pa->next;
        pb = head_b->next;
        while (pa != NULL && pb != NULL && pa->exp + pb->exp < k)
            pb = pb->next;

        while (pa != NULL && pb != NULL) {
            if (k == pa->exp + pb->exp) {
                ceof += pa->coef * pb->coef;
                pa = pa->next;
                pb = pb->next;
            } else {
                if (pa->exp + pb->exp < k)
                    pb = pb->next;
                else
                    pa = pa->next;
            }

        }
        if (ceof != 0.0) {

            newnode->coef = ceof;
            newnode->exp = k;
            newnode->next = NULL;

            pc->next = newnode;
            pc = newnode;
            ceof = 0.0;
        }
    }

    InverseList(head_b);
    return head_c;
}


int main()
{
    int n;
    scanf("%d", &n);
    node *head_a = CreateList(n);
    scanf("%d", &n);
    node *head_b = CreateList(n);
    node *head_c = MultiplisePoly(head_a, head_b);
    printflist(head_c);
    return 0;
}

```

### [5.](../programs/chapter12/12.5.c)

```c

```

### [6.](../programs/chapter12/12.6.c)

```c

```

### [7.](../programs/chapter12/12.7.c)

```c

```

### [8.](../programs/chapter12/12.8.c)

```c

```

### [9.](../programs/chapter12/12.9.c)

```c

```

### [10.](../programs/chapter12/12.10.c)

```c

```

### [11.](../programs/chapter12/12.11.c)

```c

```

### [12.](../programs/chapter12/12.12.c)

```c

```

### [13.](../programs/chapter12/12.13.c)

```c

```

### [14.](../programs/chapter12/12.14.c)

```c

```

### [15.](../programs/chapter12/12.15.c)

```c

```

### [16.](../programs/chapter12/12.16.c)

```c

```

### [17.](../programs/chapter12/12.17.c)

```c

```

### [18.](../programs/chapter12/12.18.c)

```c

```

### [19.](../programs/chapter12/12.19.c)

```c

```

### [20.](../programs/chapter12/12.20.c)

```c

```

### [21.](../programs/chapter12/12.21.c)

```c

```

### [22.](../programs/chapter12/12.22.c)

```c

```


