## 第三章

### 1.

#### (1)

①`printf("%d %u %o %x\n%d %u %o %x\n%d %u %o %x\n",128,128,128,128,-128,-128,-128,-128,3456789,3456789,3456789,3456789);`
<br>
②`printf("%f %e\n%f %e\n", 3.1415926, 3.1415926, 12345678.123456789, 12345678.123456789);`<br>
③`printf("%c %d\n%c %d\n", 'X', 'X', 65, 65);`<br>
④`printf("\%")`<br>

#### (2)

①`printf("%-5d %-5d %-5d %5d %5d %5d", 456, -123, 987654, 456, -123, 987654);`<br>
②`printf("%-10.6e\n%-10.6e\n%10.6e\n%10.6e\n", (double) 666666, (double) 55555, (double) 666666, (double) 55555);`<br>
③`printf("%-14.6e\n%-14.6e\n%14.6e\n%14.6e\n", 3.1415926, 12.3456, 3.1415926, 12.3456);`<br>
④

``` c
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int width,accuracy;
    char format[100000]="%";
    char buffer[100];
    scanf("%d%d",&width,&accuracy);
    itoa(width,buffer,10);
    strcat(format,buffer);
    strcat(format,".");
    itoa(accuracy,buffer,10);
    strcat(format,buffer);
    strcat(format,"f %");
    itoa(width,buffer,10);
    strcat(format,buffer);
    strcat(format,".");
    itoa(accuracy,buffer,10);
    strcat(format,buffer);
    strcat(format,"f ");
    printf(format,98.16054,77.676767);
    return 0;
}
```

### 2.

### 3.

### 4.

### 5.

### 6.

### 7.

### 8.

### 9.

### 10.

### 11.

### 12.

### 13.

### 14.

### 15.

### 16.

### 17.

### 18.

### 19.

### 20.

### 21.

### 22.

### 23.

### 24.

### 25.

### 26.

### 27.

### 28.

### 29.

### 30.