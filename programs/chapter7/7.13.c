#include <stdio.h>
#include <string.h>

void visitint(void *p) {
    printf("%d ", *((int *) p));
}

void visitchar(void *p) {
    printf("%c ", *((char *) p));
}

void visitdouble(void *p) {
    printf("%lf ", *((double *) p));
}

void traverse(void *p, int n, void(*visit)(void *ep)) {
    for (int i = 0; i < n; i++) {
        visit((char*) p + i * (visit == visitchar ? sizeof(char) : (visit == visitint ? sizeof(int) : sizeof(double))));
    }
}


int main() {
    int a[]={1,2,3,4,5,6,7,8,9};
    traverse(a,9,visitint);
    printf("\n");
    double b[]={1.,2.,3.,4.,5.,6.,7.,8.,9.};
    traverse(b,9,visitdouble);
    printf("\n");
    char s[]="abcdefghi";
    traverse(s,9,visitchar);
    return 0;
}
