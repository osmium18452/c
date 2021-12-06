#include <stdio.h>
#ifdef RELEASE
int main(){
    double ans=0.,init=10.;
    for (int i=0;i<10;i++){
        ans+=init;
        init/=2;
        if (i==9) printf("total: %lf current: %lf\n",ans,init);
        ans+=init;
    }
    return 0;
}
#endif
#ifdef DEBUG
int main(){
    double ans=0.,init=10.;
    for (int i=0;i<10;i++){
        ans+=init;
        init/=2;
        if (i==9) printf("total: %lf current: %lf\n",ans,init);
        ans+=init;
        printf("time: %d total: %lf current: %lf\n",i,ans,init);
    }
    return 0;
}
#endif
