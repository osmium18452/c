#include<stdio.h>

int main() {
    int n, k, x, y, cc, pc;
    pc = cc = 0;
    printf("How many mountains are there?\n\n");
    scanf("%d", &n);
    printf("How many mountains are allowed to move each time?\n");
    scanf("%d", &k);
    do {
        printf("How many mountains do you wish move away?\n");
        scanf("%d", &x);
        if (x < 1 || x > k || x > n) {
            printf("Illegal number,type in another please!\n");
            continue;
        }
        n -= x;
        printf("There are %d mountains left now.\n", n);
        if (!n) {
            printf("I win.\n\n");
            cc++;
        } else {
            y = (n - 1) % (k + 1);
            if (!y)
                y = 1;
            n -= y;
            printf("Copmputer move %d mountains away.\n", y);
            if (n)
                printf(" There are %d mountains left now.\n", n);
            else {
                printf("You win\n\n");
                pc++;
            }
        }
    } while (n);
    return 0;
}

