#include <stdio.h>
#include <stdarg.h>

double avg(int first, ...) {
    int count = 0, sum = 0, i;
    va_list arg_ptr;
    va_start(arg_ptr, first);
    i = first;
    while (i != -1) {
        sum += i;
        count++;
        i = va_arg(arg_ptr, int);
    }
    va_end(arg_ptr);
    return count > 0 ? (double) sum / count : 0;
}
int main(){
    printf("%lf\n",avg(1,2,3,-1));
    printf("%lf\n",avg(7,8,9,10,-1));
    printf("%lf\n",avg(-1));
    return 0;
}

