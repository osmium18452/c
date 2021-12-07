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

