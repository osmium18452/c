#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int code;
    char city[20];
    node *next;
};

void search(node *head, char *s) {
    node *q = head;
    while (q != NULL) {
        if (strcmp(s, q->city) == 0) {
            printf("%d\n", q->code);
            return;
        }
    }
    printf("not found\n");
}

void insert(node **head, int code, char *city) {
    node *q = (node *) malloc(sizeof(node));
    q->code=code;
    strcpy(q->city,city);
    q->next=*head;
    *head=q;
}

int main() {
    node *head;
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 1) {
            char s[20];
            scanf("%s", s);
            search(head, s);
        } else if (n == 2) {
            char s[20];
            int code;
            scanf("%d%s", &code, s);
            insert(&head, code, s);
        } else if (n == 0) {
            break;
        }
    }
    return 0;
}

