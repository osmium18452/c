#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stuff {
    int salary;
    char snum[10], name[30], sex[10], birth[10], email[30];
};

struct node {
    stuff sf;
    node *next;
};

node *load(char *filename, int *n) {
    node *head = NULL;
    FILE *f = fopen(filename, "rb");
    if (fread(n, sizeof(int), 1, f) == 1) {
        for (int i = 0; i < *n; i++) {
            node *p = (node *) malloc(sizeof(stuff));
            fread(&(p->sf), sizeof(stuff), 1, f);
            p->next = head;
            head = p;
        }
    }
    return head;
}

void save(char *filename, int n, node *head) {
    FILE *f = fopen(filename, "wb");
    fwrite(&n, sizeof(int), 1, f);
    while (head != NULL) {
        fwrite(&(head->sf), sizeof(stuff), 1, f);
        head = head->next;
    }
}

void print(node *head) {
    while (head != NULL) {
        printf("worker num: %s\nname: %s\nsex: %s\nbirthday: %s\nemail: %s\nsalary: %d\n\n", head->sf.snum,
               head->sf.name, head->sf.sex, head->sf.birth, head->sf.email, head->sf.salary);
        head = head->next;
    }
}

node *add(node *head, int *n) {
    (*n)++;
    node *p = (node *) malloc(sizeof(node));
    p->next = head;
    head = p;
    scanf("%s%s%s%s%s%d", head->sf.snum, head->sf.name, head->sf.sex, head->sf.birth, head->sf.email,
          &(head->sf.salary));
    return head;
}

node *del(node *head, int *n, char *snum) {
    if (strcmp(head->sf.snum, snum) == 0) {
        (*n)--;
        head = head->next;
    } else {
        node *p = head;
        node *prev = NULL;
        while (p != NULL && strcmp(p->sf.snum, snum) != 0) {
            prev = p;
            p = p->next;
        }
        if (p != NULL) {
            (*n)--;
            prev->next = p->next;
        }
    }
    return head;
}

void find(node *head, char *snum) {
    while (head != NULL && strcmp(head->sf.snum, snum) != 0) {
        head = head->next;
    }
    if (head == NULL) printf("cannot found");
    else {
        printf("worker num: %s\nname: %s\nsex: %s\nbirthday: %s\nemail: %s\nsalary: %d\n\n", head->sf.snum,
               head->sf.name, head->sf.sex, head->sf.birth, head->sf.email, head->sf.salary);
    }
}

int main() {
    int n = 2;
    node *head = NULL;
    char *filename = "test.bin";
    head = load(filename, &n);
    while (true) {
        char instr[20];
        scanf("%s", instr);
        if (strcmp(instr, "exit") == 0) break;
        else if (strcmp(instr, "find")) {
            char snum[30];
            scanf("%s", snum);
            find(head, snum);
        } else if (strcmp(instr, "del")) {
            char snum[30];
            scanf("%s", snum);
            head = del(head,&n, snum);;
        } else if (strcmp(instr, "add")) {
            head=add(head,&n);
        } else if (strcmp(instr, "print")) {
            print(head);
        }
    }
    save(filename, n, head);
    return 0;
}

//  use the code below to make a demo
/*
    node *head = NULL;
    node *p = (node *) malloc(sizeof(stuff));
    p->next = head;
    head = p;
    p->sf.salary = 100;
    strcpy(p->sf.email, "123@qq.com");
    strcpy(p->sf.birth, "19111111");
    strcpy(p->sf.sex, "man");
    strcpy(p->sf.name, "lmao");
    strcpy(p->sf.snum, "123456");
    p = (node *) malloc(sizeof(stuff));
    p->next = head;
    head = p;
    p->sf.salary = 1000;
    strcpy(p->sf.email, "666@qq.com");
    strcpy(p->sf.birth, "19221111");
    strcpy(p->sf.sex, "woman");
    strcpy(p->sf.name, "haha");
    strcpy(p->sf.snum, "654321");
    char *filename = "test.bin";
    save(filename, n, head);
    */