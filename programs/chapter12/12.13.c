
#include <stdio.h>
#include <stdlib.h>

struct node {
    int no;
    node *next;
};

int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &s, &m);
    if (m == 0) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        return 0;
    }
    node *head = NULL, *tail;
    for (int i = 0; i < n; i++) {
        node *p = (node *) malloc(sizeof(node));
        p->no = n - i;
        p->next = head;
        head = p;
        if (i == 0) tail = p;
    }
    tail->next = head;
    node *p = head, *prev = NULL;
    for (int i = 1; i < s; i++) p = p->next;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
        printf("%d ", p->no);
        free(p);
        p = prev->next;
    }
    return 0;
}
