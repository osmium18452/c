#include <stdio.h>

int main() {
    char s[1000];
    int stack_ele_num = 0;
    scanf("%s", s);
    int i = 0;
    while (s[i] == 'I' || s[i] == 'O') {
        if (s[i] == 'I') stack_ele_num++;
        else {
            if (stack_ele_num > 0) stack_ele_num--;
            else {
                printf("illegal i/o");
                return 0;
            }
        }
        i++;
    }
    printf("legal i/o");
    return 0;
}