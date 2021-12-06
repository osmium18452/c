#include<stdio.h>
int main()
{
    int x, y, z;
    for(x=0; x<=1; x++)
        for(y=0; y<=1; y++)
            for(z=0; z<=1; z++)
                if( ((x&&!y) || (!x&&y)) && ((y&&!z) || (!y&&z)) && ((z&&x==0&&y==0) || (!z&&x+y!=0)) )
                {
                    printf("zs told %s.\n",x?"the truth":"a lie");
                    printf("ls told %s.\n",y?"the truth":"a lie");
                    printf("ww told %s.\n",z?"the truth":"a lie");

                }
    return 0;
}
