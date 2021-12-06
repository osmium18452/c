#include <cstdio>

int main(){
    char c=getchar();
    if (c>='0'&&c<='9') printf("number");
    else if (c>='A'&&c<='Z') printf("upper case letter");
    else if (c>='a'&&c<='z') printf("lower case letter");
    else if (c=='+'||c=='-'||c=='*'||c=='/') printf("arithmetic operator");
    else if (c=='<'||c=='>') printf("relation operator");
    else if (c=='!') printf("logical operator");
    else printf("other character");
}
