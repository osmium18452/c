
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char s[30];
    node *father, *mother;
};

char s[10000];

node *parser(int left,int right) {
    int pos1= left + 1;
    while (s[pos1] != ','){
        pos1++;
    }
    node* p=(node* ) malloc(sizeof (node));
    strncpy(p->s,s+left+1, pos1 - left - 1);
    int pos2=pos1+2;
    int top=1;
    while (top>0){
        if (pos2=='(') top++;
        if (pos2==')') top--;
        pos2++;
    }
    printf("%c %c %d %d ",s[pos1],s[pos2],pos1,pos2);
    return NULL;
//    p->father= parser(pos1+1,pos2-1);
}

int main() {
    scanf("%s", s);
    parser(0,strlen(s)-1);
}
// (1,(),())