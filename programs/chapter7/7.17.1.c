#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[]) {
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    if (strcmp(argv[3],"min")==0) printf("%d",a>b?b:a);
    else if (strcmp(argv[3],"max")==0) printf("%d",a>b?a:b);
    else printf("illegal paramater");
    return 0;
}


