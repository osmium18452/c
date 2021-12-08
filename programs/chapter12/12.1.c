
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