## 《C Primer Plus》第15章练习题

#### 15.01 要用移位运算符来解决把数字转换为二进制形式的问题。读取用户从键盘输入的整数，将该整数和一个字符串地址传递给itobs()函数（itobs表示interger to binary string，即整数转换成二进制字符串）。然后，该函数使用移位运算符计算出正确的1和0的组合，并将其放入字符串中。输出示例：

```
Enter integers and see them in binary.
Non-numeric input terminates program.
7
7 is 0000 0000 0000 0000 0000 0000 0000 0111
2013
2013 is 0000 0000 0000 0000 0000 0111 1101 1101
-1
-1 is 1111 1111 1111 1111 1111 1111 1111 1111
32123
32123 is 0000 0000 0000 0000 0111 1101 0111 1011
q
Bye!
```

#### 15.02 修改15.02，添加一个函数用于切换一个值中的后n位，待处理值和n都是函数的参数。输出示例：

```
Enter integers and see them in binary.
Non-numeric input terminates program.
7
7 is
0000 0000 0000 0000 0000 0000 0000 0111
Inverting the last 4 bits gives
0000 0000 0000 0000 0000 0000 0000 1000
12541
12541 is
0000 0000 0000 0000 0011 0000 1111 1101
Inverting the last 4 bits gives
0000 0000 0000 0000 0011 0000 1111 0010
q
Bye!
```

#### 15.03 编写一个程序，输出方框的一些属性，并使用位字段来设置这些属性：

+ 方框是透明的或不透明的；
+ 方框的填充色选自以下调色板：黑色、红色、绿色、黄色、蓝色、紫色、青色或白色；
+ 边框可见或隐藏；
+ 边框颜色与填充色使用相同的调色板；
+ 边框可以使用实线、点线或虚线样式；

#### 输出示例：

```
Original box settings:
Box is opaque.
The fill color is yellow.
Border shown.
The border color is green.
The border style is dashed.

Modified box settings:
Box is transparent.
The fill color is white.
Border shown.
The border color is magenta.
The border style is solid.
```

#### 15.04 修改15.03,使用按位运算符代替位字段。输出示例：

```
Original box settings:
Box is opaque.
The fill color is yellow.
Border shown.
The border color is green.
The border style is dashed.
Box settings using unsigned int view:
box is opaque.
The fill color is yellow.
Border shown.
The border style is dashed.
The border color is green.
bits are 00000000000000000010010100000111
Modified box settings:
Box is transparent.
The fill color is cyan.
Border shown.
The border color is yellow.
The border style is dotted.
Box settings using unsigned int view:
box is transparent.
The fill color is cyan.
Border not shown.
The border style is dotted.
The border color is yellow.
bits are 00000000000000000001011100001100
```

#### 15.05 演示_Alignas和_Alignof的用法。输出示例：

```
char alignment: 1
double alignment: 8
&dx: 0x7fff5fbff660
&ca: 0x7fff5fbff65f
&cx: 0x7fff5fbff65e
&dz: 0x7fff5fbff650
&cb: 0x7fff5fbff64f
&cz: 0x7fff5fbff648
```

#### 15.06 编写一个函数，把二进制字符串转换为一个数值。例如，有下面的语句：

```c
char * pbin = "01001001";
```

#### 那么把pbin作为参数传递给该函数后，它应该返回一个int类型的值25。

#### 15.07 编写一个程序，通过命令行参数读取两个二进制字符串，对这两个二进制数使用～运算符、&运算符、|运算符和^运算符，并以二进制字符串形式打印结果（如果无法使用命令行环境，可以通过交互式让程序读取字符串）。

#### 15.08 编写一个函数，接受一个 int 类型的参数，并返回该参数中打开位的数量。在一个程序中测试该函数。

#### 15.09 编写一个程序，接受两个int类型的参数：一个是值；一个是位的位置。如果指定位的位置为1，该函数返回1；否则返回0。在一个程序中测试该函数。

#### 15.10 编写一个函数，把一个 unsigned int 类型值中的所有位向左旋转指定数量的位。例如，rotate_l(x,4)把x中所有位向左移动4个位置，而且从最左端移出的位会重新出现在右端。也就是说，把高阶位移出的位放入低阶位。在一个程序中测试该函数。

#### 15.11设计一个位字段结构以储存下面的信息。

+ 字体ID：0～255之间的一个数；
+ 字体大小：0～127之间的一个数；
+ 对齐：0～2之间的一个数，表示左对齐、居中、右对齐；
+ 加粗：开（1）或闭（0）；
+ 斜体：开（1）或闭（0）；

#### 在一个程序中使用该结构来打印字体参数，并使用循环菜单来让用户改变参数。例如，该程序的一个运行示例如下：

```
  ID SIZE ALIGNMENT   B   I   U
   1   12   left     off off off


f)change font    s)change size    a)change alignment
b)toggle bold    i)toggle italic  u)toggle underline
q)quit
s
Enter fone size(0-127): 36


  ID SIZE ALIGNMENT   B   I   U
   1   36   left     off off off


f)change font    s)change size    a)change alignment
b)toggle bold    i)toggle italic  u)toggle underline
q)quit
a
Select alignment:
l)left   c)center   r)right
r

  ID SIZE ALIGNMENT   B   I   U
   1   36  right     off off off


f)change font    s)change size    a)change alignment
b)toggle bold    i)toggle italic  u)toggle underline
q)quit
i

  ID SIZE ALIGNMENT   B   I   U
   1   36  right     off off off


f)change font    s)change size    a)change alignment
b)toggle bold    i)toggle italic  u)toggle underline
q)quit
q
Bye!
```

#### 该程序要使用按位与运算符（&）和合适的掩码来把字体ID和字体大小信息转换到指定的范围内。

#### 15.12 编写一个与编程练习15.11功能相同的程序，使用 unsigned long 类型的变量储存字体信息，并且使用按位运算符而不是位成员来管理这些信息。