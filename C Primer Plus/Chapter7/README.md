## 《C Primer Plus》第7章练习题

#### 7.01 电力公司通常根据客户的总用电量来决定电费。编写一个程序，使用if与else if嵌套根据电力公司收费标准计算电费。输出结果示例：

```markdown
Electricity bill list(kWh)：
First 360kWh:      $0.13230/kWh
Renew 108kWh:      $0.15040/kWh
Renew 252kWh:      $0.30025/kWh
Exceed 720kWh:     $0.34025/kWh

Please enter the kWh used:
580
The charge for 580.00kWh is $97.50.
```

#### 7.02 编写一个程序，判断一个数是否为素数，如果不是素数就列出它的所有约数，程序提示用户输入一个整数进行判断，输入'q'就退出。要求使用while、for、if else语句。输出结果示例：

```markdown
Please enter an integer number for analysis(enter 'q' to quit):
123456789
123456789 is divisible by 3 and 41152263.
123456789 is divisible by 9 and 13717421.
123456789 is divisible by 3607 and 34227.
123456789 is divisible by 3803 and 32463.
123456789 is divisible by 10821 and 11409.
123456789 is not prime.
Please enter another integer number for analysis(enter 'q' to quit):
149
149 is prime.
Please enter another integer number for analysis(enter 'q' to quit):
2013
     2013 is divisible by 3 and 671.
2013 is divisible by 11 and 183.
2013 is divisible by 33 and 61.
2013 is not prime.
Please enter another integer number for analysis(enter 'q' to quit):
q
Done!
```

#### 7.03 编写一个程序，使用if与while语句计算输入的字符、单词、行的数量，使用'|'字符作为文本的结束，输出结果示例：

```markdown
Please enter text to analyzed(enter '|' to end)
Use blank character to separate words:
Reason is a
powerful servant but
an inadequate master.
|
There are 55 characters, 9 words, 3 lines and 0 special lines.
```

#### 7.04 商店出售油漆时往往根据客户的粉刷面积确定使用的桶数，而且不会拆分来卖，只会出售完整的罐装油漆。编写一个程序，根据客户的粉刷面积（平方英尺）以及每罐油漆可粉刷的面积（平方英尺）计算需要购买的油漆罐数。使用while循环提示用户重复输入数值，直到输入字符'q'退出程序，使用?:三元运算符计算罐数和输出。输出结果示例：

```markdown
Enter number of square feet to be painted:
349
You need 1 can of paint.
Enter the next number of square feet to be paint(enter 'q' to quit):
351
You need 2 cans of paint.
Enter the next number of square feet to be paint(enter 'q' to quit):
q
Done!
```

#### 7.05 编写一个程序，使用switch语句根据输入的字母（不区分大小写）输出相应的文本。使用while循环提示用户反复输入字符，程序要能跳过输入的多余字符以及首次输入的换行符（Enter键产生），能根据错误字符输出相应的提示，直到用户输入'#'字符退出循环。输出结果示例：

```markdown
Please enter an letter of the alphabet, and I will give an animal name.
The letters entered are not case sensitive, enter '#' to quit.
A
Argali, a wild sheep of Asia.
Now enter another letter(enter '#' to quit):
b
Babirusa, a wild pig of Malay.
Now enter another letter(enter '#' to quit):
C
Coati, racoonlike mammal.
Now enter another letter(enter '#' to quit):
d
Desman, aquatic, molelike critter.
Now enter another letter(enter '#' to quit):
E
Echidna, the spiny anteater.
Now enter another letter(enter '#' to quit):
&
Wrong input!
Now enter another letter(enter '#' to quit):
#
Done!
```

#### 7.06 编写一个程序，使用switch语句根据输入的文本统计大写字母以及小写字母还有其他字符的数量。使用while语句循环读取用户输入的字符，直到输入'#'结束循环。输出结果示例：

```markdown
Please enter a text for analysis(enter '#' to end):
My name is LiYifan.#
There are 12 lower case letters, 3 uppercase letters, and 4 other characters.
```

#### 7.07 编写一个程序，使用switch语句测试goto语句。

#### 7.08 编写一个程序，使用while循环读取输入，读到'#'字符停止，然后报告读取的空格数、换行符数和所有其他字符数。输出结果示例：

```markdown
Please enter a text for analysis(enter '#' to end):
My name is LiYifan,
I'am 21 years old.#
There are 6 spaces, 1 '\n', and 31 other characters.
```

#### 7.09 编写一个程序，读到'#'字符停止。程序要打印每个输入字符以及对应的ASCII码（十进制）。每行打印８个”字符－ASCII码“组合。建议：使用字符计数和求模运算符在每８个循环周期时打印一个换行符。输出结果示例：

```markdown
Please enter some charchters to analysis(enter '#' to end):
ABCDEFGHIJKLMNOPQRSTUVWXYZ!@$%^&*()-_+=1#
A-065   B-066   C-067   D-068   E-069   F-070   G-071   H-072
I-073   J-074   K-075   L-076   M-077   N-078   O-079   P-080
Q-081   R-082   S-083   T-084   U-085   V-086   W-087   X-088
Y-089   Z-090   !-033   @-064   $-036   %-037   ^-094   &-038
*-042   (-040   )-041   --045   _-095   +-043   =-061   1-049
Done!
```

#### 7.10 编写一个程序，读取整数直到用户输入0停止读取。输入结束后，程序应报告用户输入的偶数（不包括0）个数、偶数和的平均值以及奇数个数、奇数和的平均值。使用while循环输入。输出结果示例：

```markdown
Please enter a set of numbers(enter 0 to end):
1 4 5 9 10 0 
Count of odd numbers:3
Average of odd numbers:5.000000
Count of even numbers:2
Average of even numbers:7.000000
```

#### 7.11 编写一个程序，提示用户输入一周工作的小时数，然后打印工资总额、税金和净收入。做如下假设：a.基本工资=10.00美元/小时；b.加班（超过40小时）=1.5倍的时间；c.税率：前300美元15%，续150美元20%，余下的为25%。用#define定义符号常量。输出结果示例：

```markdown
Please enter the number of hours you work in a week:
50
Wage:750.000000
Taxes:150.000000
Net income:600.000000
```

#### 7.12 修改7.11程序，让程序给出一个供选择的工资等级菜单。使用switch完成工资选择。运行程序后，显示的菜单如下：

```c
*****************************M*E*N*U*****************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr                     2) $9.33/hr
3) $10.00/hr                    4) $11.20/hr
5) quit
*****************************************************************
```
#### 如果选择1~4其中的一个数字，程序应该询问用户工作的小时数。程序要通过循环运行，除非用户输入5。如果输入1~5以外的其他数字，程序应该提醒用户输入正确的选项，然后再重复显示菜单提示用户输入。使用#define定义符号常量，表示各工资等级和税率。输出结果示例：

```c
*****************************M*E*N*U*****************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr                     2) $9.33/hr
3) $10.00/hr                    4) $11.20/hr
5) quit
*****************************************************************
9
Please enter the correct selection!
*****************************M*E*N*U*****************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr                     2) $9.33/hr
3) $10.00/hr                    4) $11.20/hr
5) quit
*****************************************************************
3
Please enter the number of hours you work in a week:
50
Wage:750.000000
Taxes:150.000000
Net income:600.000000

*****************************M*E*N*U*****************************
Enter the number corresponding to the desired pay rate or action:
1) $8.75/hr                     2) $9.33/hr
3) $10.00/hr                    4) $11.20/hr
5) quit
*****************************************************************
5
Done!
```

#### 7.13 编写一个程序，只接受正整数输入，然后显示所有小于或等于该数的素数。输出结果示例：

```markdown
Please enter a positive integer:
10
The prime numbers less than or equal to 10 have:
2 3 5 7 
Done!
```

#### 7.14 1998年的美国联邦税收计划是近代最简单的税收方案。它分为4个类别，每个类别有两个等级。下面是该税收计划的摘要

```markdown
（美元数为应征税的收入）
类别                税金
单身                17850美元按15%计，超出部分按28%计
户主                23900美元按15%计，超出部分按28%计
已婚，共有           29750美元按15%计，超出部分按28%计
已婚，离异           14875美元按15%计，超出部分按28%计
```
#### 例如，一位工资20000美元的单身纳税人，应缴纳税费0.15x17850+0.28x(20000-17850)美元。编写一个程序，让用指定缴纳税金的种类和应纳税收入，然后计算税金，程序应该通过循环让用户可以多次输入。输出结果示例：

```c
*****************************M*E*N*U*****************************
Please enter the number corresponding to the option you selected:
1) Single                       2) Head of Household
3) Married,Shared               4) Married,Divorced
5) quit
*****************************************************************
#
Please enter the correct selection!
*****************************M*E*N*U*****************************
Please enter the number corresponding to the option you selected:
1) Single                       2) Head of Household
3) Married,Shared               4) Married,Divorced
5) quit
*****************************************************************
1
Please enter your income(>=17850):
20000
Your taxes:3279.500000

*****************************M*E*N*U*****************************
Please enter the number corresponding to the option you selected:
1) Single                       2) Head of Household
3) Married,Shared               4) Married,Divorced
5) quit
*****************************************************************
5
Done!
```

#### 7.15 ABC邮购杂货店出售的洋蓟售价为2.05美元/磅，甜菜售价为1.15美元/磅，胡萝卜售价为1.09美元/磅。在添加运费之前，100美元的订单有5%的打折优惠。少于或等于5磅的订单收取6.5美元的运费和包装费，5~20磅的订单收取14美元的运费和包装费，超过20磅的订单在14美元的基础上每续重1磅增加0.5美元。编写一个程序，在循环中用switch语句实现用户输入不同的字母时有不同的响应，即输入a的响应是让用户输入洋蓟的磅数，b是甜菜的磅数，c是胡萝卜的磅数，q是退出订购。程序要记录累计的重量。即用户输入4磅的甜菜，然后要输入5磅的甜菜，程序应报告9磅的甜菜。然后，该程序要计算总价，折扣（如果有的话）、运费和包装费。随后，程序应显示所有的购买信息：物品售价、订购的重量、订购的蔬菜费用、订单总费用、折扣（如果有的话）、运费和包装费，以及所有的费用总额。输出结果示例：

```c
*******************************M*E*N*U*******************************
Please enter the option corresponding to the product you want to buy:
a) Artichoke            b) Beet         c) Carrot       q) Quit      
*********************************************************************
a
Please enter the pound of the artichoke you want to buy:
20
Please enter another product option(enter 'q' to quit):
b
Please enter the pound of beets you want to buy:
25
Please enter another product option(enter 'q' to quit):
c
Please enter the pounds of carrots you want to buy:
30
Please enter another product option(enter 'q' to quit):
q
******************************O*R*D*E*R******************************
Artichoke:20.000000     Beet:25.000000  Carrot:30.000000

The cost of the meat you ordered:41.000000
The total weight of the goods you purchased: 75.000000 pounds
The cost of the vegetables you ordered:61.450000
The total cost of your order:102.450000
You have a coupon to use.Total order cost after discount:97.327500
Freight and packaging fees:41.500000
                                             To be paid:   138.827500
*********************************************************************
Done!
```