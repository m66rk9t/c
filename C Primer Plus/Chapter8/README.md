## 《C Primer Plus》第8章练习题

#### 8.01 编写一个程序，使用while循环、getchar()和putchar()模拟EOF，打印输入的文本。输出结果示例：

```markdown
Please enter the text to be displayed,press Enter to print the text on the next line,
press Ctrl+Z to end:
My name is LiYifan, I'am 21 years old.
My name is LiYifan, I'am 21 years old.
I'll press Ctrl+Z
I'll press Ctrl+Z
^Z
Done!
```

#### 8.02 编写一个程序，使用while循环读取并打印输入的内容。程序要求用户输入一个字符和两个数字，代表打印的行数和列数。程序要跳过一轮输入结束与一轮输入开始之间的所有换行符和空格。输出结果示例：

```markdown
Please enter a character and two integers,
Press enter to quit:
a 5 6
aaaaaa
aaaaaa
aaaaaa
aaaaaa
aaaaaa
Now enter another character and two integers,
Press enter to quit:
a5 6
aaaaaa
aaaaaa
aaaaaa
aaaaaa
aaaaaa
Now enter another character and two integers,
Press enter to quit:

Done!
```

#### 8.03 编写一个程序，输入两个数分别代表下限和上限并求两数之间所有整数的平方和。程序要能检查输入的值是否有效，与已定义好的最大值和最小值进行判断，还要检查上下限是否对应。输出结果示例：

```markdown
Please enter a range, which must be within the specified range.
Min:-10000000
Max:+10000000
Please enter the limits(enter 0 for both to quit):
Lower limit:low
low is not an integer.
Please enter an integer such as 17,-203 and 0:3
Higher limit:infinity
infinity is not an integer.
Please enter an integer such as 17,-203 and 0:9
The sum of the squares of 3 to 9 is 280.000000
Enter the limits(enter 0 for both to quit):
Lower limit:80
Higher limit:10
80 is bigger than 10.
Please try again!
Enter the limits(enter 0 for both to quit):
Lower limit:0
Higher limit:0
Done!
```

#### 8.04 编写一个简单的菜单程序，程序要能根据用户输入的选项执行相应的行为，同时程序要能丢弃一行输入中除第一个字符以外的无效字符。输出结果示例：

```markdown
Enter the letter of your choice:
a. advice               b. bell
c. count                q. quit
a
Buy low, sell high.
Enter the letter of your choice:
a. advice               b. bell 
c. count                q. quit 
b
Enter the letter of your choice:
a. advice               b. bell
c. count                q. quit
count
Count how far?Enter an integer:two
two is not an integer,please enter an integer:5
0
1
2
3
4
5
Enter the letter of your choice:
a. advice               b. bell
c. count                q. quit
q
Done!
```

#### 8.05 编写一个程序，在遇到EOF之前，把输入作为字符流读取。程序要打印每个输入的字符及其相应的ASCII十进制值。注意，在ASCII中，空格字符前面的字符都是非打印字符，要特殊处理这些字符。如果非打印字符时换行符或制表符，则分别打印\n或\t。否则使用控制字符表示法。除每次遇到换行符打印新的一行之外，每行打印10对值。输出结果示例：

```markdown
Please enter some chararters(press ctrl+z to end):
abcdefghijklmnopqrstuvwxyz      ABCDEFGHIJKLMNOPQRSTUVWXYZ
a-97    b-98    c-99    d-100   e-101   f-102   g-103   h-104   i-105   j-106   
k-107   l-108   m-109   n-110   o-111   p-112   q-113   r-114   s-115   t-116   
u-117   v-118   w-119   x-120   y-121   z-122   \t-9    A-65    B-66    C-67    
D-68    E-69    F-70    G-71    H-72    I-73    J-74    K-75    L-76    M-77    
N-78    O-79    P-80    Q-81    R-82    S-83    T-84    U-85    V-86    W-87    
X-88    ^Z
Done!
```

#### 8.06 编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要能报告输入中的大写字母和小写字母的个数。假设大小写字母是连续的。或者使用ctype.h库中合适的分类函数更方便。输出结果示例：

```markdown
Please enter some characters for analysis(press ctrl+z to quit):
abcdefghijklmnopqrstuvwxyz
ABCDEFGHIJKLMNOPQRSTUVWXYZ
^Z
There are 26 lower case letters and 26 uppercase letter.
```

#### 8.07 编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要报告平均每个单词的字母数。不要把空白和标点符号统计为单词的字母。输出格式示例：

```markdown
Please enter text to analyzed(press Ctrl+Z to end),
Use blank character to separate words:
My name is Liyifan,
I'am 21 years old,
I like to play vedio games!
^Z
Letters:49
Words:15
Avg:3.27/word
```

#### 8.08 编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。获得用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的操作。该程序只接收菜单提供的选项。程序使用float类型的变量存储用户输入的数字，如果用户输入失败则允许再次输入。进行除法运算时，如果用户输入0作为除数，程序应提示用户重新输入一个新值。输出结果示例：

```markdown
Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide  
q.quit
LYF
Wrong input!Please respond with a, s, m, d or q.
Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide
q.quit
a
Enter left  value:one
one is not a floating-point number, please enter again:10
Enter right value:two
two is not a floating-point number, please enter again:10
10.000000 + 10.000000 = 20.000000
Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide
q.quit
s
Enter left  value:50
Enter right value:2.5
50.000000 - 2.500000 = 47.500000
Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide
q.quit
m
Enter left  value:2.5
Enter right value:4.5
2.500000 x 4.500000 = 11.250000
Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide
q.quit
d
Enter left  value:25
Enter right value:1.25
25.000000 / 1.250000 = 20.000000
Enter the operation of your choice:
a. add          s. subtract
m. multiply     d. divide
q.quit
q
Done!
```