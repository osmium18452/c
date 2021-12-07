#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    node *next;
};

void save(node *head, char *name) {
    FILE *f = fopen(name, "w");
    node *p = head;
    while (p != NULL) {
        fprintf(f, "%d ", p->val);
        p = p->next;
    }
    fclose(f);
}

node *load(char *name) {
    node *head = NULL;
    FILE *f = fopen(name, "r");
    int a;
    while (~fscanf(f, "%d", &a)) {
        node *p = (node *) malloc(sizeof(node));
        p->val = a;
        p->next = head;
        head = p;
    }
    fclose(f);
    return head;
}

int main() {
    int n, a;
    scanf("%d", &n);
    node *head = NULL;
    while (n--) {
        scanf("%d", &a);
        node *p = (node *) malloc(sizeof(node));
        p->val = a;
        p->next = head;
        head = p;
    }
    char fileName[10] = "sv.txt";
    save(head, fileName);
    node *head2 = load(fileName);
    node *p = head2;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    return 0;
}

