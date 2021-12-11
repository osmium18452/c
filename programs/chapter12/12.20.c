
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
