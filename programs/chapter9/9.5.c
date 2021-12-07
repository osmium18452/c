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
