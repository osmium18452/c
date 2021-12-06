#include<stdio.h>
#include<math.h>

int main() {
    double xmid,xmax=10.,xmin=-10.,fmid,fmax,fmin;
    do{
        xmid=(xmax+xmin)/2;
        fmid=xmid*xmid-6*xmid-1;
        fmax=xmax*xmax-6*xmax-1;
        fmin=xmin*xmin-6*xmin-1;
        if (fmid*fmin>0) xmin=xmid;
        else xmax=xmid;
    } while (xmax-xmin>0.000001);
    printf("%f %f %f",xmid, xmax, xmin);
    return 0;
}
