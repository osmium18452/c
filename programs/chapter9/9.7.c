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

