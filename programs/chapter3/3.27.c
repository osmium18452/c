#include <stdio.h>

int main() {
    int steps = 7;
    while (true) {
        if (steps % 2 == 1 && steps % 3 == 2 && steps % 5 == 4 && steps % 6 == 5){
            printf("%d",steps);
            break;
        } else {
            steps+=7;
        }
    }
    return 0;
}
