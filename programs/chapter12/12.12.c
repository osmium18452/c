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