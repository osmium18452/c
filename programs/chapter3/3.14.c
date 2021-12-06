#include <stdio.h>
#include <string.h>

int main() {
    for (int a=1;a<7;a++){
        for (int b=0;b<7;b++){
            for (int c=1;c<7;c++){
                if (a*49+b*7+c==c*81+b*9+a){
                    printf("%d",a*49+b*7+c);
                }
            }
        }
    }
    return 0;
}
