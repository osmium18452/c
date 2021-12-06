#include<stdio.h>
int main()
{
    char a,b,c;
    for(a = 'x'; a <= 'z'; a++) {
        for(b = 'x'; b <= 'z'; b++) {
            if(a != b) {   //避免参赛队员重复比赛
                for(c = 'x'; c <= 'z'; c++) {
                    if(a != c && b != c) {      //避免参赛队员重复比赛
                        if(a != 'x' && c != 'x' && c != 'z') {   //根据题意判断
                            printf("a with %c, b with %c, c with %c",a,b,c);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
