#include<stdio.h>
int main()
{
    int m, n, number=0;
    printf(" red white black\n");
    printf("......................\n");
    for( m=0; m<=3; m++ )
        for( n=0; n<=3; n++ )
            if(8-m-n<=6)
                printf(" %2d: %d %d %d\n", ++number, m, n, 8-m-n);
    return 0;
}
