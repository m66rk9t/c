## 《C Primer Plus》第5章练习题

#### 5.01 编写一个程序，根据国王与小麦的故事，计算每个棋格中的小麦数量，每格增长的数量并与世界小麦年产量进行粗略的比较。输出结果示例：

```
square  grains total  fraction of
   added  grains world total
1  1.00e+00    1.00e+00    5.00e-17
2  2.00e+00    3.00e+00    1.50e-16
...
That's all.
```

#### 5.02 编写一个程序，使用/运算符进行截断运算，输出结果示例：

```
integer division:  5/4is 1
integer division:  6/3is 2
integer division:  7/4is 1
floatint division: 7.0/4.0 is 1.75
mixed division:    7.0/4   is 1.75
```

#### 5.03 编写一个程序，对`-(2+5)*6+(4+3*(2+3))`表达式进行优先级测试并输出。

#### 5.04 编写一个程序，使用while迭代语句控制，将输入的秒数转换成以分钟和秒为单位的值并输出。当输入值小于0时结束循环，输出结果示例：

```
Please enter the number of seconds:
154
154 seconds is 2 minutes,34 seconds.
567
567 seconds is 9 minutes,27 seconds.
0
Done!
```

#### 5.05 编写一个程序，根据自动类型转换，观察数据类型的上溢和截断现象，输出结果示例：

```
ch=C,i=67,fl=67.00
ch=D,i=203,fl=339.00
Now ch=S
Now ch=P
```

#### 5.06 编写一个程序，使用明示常量根据编译时替换（compile-time substitution）原理，使用printf()函数观察输出，输出结果示例：

```
#define FORMAT "%s!LYFNB!\n"
...
printf(FORMAT,FORMAT);
...
```

#### 5.07 编写一个程序，使用递增运算符和while迭代语句，根据ASCII码值，打印A~G字母。

#### 5.08 编写一个程序，完成以下副作用：
+ 将变量x的值增加10
+ 将变量x的值增加1
+ 将a与b之和的两倍赋给c
+ 将a与b的两倍之和赋给c

#### 5.09 编写一个程序，完成以下副作用：
+ 将变量x的值减少1
+ 将n除以k的余数赋给m
+ q除以b减去a，并将结果赋给p
+ a与b之和除以c与d的乘积，并将结果赋给x

#### 5.10 编写一个程序，把用分钟表示的时间转换成用小时和分钟表示的时间。使用#define或const创建一个表示60的明示常量或const变量。通过while循环让用户重复输入值，直到输入用户输入小于或等于0的值才停止循环。

#### 5.11 编写一个程序，提示用户输入一个整数，然后打印从该数到比该数大10的所有整数。例如，用户输入5，则打印5~15的所有整数，包括5和15。要求打印的各值之间用一个空格、换行符或制表符分隔开。

#### 5.12 编写一个程序，提示用户输入天数，然后将其转换成周数和天数。例如，用户输入18，则转换成2周4天，通过while循环让用户重复输入天数，直到输入用户输入小于或等于0的值才停止循环。输出结果示例：

```
Please enter the number of days(<=0 to quit):
18
18 days are 2 weeks,4 days.
Please enter the number of days(<=0 to quit):
20
20 days are 2 weeks,6 days.
Please enter the number of days(<=0 to quit):
-1
Done!
```

#### 5.13 编写一个程序，提示用户输入一个身高（单位：厘米），并以英寸和英尺单位显示该值，允许有小数部分。通过while循环让用户重复输入身高，直到输入用户输入小于或等于0的值才停止循环。单位换算：1英寸=30.48厘米，1英寸=12英尺，1英尺=30.48/12厘米。输出结果示例：

```
Please enter your height(cm):
182
182.0 cm = 5 feet,11.7 inches
Please enter your height(<=0 to quit):
168.7
168.7 cm = 5 feet,6.4 inches
Please enter your height(<=0 to quit):
0
Done!
```

#### 5.14 编写一个程序，提示用户输入一个整数，并通过while循环求1到输入的值内所有整数之和。

#### 5.15 编写一各程序，提示用户输入一个整数，并通过while循环求1到输入的值内所有整数的平方和。

#### 5.16 编写一个程序，提示用户输入一个double类型的值，并打印该数的平方值。自己设计一个求平方值的函数并返回一个double类型的值。

#### 5.17 编写一个程序，提示用户输入两个整数，并显示求模运算的结果。把用户输入的第一个数作为求模运算的右项，该数在程序运行期间不会变。用户输入的第二个数作为求模运算的左项。通过while循环让用户重复输入左项的值，直到输入用户输入小于或等于0的值才停止循环。输出结果示例：

```
Please enter an integer to serve as the second operand:256
Now enter the first operand:438
438 % 256 is 182
Now enter next number for first operand(<=0 to quit):1234567
1234567 % 256 is 135
Now enter next number for first operand(<=0 to quit):0
Done!
```

#### 5.18 编写一个程序，提示用户输入一个摄氏度，并求对应的华氏度和开氏度值，类型均为double类型。用户定义Temperatures()函数求华氏度和开氏度值，并在函数内用printf()函数输出结果，显示结果精确到3位小数。三个温度的换算位：华氏度=摄氏温度/(5.0/9.0)+32.0，开氏度=摄氏度+273.16。Temperatures()函数内用const创建温度转换中使用的变量。在main()函数中通过while循环让用户反复输入多个值，通过scanf()函数的返回值判断是否进行新的循环，注意scanf()函数正确读取数据返回值为1，反之返回值为0。输出结果示例：

```
Please enter a floating-point number as Celsius:36.5
36.50C=97.70F=309.66K
Now enter the next floating-point number as Celsius:37.0
37.00C=98.60F=310.16K
Now enter the next floating-point number as Celsius:0
0.00C=32.00F=273.16K
Now enter the next floating-point number as Celsius:e
Done!
```