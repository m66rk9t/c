## 《C Prime Plus》第9章练习题

#### 9.01 编写一个程序，使用函数原型和指针变量求两个数中的最大值并将最大值放入第一个数中。输出结果示例：

```markdown
Please enter two integers:
45 89
The min is 45, the max is 89.
```

#### 9.02 编写一个程序，使用函数原型和指针变量判断三个数的大小关系。判断大小的函数要以三个变量地址作为参数，把最小值放入第一个变量中，中间值放入第二个变量中，最大值放入第三个变量中。输出结果示例：

```markdown
Please enter three numbers:
45.2 98.4 85.41
98.400000>85.410000>45.000000
```

#### 9.03 编写一个程序，使用递归计算阶乘。程序使用while循环提示用户重复输入。注意，用户输入的数值不能小于0且不能大于12，当输入的数据不符合要求时，程序要能提示用户错误输入并重新输入范围内的值。
     
#### 9.04 编写一个程序，使用递归算法将一个十进制值转换成二进制值并输出出来。输出结果示例：

```markdown
Please enter an integer(enter 'q' to qiut):
9
Binary equivalent: 1001
Now enter another integer(enter 'q' to qiut):
255
Binary equivalent: 11111111
Now enter another integer(enter 'q' to qiut):
1024
Binary equivalent: 10000000000
Now enter another integer(enter 'q' to qiut):
q
Done!
```

#### 9.05 设计一个函数chline(chara,row,column)，打印指定字符row行column列。输出结果示例：

```markdown
Please enter a character and two integers,
Press Ctrl+Z to quit:
c 6 8
cccccccc
cccccccc
cccccccc
cccccccc
cccccccc
cccccccc
Now enter another character and two integers,
Press enter to quit:
^Z
Done!
```

#### 9.06 编写一个程序求两个数的调和平均数，调和平均数即先得到两个数的的倒数，然后计算两个倒数的平均值，最后取计算结果的倒数。编写一个函数，接受两个double类型的参数，返回这两个参数的调和平均数。输出结果示例：

```markdown
Please enter two floating-point values(press Ctrl+Z to quit):
1 2
The harmonic mean of 1.000000 and 2.000000 is 1.333333.
Now enter another set of valuse(press Ctrl+Z to quit):
2 4
The harmonic mean of 2.000000 and 4.000000 is 2.666667.
Now enter another set of valuse(press Ctrl+Z to quit):
^Z
Done!
```

#### 9.07 编写一个函数，从标准输入中读取字符直到遇到文件结尾。程序要报告每个字符是否为字母。如果是，还要报告该字母在字母表中的数值位置。例如，c和C在字母表中的位置都是3。合并一个函数，以一个字符作为参数，如果该字符是一个字母则返回一个数值位置，否则返回-1。同时程序要处理掉回车符，输出结果示例：

```markdown
Please enter some characters(press Ctrl+Z to qiut):
abcDEF123()^&
The position of a in the alphabet is 1.
The position of b in the alphabet is 2.
The position of c in the alphabet is 3.
The position of D in the alphabet is 4.
The position of E in the alphabet is 5.
The position of F in the alphabet is 6.
1 is not a letter.
2 is not a letter.
3 is not a letter.
( is not a letter.
) is not a letter.
^ is not a letter.
& is not a letter.
^Z
Done!
```

#### 9.08 编写一个函数power()用于求某数的负幂值，该数接受两个参数，double类型的底数以及int类型的指数。该函数要能处理0的任何次幂都为0以及任何数的0次幂都为1（报告0的0次幂未定义并将值处理为1）。使用while循环提示用户重复输入直到遇到文件结尾结束循环。输出结果示例：

```markdown
Please enter a base and an exponent(press Ctrl+Z to quit):
0 0 
0^0 undefined.
Evaluation result:1.000000
Now enter another set of valuse(press Ctrl+Z to quit):
0 1
Any power of 0 is 0.
Evaluation result:0.000000
Now enter another set of valuse(press Ctrl+Z to quit):
1 0
Evaluation result:1.000000
Now enter another set of valuse(press Ctrl+Z to quit):
2 -2
Evaluation result:0.250000
Now enter another set of valuse(press Ctrl+Z to quit):
-5 -3
Evaluation result:-0.008000
Now enter another set of valuse(press Ctrl+Z to quit):
^Z
Done!
```

#### 9.09 修改9.04中的to_binary()函数，以此为基础编写一个to_base_n()函数，该函数接受两个参数，第一个参数是要转换的十进制值，第二个参数是指定的进制。第二个参数在2~10范围内，以第二个参数中指定的进制打印第一个参数的数值。例如to_base_n(129,8)显示的结果为201，也就是129的八进制值。程序使用while循环提示用户重复输入直到遇到文件结尾结束循环，同时还要检查、报告第二个参数的有效性。输出结果示例：

```markdown
Please enter an integer and a base(press Ctrl+Z to qiut):
129 1
Please enter an integer in the range of 2~10:
8
Conversion result: 201
Now enter another set of valuse(press Ctrl+Z to quit):
1024 11
Please enter an integer in the range of 2~10:
2
Conversion result: 10000000000
Now enter another set of valuse(press Ctrl+Z to quit):
^Z
Done!
```

#### 9.10 编写Fibonacci()函数，该函数用递归算法输出用户指定的全部项。输出结果示例：

```markdown
Please enter the number of items(press Ctrl+Z to end):
5
Result:
1 1 2 3 5 
Please enter the number of items(press Ctrl+Z to end):
7
Result:        
1 1 2 3 5 8 13 
Please enter the number of items(press Ctrl+Z to end):
^Z
Done!
```

#### 9.11 编写一个程序，管理4家酒店的客房服务。根据预定的天数计算房费，4家酒店的房费相同，第2天的房费是是第1天的95%，第3天的房费是第2天的的95%，以此类推。该程序包含三个文件，分别是包含main()函数的源文件，包含函数定义的源文件以及包含字符常量与函数原型的头文件。输出结果示例：

```c
******************************************
Enter the number of the diserd hotle:     
1) Fairfield Arms       2) Hotle Olympic  
3) Chertowth Plaza      4) The Stocken    
5) quit
******************************************
3
How many nights are needed?
1
The total cost will be $255.00

******************************************
Enter the number of the diserd hotle:
1) Fairfield Arms       2) Hotle Olympic
3) Chertowth Plaza      4) The Stocken
5) quit
******************************************
4
How many nights are needed?
3
The total cost will be $1012.64

******************************************
Enter the number of the diserd hotle:
1) Fairfield Arms       2) Hotle Olympic
3) Chertowth Plaza      4) The Stocken
5) quit
******************************************
5
Thank you and goodbye!
```