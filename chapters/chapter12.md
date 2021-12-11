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
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    node *next;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    node *head1 = NULL, *head2 = NULL;
    while (n--) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &(p->val));
        p->next = head1;
        head1 = p;
    }
    while (m--) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &(p->val));
        p->next = head2;
        head2 = p;
    }
    node *q = head2;
    while (q != NULL) {
        node *p = head1, *prev = NULL;
        while (p != NULL) {

            if (p->val == q->val) {
                if (p == head1) {
                    head1 = p->next;
                    free(p);
                    p = head1;
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
        q = q->next;
    }
    node *p = head1;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}

```

### [6.](../programs/chapter12/12.6.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int val;
    node *next;
};

void push(node **head, int n) {
    node *p = (node *) malloc(sizeof(node));
    p->val = n;
    p->next = *head;
    *head = p;
}

int pop(node **head) {
    if (head == NULL) {
        printf("stack is empty");
        exit(-1);
    }
    int n = (*head)->val;
    node *p = (*head)->next;
    free(*head);
    (*head) = p;
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    node *head = NULL;
    while (n--) {
        char s[10];
        scanf("%s", s);
        if (strcmp(s, "push") == 0) {
            int t;
            scanf("%d", &t);
            push(&head, t);
        } else {
            printf("%d", pop(&head));
        }
    }
    return 0;
}

```

### 7.

CDEBA CDBAE CDBEA

### [8.](../programs/chapter12/12.8.c)

```c
#include <stdio.h>

int main() {
    char s[1000];
    int stack_ele_num = 0;
    scanf("%s", s);
    int i = 0;
    while (s[i] == 'I' || s[i] == 'O') {
        if (s[i] == 'I') stack_ele_num++;
        else {
            if (stack_ele_num > 0) stack_ele_num--;
            else {
                printf("illegal i/o");
                return 0;
            }
        }
        i++;
    }
    printf("legal i/o");
    return 0;
}
```

### [9.](../programs/chapter12/12.9.c)

```c
#include <stdio.h>

#define maxn 10000
char stack[maxn];

int main() {
    char s[maxn * 10];
    int top = 0;
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top++] = s[i];
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if ((stack[top - 1] == '(' && s[i] == ')') || (stack[top - 1] == '[' && s[i] == ']') ||
                (stack[top - 1] == '{' && s[i] == '}')) {
                top--;
            } else {
                printf("braces mismatch");
                return 0;
            }
        }
        i++;
    }
    printf("braces match");
    return 0;
}
```

### [10.](../programs/chapter12/12.10.c)

```c
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ERROR -1
#define TRUE 1
#define OK 0
#define STACK_INIT_SIZE 30
#define STACKINCREMENT 50
struct stack {
    int *bottom;
    int *top;
    int stacksize;
};

int InitStack(stack &S) {
    S.bottom = (int *) malloc(STACK_INIT_SIZE
                              * sizeof(char));
    if (!S.bottom) exit(OVERFLOW);
    S.
            top = S.bottom;
    S.
            stacksize = STACK_INIT_SIZE;
    return OK;
}

int push(stack &S, int ch) {
    if (S.top - S.bottom >= S.stacksize) {
        S.bottom = (int *) realloc(S.bottom, S.stacksize + STACKINCREMENT * sizeof(int));
        if (!S.bottom) exit(OVERFLOW);
        S.top = S.bottom + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top = ch;
    S.top = S.top + 1;
    return OK;
}

int pop(stack &S, int &ch) {
    if (S.top == S.bottom) return ERROR;
    ch = *(S.top - 1);
    S.top--;
    *(S.top) = 0;
    return OK;
}

int GetTop(stack &S) {
    int ch;
    if (S.top == S.bottom) return ERROR;
    ch = *(S.top - 1);
    return ch;
}

int IsOptr(char ch) {
    int i = 0;
    char optr[] = {'+', '-', '*', '/', '(', ')', '#', '@'};
    while (optr[i] != '@') {
        if (ch == optr[i]) return TRUE;
        i++;
    }
    return OK;
}

char Precede(int sym1, int sym2) {
    if (sym1 == '#' && sym2 == '#') return '=';
    else if (sym1 == '#' && sym2 == ')') exit(ERROR);
    else if (sym1 == '#') return '<';
    else if (sym1 == '(' && sym2 == '#') exit(ERROR);
    else if (sym2 == '#') return '>';
    else if (sym1 == ')' && sym2 == '(') exit(ERROR);
    else if (sym1 == ')') return '>';
    else if (sym1 == '(' && sym2 == ')') return '=';
    else if (sym2 == ')') return '>';
    else if (sym1 == '(') return '<';
    else if (sym2 == '(') return '<';
    else if (sym1 == '*' || sym1 == '/' || sym2 == '+' || sym2 == '-') return '>';
    else return '<';
}

int Operate(int a, int theta, int b) {
    if (theta == '+') return a + b;
    else if (theta == '-') return a - b;
    else if (theta == '*') return a * b;
    else if (theta == '/') {
        if (b == 0) {
            printf("该行除数为0，出错！");
            return NULL;
        } else return a / b;
    } else exit(ERROR);
}

FILE *fp;

int main() {
    stack OPTR, OPND;
    char c = '0';
    int x, theta, a, b;
    fp = fopen("../in.txt", "r");
    while (c != EOF) {
        InitStack(OPTR);
        push(OPTR, '#');
        InitStack(OPND);
        c = fgetc(fp);
        while (c != '#' || GetTop(OPTR) != '#') {
            if (!IsOptr(c)) {
                push(OPND, c - 48);
                c = fgetc(fp);
                while (!IsOptr(c)) {
                    pop(OPND, x);
                    push(OPND, x * 10 + c - 48);
                    c = fgetc(fp);
                }
            } else
                switch (Precede(GetTop(OPTR), c)) {
                    case '<':
                        push(OPTR, c);
                        c = fgetc(fp);
                        break;
                    case '=':
                        pop(OPTR, x);
                        c = fgetc(fp);
                        break;
                    case '>':
                        pop(OPTR, theta);
                        pop(OPND, b);
                        pop(OPND, a);
                        push(OPND, Operate(a, theta, b));
                        break;
                }
        }
        printf("%d\n", GetTop(OPND));
        c = fgetc(fp);
    }
    fclose(fp);
    return 0;
}

```

### [11.](../programs/chapter12/12.11.c)

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[] = {'A', 'B', 'C', 'D'};
    int top = 0;
    int train = 0;
    int stack[4];
    char c[10];
    for (int i = 0; i < 8; i++) {
        scanf("%s", c);
        if (strcmp(c, "in") == 0) {
            stack[top++] = s[train++];
        } else if (strcmp(c, "out") == 0) {
            if (top > 0) {
                printf("train %c out\n", stack[--top]);
            } else {
                printf("no train in station\n");
                return 0;
            }
        } else {
            printf("type in \"in\" or \"out\"\n");
        }
    }
    return 0;
}
```

### [12.](../programs/chapter12/12.12.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct node {
    int val;
    node *next;
};

void pop(node **head) {
    if (*head == NULL) {
        printf("queue is empty\n");
        return;
    }
    node *p = *head;
    *head = (*head)->next;
    printf("%d\n", p->val);
    free(p);
}

void push(node **tail, int val) {
    node *p = (node *) malloc(sizeof(node));
    p->val = val;
    p->next = NULL;
    (*tail)->next = p;
    *tail = p;
}

int main() {
    char s[10];
    node *head = NULL, *tail = NULL;
    while (true) {
        scanf("%s", s);
        if (strcmp(s, "quit") == 0) {
            break;
        } else if (strcmp(s, "push") == 0) {
            int t;
            scanf("%d", &t);
            if (head == NULL) {
                node *p = (node *) malloc(sizeof(node));
                p->next = NULL;
                p->val = t;
                tail = p;
                head = p;
            } else {
                push(&tail, t);
            }
        } else if (strcmp(s, "pop") == 0) {
            if (head == tail) tail = NULL;
            pop(&head);
        }
    }
    return 0;
}
```

### [13.](../programs/chapter12/12.13.c)

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int no;
    node *next;
};

int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &s, &m);
    if (m == 0) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        return 0;
    }
    node *head = NULL, *tail;
    for (int i = 0; i < n; i++) {
        node *p = (node *) malloc(sizeof(node));
        p->no = n - i;
        p->next = head;
        head = p;
        if (i == 0) tail = p;
    }
    tail->next = head;
    node *p = head, *prev = NULL;
    for (int i = 1; i < s; i++) p = p->next;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
        printf("%d ", p->no);
        free(p);
        p = prev->next;
    }
    return 0;
}

```

### [14.](../programs/chapter12/12.14.c)

```c
#include <stdio.h>
#include <string.h>

#define maxn 1000
int map[maxn][maxn];
int visited[maxn][maxn];
int queuex[maxn * 10], queuey[maxn * 10];
int prev[maxn * 10];
int path[maxn * 10];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    memset(visited, 0, sizeof(visited));
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int h = 0, t = 0;
    queuex[t] = x1;
    queuey[t++] = y1;
    visited[x1][y1] = true;
    bool found = false;
    while (h != t) {
        int x = queuex[h], y = queuey[h++];
        if (x == x2 && y == y2) {
            int cnt = 0;
            int i = h - 1;
            path[cnt++] = i;
            while (i != 0) {
                i = prev[i];
                path[cnt++] = i;
            }
            found = true;
            while (cnt--) {
                printf("(%d, %d) ", queuex[path[cnt]], queuey[path[cnt]]);
            }
            break;
        }
        if (x + 1 < n && !visited[x + 1][y] && map[x + 1][y] == 0) {
            queuex[t] = x + 1;
            queuey[t] = y;
            prev[t++] = h - 1;
            visited[x + 1][y] = true;
        }
        if (x - 1 >= 0 && !visited[x - 1][y] && map[x - 1][y] == 0) {
            queuex[t] = x - 1;
            queuey[t] = y;
            prev[t++] = h - 1;
            visited[x - 1][y] = true;
        }
        if (y + 1 < m && !visited[x][y + 1] && map[x][y + 1] == 0) {
            queuex[t] = x;
            queuey[t] = y + 1;
            prev[t++] = h - 1;
            visited[x][y + 1] = true;
        }
        if (y - 1 >= 0 && !visited[x][y - 1] && map[x][y - 1] == 0) {
            queuex[t] = x;
            queuey[t] = y - 1;
            prev[t++] = h - 1;
            visited[x][y - 1] = true;
        }
    }
    if (!found) printf("path not found");
    return 0;
}

/*
3 3
0 0 0
1 1 0
1 1 0
0 0 2 2
 */

```

### [15-19.](../programs/chapter12/12.15-19.c)

```c
#include <stdio.h>
#include <stdlib.h>

#define maxn 10000
struct node {
    int val;
    node *left, *right;
};

void preorder(node *root) {
    printf("%d ", root->val);
    if (root->left != NULL) preorder(root->left);
    if (root->right != NULL) preorder(root->right);
}

void inorder(node *root) {
    if (root->left != NULL) preorder(root->left);
    printf("%d ", root->val);
    if (root->right != NULL) preorder(root->right);
}

void postorder(node *root) {
    if (root->left != NULL) preorder(root->left);
    if (root->right != NULL) preorder(root->right);
    printf("%d ", root->val);
}

node *find(node *root, int val) {
    if (root->val == val) return root;
    if (root->left == NULL && root->right == NULL) return NULL;
    node *rtn = NULL;
    if (root->left != NULL) rtn = find(root->left, val);
    if (rtn != NULL) return rtn;
    if (root->right != NULL) rtn = find(root->right, val);
    return rtn;
}

int main() {
    int n;
    scanf("%d", &n);
    node *queue[maxn];
    int head = 0, tail = 0;
    node *root = (node *) malloc(sizeof(node));
    scanf("%d", &(root->val));
    queue[tail++] = root;
    n--;
    while (n > 0) {
        node *father = queue[head++];
        father->left = (node *) malloc(sizeof(node));
        scanf("%d", &(father->left->val));
        father->left->left = NULL;
        father->left->right = NULL;
        queue[tail++] = father->left;
        n--;
        if (n == 0) break;
        father->right = (node *) malloc(sizeof(node));
        scanf("%d", &(father->right->val));
        father->right->left = NULL;
        father->right->right = NULL;
        n--;
        if (n == 0) break;
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    int val;
    scanf("%d", &val);
    printf("0x%016x", find(root, val));
    return 0;
}
```

### [20.](../programs/chapter12/12.20.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define maxn 10000
struct node {
    int val;
    node *next;
};

void add(node *head, int val) {
    node *p = head;
    while (p->next != NULL) p = p->next;
    p->next = (node *) malloc(sizeof(node));
    p->next->next = NULL;
    p->next->val = val;
}

node *find(node *head, int val) {
    node *p = head;
    while (p != NULL) {
        if (p->val == val) return p;
        else p = p->next;
    }
    return NULL;
}

int main() {
    int n;
    node *head = NULL;
    scanf("%d", &n);
    while (n--) {
        node *p = (node *) malloc(sizeof(node));
        scanf("%d", &(p->val));
        p->next = head;
        head = p;
    }
    while (true) {
        char s[10];
        scanf("%s", s);
        if (strcmp(s, "quit") == 0) break;
        if (strcmp(s, "add") == 0) {
            int t;
            scanf("%d", &t);
            add(head, t);
        }
        if (strcmp(s, "find") == 0) {
            int t;
            scanf("%d", &t);
            node *p = find(head, t);
            printf("0x%016x\n", p);
        }
    }
    return 0;
}

```

### [21.](../programs/chapter12/12.21.c)

```c
#include <stdio.h>
#include <stdlib.h>

#define maxn 10000

struct node {
    int val;
    node *left, *right;
};
node *queue[maxn];

void preorder(node *root) {
    printf("%d ", root->val);
    if (root->left != NULL) preorder(root->left);
    if (root->right != NULL) preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        queue[i] = (node *) malloc(sizeof(node));
        scanf("%d", &(queue[i]->val));
        queue[i]->left = NULL;
        queue[i]->right = NULL;
    }
    for (int i = 1; i < n; i++) {
        int min1 = 0x3fffffff, min2 = 0x3fffffff;
        int p1 = -1, p2 = -1;
        for (int j = 0; j < n; j++) {
            if (queue[j] != NULL) {
                if (p1 == -1) {
                    min1 = queue[j]->val;
                    p1 = j;
                    continue;
                }
                if (queue[j]->val <= min1) {
                    min2 = min1;
                    min1 = queue[j]->val;
                    p2 = p1;
                    p1 = j;
                } else if (queue[j]->val <= min2) {
                    min2 = queue[j]->val;
                    p2 = j;
                }
            }
        }
        node *p = (node *) malloc(sizeof(node));
        p->left = queue[p1];
        p->right = queue[p2];
        p->val = p->left->val + p->right->val;
        queue[p1] = p;
        queue[p2] = NULL;
    }
    node *root;
    for (int i = 0; i < n; i++) {
        if (queue[i] != NULL) root = queue[i];
    }
    preorder(root);
    return 0;
}
```

### [22.](../programs/chapter12/12.22.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char s[30];
    node *father, *mother;
};

char s[10000];

node *parser(int left,int right) {
    int pos1= left + 1;
    while (s[pos1] != ','){
        pos1++;
    }
    node* p=(node* ) malloc(sizeof (node));
    strncpy(p->s,s+left+1, pos1 - left - 1);
    int pos2=pos1+2;
    int top=1;
    while (top>0){
        if (pos2=='(') top++;
        if (pos2==')') top--;
        pos2++;
    }
    printf("%c %c %d %d ",s[pos1],s[pos2],pos1,pos2);
    return NULL;
//    p->father= parser(pos1+1,pos2-1);
}

int main() {
    scanf("%s", s);
    parser(0,strlen(s)-1);
}
// (1,(),())
// TODO
```


