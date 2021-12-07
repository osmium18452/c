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
