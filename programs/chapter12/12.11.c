#include <stdio.h>
#include <string.h>

int main() {
    char s[] = {'A', 'B', 'C', 'D'};
    int top = 0;
    int train = 0;
    int stack[4];
    char c[10];
    for (int i = 0; i < 8; i++) {
        scanf("%s", c);
        if (strcmp(c, "in") == 0) {
            stack[top++] = s[train++];
        } else if (strcmp(c, "out") == 0) {
            if (top > 0) {
                printf("train %c out\n", stack[--top]);
            } else {
                printf("no train in station\n");
                return 0;
            }
        } else {
            printf("type in \"in\" or \"out\"\n");
        }
    }
    return 0;
}