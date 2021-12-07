
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
