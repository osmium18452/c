#include <stdio.h>

int main() {
    double C,F;
    for (int i=-50;i<200;i++){
        F=(double )i;
        C=9*(F-32)/5;
        printf("F: %f C: %f\n",F,C);
    }
    return 0;
}
