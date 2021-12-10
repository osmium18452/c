
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    node *next;
};

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
    int x, y;
    scanf("%d%d", &x, &y);
    node *p = head;
    node *prev = NULL;
    while (p != NULL) {
        if (p->val >= x && p->val <= y) {
            if (p == head) {
                p = p->next;
                free(head);
                head = p;
            } else if (p->next == NULL) {
                prev->next = NULL;
                free(p);
                break;
            } else {
                prev->next = p->next;
                free(p);
                p = prev->next;
            }
        } else {
            prev = p;
            p = p->next;
        }
    }

    p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}