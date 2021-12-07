#include <stdio.h>
#include <stdlib.h>

struct node {
    int studentNum, postCode, qq;
    char name[10], sex[10], birthDay[10], address[30], tel[11];
    node *next;
};

void add(node **head) {
    node *p = (node *) malloc(sizeof(node));
    scanf("%d%s%s%s%d%s%d%s", &p->studentNum, p->name, p->sex, p->birthDay, &p->postCode, p->address, &p->qq, p->tel);
    p->next = *head;
    *head = p;
}

void del(node *head) {
    node *p, *q;
    int stdNum;
    scanf("%d", stdNum);
    p = NULL;
    q = head;
    while (q != NULL) {
        if (q->studentNum == stdNum) {
            if (p == NULL) {
                q = head->next;
                free(head);
                head = q;
            } else {
                p->next = q->next;
                free(q);
                q = p->next;
            }
        } else {
            p = q;
            q = q->next;
        }
    }
}

void find(node *head) {
    node *p = head;
    int stdNum;
    bool found = 0;
    scanf("%d", stdNum);
    while (p != NULL) {
        if (p->studentNum == stdNum) {
            printf("%d %s %s %s %d %s %d %s\n", p->studentNum, p->name, p->sex, p->birthDay, p->postCode, p->address,
                   p->qq, p->tel);
            found = true;
        } else p = p->next;
    }
    if (!found) {
        printf("not found\n");
    }
}

void print(node *head) {
    node *p = head;
    while (p != NULL) {
        printf("%d %s %s %s %d %s %d %s\n", p->studentNum, p->name, p->sex, p->birthDay, p->postCode, p->address,
               p->qq, p->tel);
        p=p->next;
    }
}

int main() {
    node *head = NULL;
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        else if (n == 1) add(&head);
        else if (n == 2) del(head);
        else if (n == 3) find(head);
        else if (n == 4) print(head);
    }
}


