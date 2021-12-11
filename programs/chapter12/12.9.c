#include <stdio.h>

#define maxn 10000
char stack[maxn];

int main() {
    char s[maxn * 10];
    int top = 0;
    scanf("%s", s);
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top++] = s[i];
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if ((stack[top - 1] == '(' && s[i] == ')') || (stack[top - 1] == '[' && s[i] == ']') ||
                (stack[top - 1] == '{' && s[i] == '}')) {
                top--;
            } else {
                printf("braces mismatch");
                return 0;
            }
        }
        i++;
    }
    printf("braces match");
    return 0;
}
