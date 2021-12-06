
#include <stdio.h>

int main() {
    int a1=1,a2=1,a3;
    int sn,sn_1=2;
    for (int i=3;i<1000;i++){
        a3=a1+a2;
        sn=sn_1+a3;
        if (sn>=100&&sn_1<100) printf("%d ",i);
        if (sn>=1000&&sn_1<1000) printf("%d ",i);
        if (sn>=10000&&sn_1<10000) {
            printf("%d ", i);
            break;
        }
        sn_1=sn;
        a1=a2;
        a2=a3;
    }
    return 0;
}
