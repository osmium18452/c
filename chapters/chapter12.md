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


