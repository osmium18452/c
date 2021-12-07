#include <stdio.h>
#include <string.h>

void front(char* s){
    while (*s=='*'){
        for (int i=0;s[i]!='\0';i++){
            s[i]=s[i+1];
        }
    }
}
void middle(char* s){
    while (*s=='*') s++;
    while (*s!='*') s++;
    while (*s=='*'){
        for (int i=0;s[i]!='\0';i++){
            s[i]=s[i+1];
        }
    }
}

void back(char* s){
    for (int i=strlen(s)-1;s[i]=='*';i--){
        s[i]=0;
    }
}

int main(int argc,char* argv[]) {
    char s[]="***123***456***";
    back(s);
    printf("%s",s);
    return 0;
}
