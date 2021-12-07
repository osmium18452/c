#include <stdio.h>

int main() {
    FILE *in=fopen("in.txt","r");
    FILE *out=fopen("out.txt","a+");
    char a;
    while ((a=fgetc(in))!=EOF){
        fputc(a,out);
    }
    return 0;
}

