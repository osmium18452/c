#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxstr 100
#define maxn 1000
struct node {
    int bookno;
    node *next;
};
struct list {
    char s[maxstr];
    node *next;
};

int main() {
    freopen("../in.txt", "r", stdin);
    int bookno;
    char s[maxstr];
    list list[maxn];
    int cnt = 0;
    while (~scanf("%d", &bookno)) {
        gets(s);
        int slen = strlen(s);
        char buf[maxstr];
        int r = 0, l = 0;
        for (int i = 0; i <= slen; i++) {
            if (s[i] == ' ' || s[i] == '\0') {
                l = r;
                r = i;
                if (r - l - 1 > 0) {
                    memset(buf, 0, sizeof(buf));
                    strncpy(buf, s + l + 1, r - l - 1);
                    bool found = 0;
                    for (int j = 0; j < cnt; j++) {
                        if (strcmp(list[j].s, buf) == 0) {
                            found = 1;
                            node *p = list[j].next;
                            bool foundbookno = false;
                            if (p->bookno == bookno) foundbookno = true;
                            while (p->next != NULL) {
                                if (p->bookno == bookno) foundbookno = true;
                                p = p->next;
                            }
                            if (!foundbookno) {
                                p->next = (node *) malloc(sizeof(node));
                                p->next->next = NULL;
                                p->next->bookno = bookno;
                                break;
                            }
                        }
                    }
                    if (!found) {
                        strcpy(list[cnt].s, buf);
                        list[cnt].next = (node *) malloc(sizeof(node));
                        list[cnt].next->next = NULL;
                        list[cnt].next->bookno = bookno;
                        cnt++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        printf("%s ", list[i].s);
        node *p = list[i].next;
        while (p != NULL) {
            printf("%d ", p->bookno);
            p = p->next;
        }
        printf("\n");
    }
    return 0;
}
