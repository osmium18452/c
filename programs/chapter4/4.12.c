#include <stdio.h>
inline unsigned char xchg(unsigned char n){
    return (n>>4)|(n<<4);
}
int main() {
    unsigned char n;
    scanf("%c",&n);
    printf("%x %x",n,xchg(n));
    return 0;
}
