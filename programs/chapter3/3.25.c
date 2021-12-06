#include <stdio.h>

int main() {
    double capital=0.;
    for (int i=0;i<5;i++){
        capital=(capital+1000)/(1+12*.00063);
    }
    printf("%.2f",capital);
    return 0;
}
