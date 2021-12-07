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
