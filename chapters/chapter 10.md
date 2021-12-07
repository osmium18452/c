### [1.](../programs/chapter10/10.1.c)

```c
#include <stdio.h>

int main(){
    freopen("/out.txt","w",stdout);
    for (int i=1;i<10;i++){
        for (int j=1;j<=i;j++){
            printf("%d*%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
    return 0;
}

```

### [2.](../programs/chapter10/10.2.c)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("in.txt", "r", stdin);
    int cnt = 1;
    char a[1000];
    while (fgets(a, 999, stdin)) {
        printf("%d %s", cnt, a);
        cnt++;
    }
    return 0;
}

```

### [3.](../programs/chapter10/10.3.c)

```c
#include <stdio.h>
#include <string.h>

struct ele {
    char s[100];

    bool operator<(const ele s1) {
        if (strcmp(this->s, s1.s) < 0) return true;
        else return false;
    }
};

int main() {
    freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    ele a[1000];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i].s);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                char tmp[100];
                strcpy(tmp, a[j].s);
                strcpy(a[j].s, a[j + 1].s);
                strcpy(a[j + 1].s, tmp);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i].s);
    }
    return 0;
}

```

### [4.](../programs/chapter10/10.4.c)

```c
#include <stdio.h>
#include <string>
#include <stdlib.h>

using std::string;
using std::to_string;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string name = "data";
        if (i < 10) {
            name = name + "0" + to_string(i) + ".txt";
        } else {
            name = name + to_string(i) + ".txt";
        }
        freopen(name.c_str(), "r", stdin);
        int cnt = 0;
        int line = 0;
        char a;
        while ((a = getchar()) != EOF) {
            if (a == '\n') line++;
            cnt++;
        }
        printf("doc: %s, line: %d, letter: %d\n", name.c_str(), line, cnt);
    }
    return 0;
}

```

### [5.](../programs/chapter10/10.5.c)

```c
#include <stdio.h>

int main() {
    FILE *in=fopen("in.txt","r");
    FILE *out=fopen("out.txt","a+");
    char a;
    while ((a=fgetc(in))!=EOF){
        fputc(a,out);
    }
    return 0;
}

```

### [6.](../programs/chapter10/10.6.c)

```c
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

```
