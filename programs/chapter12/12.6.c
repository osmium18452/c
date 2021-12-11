
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
