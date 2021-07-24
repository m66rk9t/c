## 《C Primer Plus》第6章练习题

#### 6.01 编写一个程序，提示用户输入类型的整数（long类型），并通过while循环重复输入，使用scanf()函数的返回值判断测试条件的真假，输入'q'则退出循环，输出结果示例：

```
Please enter an integer number:44
Please enter an integer number(enter 'q' to quit):33
Please enter an integer number(enter 'q' to quit):88
Please enter an integer number(enter 'q' to quit):121
Please enter an integer number(enter 'q' to quit):q
Done! The sum of the integers entered is 286.
```

#### 6.02 编写一个程序，通过while循环测试表达式的值，并观察何为真何为假，输出结果示例：

```
3 is true
2 is true
1 is true
0 is false
-3 is true
-2 is true
-1 is true
0 is false
```

#### 6.03 编写一个程序，定义一个符号常量PI表示PI的值（3.14159），提示用户输入一个double类型的数来表示用户认为PI的值，通过while循环重复输入寻找最接近PI的值，使用fabs()函数判断是否接近并进入新的迭代，fabs()函数定义在math.h头文件中，输出结果示例：

```
What is the value of PI?
3.14
Try again!
3.141
Try again!
3.1415
Close enough!
```

#### 6.04 编写一个程序，提示用户输入类型的整数（long类型），通过while循环重复输入，并使用bool类型的变量测试表达式的真值，输入'q'则退出循环，输出结果示例：

```
Please enter an integer number:44
Please enter an integer number(enter 'q' to quit):33
Please enter an integer number(enter 'q' to quit):88
Please enter an integer number(enter 'q' to quit):121
Please enter an integer number(enter 'q' to quit):q
Done! The sum of the integers entered is 286.
```

#### 6.05 编写一个程序，定义一个符号常量表示计时器，使用for循环求计数器内所有整数序数对应的立方值，输出结果示例：

```
Please enter an integer number as the Timer:10
value of x  cubic of x
1                    1
2                    8
3                   27
4                   64
5                  125
6                  216
7                  343
8                  512
9                  729
10                1000
Done
```

#### 6.06 编写一个程序，使用for嵌套循环输出7行"ABCDEFG"，输出结果示例：

```makdown
ABCDEFG
ABCDEFG
ABCDEFG
ABCDEFG
ABCDEFG
ABCDEFG
ABCDEFG
Done!
```

#### 6.07 编写一个程序，提示用户输入类型的整数（long类型），通过do while循环重复输入，并使用bool类型的变量测试表达式的真值，输入'q'则退出循环，输出结果示例：

```
Please enter an integer number:44
Please enter an integer number(enter 'q' to quit):33
Please enter an integer number(enter 'q' to quit):88
Please enter an integer number(enter 'q' to quit):121
Please enter an integer number(enter 'q' to quit):q
Done! The sum of the integers entered is 286.
```

#### 6.08 编写一个程序，提示用户输入10个数据，声明一个大小为10的数组，类型为float，使用for循环输入数据并求总分和平均分，输出结果示例：

```
Please enter 10 scores:
88.5
96.7
84.0
86.3
82.1
89.5
79.0
90.0
85.5
97.0
Overall scores:878.6
Average score: 87.86
```

#### 6.09 编写一个程序，提示用户输入两个数，一个作为底数，一个作为指数，并设计一个求幂函数，在函数内使用for循环求幂，将底数和指数作为实参传递，将结果作为返回值。输出结果示例：

```
Please enter an number as index:15.5
Now enter an number as base:3
Done! The result is 3723.875000.bianxie
```

#### 6.10 编写一个程序，使用for嵌套循环打印以下图案：

```
$$$$$$$$
$$$$$$$$
$$$$$$$$
$$$$$$$$
```

#### 6.11 编写一个程序，使用for嵌套循环打印以下图案：

```
$
$$
$$$
$$$$
$$$$$
```

#### 6.12 编写一个程序，使用for嵌套循环打印以下图案：

```
F
FE
FED
FEDC
FEDCB
FEDCBA
```

#### 6.13 编写一个程序，使用for嵌套循环打印以下图案：

```
A
BC
DEF
GHIG
KLMNO
PQRETU
```

#### 6.14 编写一个程序，使用for嵌套循环打印图案，根据输入的字母，如输入'E'打印如下图案：

```
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
```

#### 6.15 编写一个程序，提示用户输入一个整数区间，并打印一个表格，每行打印该数、该数的的平方、该数的立方，只使用一个for循环，输出结果示例：

```
Please enter lower and upper integer limits:3 5
 3  9   27
 4  16  64
 5  25  125
Done!
```

#### 6.16 编写一个程序，使用for循环将一个单词读入一个字符数组中，并用另一个for循环倒序输出，输出结果示例：

```
Please enter a word:LYFNB
Reverse output:BNFYL
Done!
```

#### 6.17 编写一个程序，要求用户输入一个上限整数和一个下限整数，计算从上限到下限范围内所有整数的平方和，并显示计算结果。然后程序提示用户输入上限和下限整数，并显示结果，直到用户输入的上限整数等于或小于下限整数为止。输出结果示例：

```
Please enter lower and upper integer limits:5 9
The sums of the squares from 25 to 81 is 255.
Now enter next set of limits:3 25
The sums of the squares from 9 to 625 is 5520.
Now enter next set of limits:5 5
Done!
```

#### 6.18 编写一个程序，创建一个包含8个元素的int类型的数组，使用for循环分别把数组元素的值设置为2的前8次幂，使用do while循环显示数组元素的值。

#### 6.19 编写一个程序，创建两个包含8个元素的double类型的数组，使用循环提示用户为第一个数组输入8个值。第2个数组元素的值设置为第一个数组对应元素的累积之和。例如：第二个数组第4个元素的值是第一个数组前4个元素之和，第二个数组的第5个元素的值是第一个数组的前5个元素之和（用嵌套循环可以完成，但是利用第二个数组的第5个元素是第二个数组的第4个元素与第一个数组的第5个元素之和，只用一个循环就能完成任务，不需要使用嵌套循环）。最后，使用循环显示两个数组的内容，第一个数组显示成一行，第二个数组显示在第一个数组的下一行，而且每个元素都与第一个数组个元素相对应。输出结果示例：

```
Please fill the first array:1 2 3 4 5 6 7 8
The first array: 1.000000 2.000000 3.000000 4.000000  5.000000  6.000000  7.000000  8.000000   
The second array:1.000000 3.000000 6.000000 10.000000 15.000000 21.000000 28.000000 36.000000  
Done!
```

#### 6.20 Chuckie Lucky赢得了100万美元（税后），他把奖金存入年利率8%的账户。在每年最后一天取走10万美元。编写一个程序计算Chuckie多少年后会取完账户里的钱。

#### 6.21 Daphne以10%的单利息投资的100美元（也就是说，每年投资获利相当于原始投资的10%）。Deirdre以5%的复合利息投资了100美元（也就是说，利息是当前含原利息余额的5%）。编写一个程序，计算需要多少年Deirdre的投资额才会超过Daphne，并显示两人的投资额。

#### 6.22 Rabnud博士加入了一个社交圈，起初他只有5个朋友。他注意到他的朋友数量以下面的方式增长：第1周少了1个朋友，剩下的朋友数量却翻倍；第2周少了2个朋友，剩下的朋友数量翻倍。一般而言，第N周少了N个朋友，剩下的朋友数量翻倍。编写一个程序，计算并显示Rabnud博士每周朋友的数量。该程序一直运行，直到超过邓巴数（Dunbar's number）。邓巴数是粗略估计一个人在社交圈中拥有稳定关系的成员的最大值，该值大约是150。