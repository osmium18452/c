#include <stdio.h>
#include <stdlib.h>

struct node {
    int studentNum, age;
    char name[10], sex[10];
    node *next;
};

int main() {
    int n;
    scanf("%d", &n);
    node *head = NULL;
    for (int i = 0; i < n; i++) {
        node *q = (node *) malloc(sizeof(node));
        q->next = head;
        scanf("%d%s%s%d", &q->studentNum, q->name, q->sex, &q->age);
        head = q;
    }
    int age;
    scanf("%d", &age);
    node *p, *q;
    p=NULL;
    q=head;
    while (q!=NULL){
        if (q->age==age){
            if (p==NULL){
                q=head->next;
                free(head);
                head=q;
            } else {
                p->next=q->next;
                free(q);
                q=p->next;
            }
        } else{
            p=q;
            q=q->next;
        }
    }
    p=head;
    while (p!=NULL){
        printf("%d %s %s %d\n",p->studentNum,p->name,p->sex,p->age);
        p=p->next;
    }
    return 0;
}

