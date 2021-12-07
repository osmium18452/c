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
