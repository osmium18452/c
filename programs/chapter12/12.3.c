
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