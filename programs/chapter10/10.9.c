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