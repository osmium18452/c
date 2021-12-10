
#include <stdio.h>
#include <stdlib.h>

struct node {
    float coef;
    int exp;
    struct node *next;
};


node *CreateList(int n)
{
    node *head = (node *) malloc(sizeof(node)), *p, *pre = head;
    float coef;
    int exp;
    head->next = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%f%d", &coef, &exp);
        p->coef = coef;
        p->exp = exp;
        p->next = NULL;

        pre->next = p;
        pre = p;
    }
    return head;
}

int printflist(node *head)
{
    node *p = head->next;
    while (p->next != NULL) {
        printf("%1.1f*X^%d+", p->coef, p->exp);
        p = p->next;
    }
    printf("%1.1f*X^%d\n", p->coef, p->exp);
    return 0;
}


int InverseList(node *head)
{
    node *p = head->next, *q;
    head->next = NULL;
    while (p) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
    return 0;
}

node *MultiplisePoly(node *head_a, node *head_b)
{
    node *head_c, *pa = head_a, *pb = head_b, *pc, *newnode;
    int exp_max;
    if (pa->next != NULL && pb->next != NULL)
        exp_max = pa->next->exp + pb->next->exp;
    else return NULL;

    head_c = (node *) malloc(sizeof(node));
    head_c->coef = 0.0;
    head_c->exp = 0;
    head_c->next = NULL;
    pc = head_c;
    InverseList(head_b);
    float ceof = 0.0;
    for (int k = exp_max; k >= 0; k--) {
        pa = head_a->next;
        while (pa != NULL && pa->exp > k)
            pa = pa->next;
        pb = head_b->next;
        while (pa != NULL && pb != NULL && pa->exp + pb->exp < k)
            pb = pb->next;

        while (pa != NULL && pb != NULL) {
            if (k == pa->exp + pb->exp) {
                ceof += pa->coef * pb->coef;
                pa = pa->next;
                pb = pb->next;
            } else {
                if (pa->exp + pb->exp < k)
                    pb = pb->next;
                else
                    pa = pa->next;
            }

        }
        if (ceof != 0.0) {

            newnode->coef = ceof;
            newnode->exp = k;
            newnode->next = NULL;

            pc->next = newnode;
            pc = newnode;
            ceof = 0.0;
        }
    }

    InverseList(head_b);
    return head_c;
}


int main()
{
    int n;
    scanf("%d", &n);
    node *head_a = CreateList(n);
    scanf("%d", &n);
    node *head_b = CreateList(n);
    node *head_c = MultiplisePoly(head_a, head_b);
    printflist(head_c);
    return 0;
}
