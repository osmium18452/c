#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess(){
    srand(time(0));
    int number=rand()%101;
    int gue;
    for (int i=0;i<5;i++){
        scanf("%d",&gue);
        if (gue==number) {
            printf("ok\n");
            return ;
        } else {
            if (gue>number) printf("bigger\n");
            else printf("smaller\n");
        }
    }
    printf("good game. the number is %d", number);
}
int main() {
    guess();
    return 0;
}
