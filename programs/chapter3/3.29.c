#include<stdio.h>
int main()
{
    char a,b,c;
    for(a = 'x'; a <= 'z'; a++) {
        for(b = 'x'; b <= 'z'; b++) {
            if(a != b) {   //���������Ա�ظ�����
                for(c = 'x'; c <= 'z'; c++) {
                    if(a != c && b != c) {      //���������Ա�ظ�����
                        if(a != 'x' && c != 'x' && c != 'z') {   //���������ж�
                            printf("a with %c, b with %c, c with %c",a,b,c);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
