## 第二章

### 1.

||八进制|十六进制|
|---|---|---|
|10|012|0xA|
|31|037|0x1F|
|65|0101|0x41|
|127|0177|0x7F|
|-128|-0200|-0x80|
|-625|-01161|-0x271|
|-111|-0157|-0x6F|
|12345|030071|0x3039|
|-25536|-061700|-0x63C0|
|32767|077777|0x7FFF|
|65535|0177777|0xFFFF|
|255|0377|0xFF|

### 2.

|变量类型|-32768|-128|-1|168|32767|65535|2147483647|
|---|---|---|---|---|---|---|---|
|int|FFFF8000|FFFFFF80|FFFFFFFF|000000A8|00007FFF|0000FFFF|7FFFFFFF|
|unsigned int|FFFF8000|FFFFFF80|FFFFFFFF|000000A8|00007FFF|0000FFFF|7FFFFFFF|
|short|8000|FF80|FFFF|00A8|7FFF|FFFF|FFFF|
|unsigned short|8000|FF80|FFFF|00A8|7FFF|FFFF|FFFF|
|char|00|80|FF|A8|FF|FF|FF|
|unsigned char|00|80|FF|A8|FF|FF|FF|

### 3.

在C语言编写的程序中，如果使用了某标识符，那么应该确定之前已有该标识符的定义或声明，否则会导致语法错误。

### 4.

(1)①23 ②1 <br>
(2)1 <br>
(3)①4 ②19 ③15 ④160 ⑤1 <br>
(4)22 <br>
(5)①0 ②2 ③3 <br>
(6)5 <br>
(7)9 <br>
(8)①false ②true ③true <br>
(9)6 <br>
(10)88 <br>
(11)①80 ②9 <br>
(12)-40 <br>
(13)1.23 <br>
(14)1 <br>
(15)①5 ②10 ③11 <br>
(16)false <br>
(17)undefined y <br>
(18)①24 ②10 ③60 ④0 ⑤24 ⑥0 <br>

### 5.

(1)`(x+y)*(x+y)*(x+y)` <br>
(2)`a*100+b*10+c` <br>
(3)
①`x*x*x*x*x*x-2*x*x*x*x*x+3*x*x*x*x+4*x*x*x-5*x*x+6*x+7` <br>
②`0.5*(a*x+(a+x)/(4*a))` <br>
③`3*a*e/(b*c)` <br>
(4)`a+b+c-x-y` <br>
(5)`a>b?b:a` <br>
(6)`(y%4==0&&y%100!=0)||(y%400==0&&y%100==0)` <br>
(7)`x*y*z>0&&(x*y<0||x*z<0)` <br>
(8)`n<m&&n%2==0` <br>
(9)`2*b==a+c||2*a==b+c||2*c==a+b` <br>
(10)`n<100&&n>9&&((int)n==n)` <br>



