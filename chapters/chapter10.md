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

### [7.](../programs/chapter10/10.7.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f1 = fopen("../in1.txt", "r");
    FILE *f2 = fopen("../in2.txt", "r");
    char a[100];
    char b[100];
    printf("             in1.txt | in2.txt\n");
    printf("---------------------+---------------------\n");
    while (true) {
        bool flaga = false, flagb = false;
        if (~fscanf(f1, "%[^\n]%*c", a)) {
            flaga = true;
        }
        if (~fscanf(f2, "%[^\n]%*c", b)) {
            flagb = true;
        }
        if (flaga && flagb) {
            printf("%20s |", a);
            printf(" %-20s\n", b);
        } else if (!flagb && !flaga) {
            break;
        } else {
            if (flaga) {
                printf("%20s |\n", a);
                while (~fscanf(f1, "%[^\n]%*c", a)) {
                    printf("%20s |\n", a);
                }
                break;
            } else if (flagb) {
                printf("                     | %-20s\n", b);
                while (~fscanf(f2, "%[^\n]%*c", b)) {
                    printf("                     | %-20s\n", b);
                }
                break;
            }
        }
    }
}

```

### [8.](../programs/chapter10/10.8.c)

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("in.txt", "rb");
    char c;
    int columncnt = 0;
    printf("+------------------------------------\n| ");
    while (true) {
        c = fgetc(f);
        if (c == EOF) {
            break;
        } else {
            if (columncnt % 4 == 0 && columncnt != 0 && columncnt % 16 != 0) printf(" ");
            if (columncnt % 16 == 0 && columncnt != 0) printf("\n| ");
            printf("%02X", c);
            columncnt++;
        }
    }
    return 0;
}
```

### [9.](../programs/chapter10/10.9.c)


```c
#include <stdio.h>

int main() {
    int a, b, c;
    char name[30], stdnum[30];
    FILE *f = fopen("out.txt", "w");
    for (int i = 0; i < 30; i++) {
        scanf("%s%s%d%d%d", stdnum, name, &a, &b, &c);
        fprintf(f, "%s %s %d %d %d\n", stdnum, name, a, b, c);
    }
    return 0;
}
```

### [10.](../programs/chapter10/10.10.c)

```c
//TODO
```

### [11.](../programs/chapter10/10.11.c)

```c
#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("in.c", "r");
    char s[100];
    int cnt = 0;
    while (~fscanf(f, "%s", s)) {
        if (strcmp(s, "int") == 0) cnt++;
        if (strcmp(s, "auto") == 0) cnt++;
        if (strcmp(s, "break") == 0) cnt++;
        if (strcmp(s, "case") == 0) cnt++;
        if (strcmp(s, "char") == 0) cnt++;
        if (strcmp(s, "const") == 0) cnt++;
        if (strcmp(s, "continue") == 0) cnt++;
        if (strcmp(s, "default") == 0) cnt++;
        if (strcmp(s, "do") == 0) cnt++;
        if (strcmp(s, "double") == 0) cnt++;
        if (strcmp(s, "else") == 0) cnt++;
        if (strcmp(s, "enum") == 0) cnt++;
        if (strcmp(s, "extern") == 0) cnt++;
        if (strcmp(s, "float") == 0) cnt++;
        if (strcmp(s, "for") == 0) cnt++;
        if (strcmp(s, "goto") == 0) cnt++;
        if (strcmp(s, "if") == 0) cnt++;
        if (strcmp(s, "long") == 0) cnt++;
        if (strcmp(s, "register") == 0) cnt++;
        if (strcmp(s, "return") == 0) cnt++;
        if (strcmp(s, "short") == 0) cnt++;
        if (strcmp(s, "signed") == 0) cnt++;
        if (strcmp(s, "sizeof") == 0) cnt++;
        if (strcmp(s, "static") == 0) cnt++;
        if (strcmp(s, "struct") == 0) cnt++;
        if (strcmp(s, "switch") == 0) cnt++;
        if (strcmp(s, "typedef") == 0) cnt++;
        if (strcmp(s, "unsigned") == 0) cnt++;
        if (strcmp(s, "union") == 0) cnt++;
        if (strcmp(s, "void") == 0) cnt++;
        if (strcmp(s, "volatile") == 0) cnt++;
        if (strcmp(s, "while") == 0) cnt++;
    }
    printf("%d", cnt);
    return 0;
}

```

### [12.](../programs/chapter10/10.12.c)

```c
//TODO
```

### [13.](../programs/chapter10/10.13.c)

```c
#include <stdio.h>

int state;

int c1, c2;

void change_state(int c) {
    if (state == 0) {
        if (c == '/') {
            state = 1;
        } else if (c == '"') {
            state = 5;
            putchar(c);
        } else if (c == '\'') {
            state = 6;
            putchar(c);
        } else {
            state = 0;
            putchar(c);
        }
    } else if (state == 1) {
        if (c == '/') {
            state = 2;
        } else if (c == '*') {
            state = 3;
        } else {
            state = 0;
            putchar(c1);
            putchar(c);
        }
    } else if (state == 2) {
        if (c == '\n') {
            state = 0;
            putchar(c);
        } else {
            state = 2;
        }
    } else if (state == 3) {
        if (c == '*') {
            state = 4;
        } else {
            state = 3;
        }
    } else if (state == 4) {
        if (c == '/') {
            state = 0;
        } else {
            state = 3;
        }
    } else if (state == 5) {
        if (c == '"') {
            state = 0;
            putchar(c);
        } else if (c == '\\') {
            state = 7;
            putchar(c);
        } else {
            state = 5;
            putchar(c);
        }
    } else if (state == 6) {
        if (c == '\'') {
            state = 0;
            putchar(c);
        } else if (c == '\\') {
            state = 8;
            putchar(c);
        } else {
            state = 6;
            putchar(c);
        }
    } else if (state == 7) {
        state = 5;
        putchar(c);
    } else if (state == 8) {
        state = 6;
        putchar(c);
    }
}

int main() {
    int c;
    state = 0;
    c1 = 0;
    c2 = 0;
    FILE *f = fopen("in.c", "r");
    while ((c = fgetc(f)) != EOF) {
        c1 = c2;
        c2 = c;
        change_state(c);
    }
}


```

### [14.](../programs/chapter10/10.14.c)

```c
// TODO
```

### [15.](../programs/chapter10/10.15.c)

```c
// TODO
```

### [16.](../programs/chapter10/10.16.c)

```c
// TODO
```

### [17.](../programs/chapter10/10.17.c)

```c
// TODO
```

### [18.](../programs/chapter10/10.18.c)

```c
// TODO
```


