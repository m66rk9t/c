## 《C Primer Plus》第14章练习题

#### 14.01 该例题完成的任务是创建一个结构模板，包含标题、作者、价格三个成员，以交互的方式提示用户输入三个成员的信息，并以两种指定的格式输出信息。输出示例：

```
Please enter the book title.
Chicken of the Andes
Now enter the author.
Disma Lapoult
Now enter the value.
29.99
Chicken of the Andes by Disma Lapoult: $29.99
Disma Lapoult: "Chicken of the Andes" ($29.99)
Done.
```

#### 14.02 修改14.01程序，使用结构数组创建多本图书信息，用while循环提示用户输入每本书的信息。输出示例：

```
Please enter the book title.
Press [enter] at the start of a line to stop.
My Life as a Budgie
Now enter the author.
Mack Zackles
Now enter the value.
12.95
Enter the next title.
...（此处省略了许多内容）...
Here is the list of your books:
My Life as a Budgie by Mack Zackles: $12.95
Thought and Unthought Rethought by Kindra Schlagmeyer: $43.50
Concerto for Financial Instruments by Filmore Walletz: $49.99
The CEO Power Diet by Buster Downsize: $19.25
C++ Primer Plus by Stephen Prata: $59.99
Fact Avoidance: Perception as Reality by Polly Bull: $19.97
Coping with Coping by Dr.Rubin Thonkwacker: $0.02
Diaphanous Frivolity by Neda McFey: $29.99
Murder Wore a Bikini by Mickey Splats: $18.95
A History of Buvania, Volume 8, by Prince Nikoli Buvan: $50.04
Mastering Your Digital Watch, 5nd Edition, by Miklos Mysz: $28.95
A Foregone Confusion by Phalty Reasoner: $5.99
Outsourcing Government: Selection vs.Election by Ima Pundit: $33.33
```

#### 14.03 该例题完成的任务是创建两个结构模板，分别为姓名模板以及朋友信息模板，其中姓名结构作为嵌套结构被声明在朋友信息结构中，以此为好朋友写一封信，可以声明一个指针数组并初始化未信件内容，然后再按格式输出内容。输出示例：

```
Dear Ewen,
    Thank you for the wonderful evening, Ewen.
You certainly prove that a personality coach
is a special kind of guy.We must get together
over a delicious grilled salmon and have a few laughs.
                                         See you soon,
                                         Shalala
```

#### 14.04 该例题完成的任务是使用指向结构的指针，并使用指针访问结构成员。输出示例：

```
address #1: 0x7fff5fbff820 #2: 0x7fff5fbff874
pointer #1: 0x7fff5fbff820 #2: 0x7fff5fbff874
him->income is $68112.00: (*him).income is $68112.00
him->favfood is tripe: him->handle.last is Swillbelly
```

#### 14.05 该例题完成的任务是把结构成员作为参数传递，输出示例：

```
Stan has a total of $12576.21.
```

#### 14.06 该例题完成的任务是把结构的地址作为参数传递，输出示例：

```
Stan has a total of $12576.21.
```

#### 14.07 该例题完成的任务是把结构作为参数传递，输出示例：

```
Stan has a total of $12576.21.
```

#### 14.08 编写一个程序，使用指向结构的指针，以交互方式输入用户的姓名并输出姓名包含的字符个数。创建一个姓名结构模板，声明一个结构以储存输入的信息，声明一个指向该结构的指针并作为参数传递给输入姓名、统计字符以及显示信息的函数。输出示例：

```
Please enter your first name.
Viola
Please enter your last name.
Plunderfest
Viola Plunderfest, your name contains 16 letters.
```

#### 14.09 修改14.08程序，让输入姓名和统计字符的函数的返回类型是一个结构。

#### 14.10 修改14.08程序，使用指向字符的指针代替结构模板中的字符数组，同时要注意使用malloc()为要指向字符串的指针分配内存以储存要输入的字符串，同时还要使用一个临时变量储存输入的内容，然后再拷贝到指定位置。输出示例：

```
Please enter your first name.
Floresiensis
Please enter your last name.
Mann
Floresiensis Mann, your name contains 16 letters.
```

#### 14.11 该例题完成的任务是使用复合字面量初始化一个图书的信息结构，复合字面量要包括书名、作者、价格三个必要信息并输出。输出示例：

```
Enter test score: 90
Your assigned reading:
Crime and Punishment by Fyodor Dostoyevsky: $11.25
```

#### 14.12 该例题完成的任务是使用伸缩型数组成员这一特性，完成计算分数平均分的任务。注意使用伸缩型数组成员时，要使用malloc()分配足够的存储空间。输出示例;

```
Scores : 20 19 18 17 16
Average: 18
Scores : 20 19.5 19 18.5 18 17.5 17 16.5 16
Average: 17
```

#### 14.13 该例题完成的任务创建一个结构数组，数组中的每个元素都是一个结构，并将数组作为参数传递。输出示例：

```
The Joneses have a total of $20000.00.
```

#### 14.14 该例题完成的任务是从一个储存图书信息的文件中读取内容，并在读取完后以交互的方式允许用户继续添加新的图书信息，输入结束后输出现文件中所有图书信息。输出示例：

```
Please add new book titles.
Press [enter] at the start of a line to stop.
Metric Merriment
Now enter the author.
Polly Poetica
Now enter the value.
18.99
Enter the next title.
Deadly Farce
Now enter the author.
Dudley Forse
Now enter the value.
15.99
Enter the next title.
[enter]
Here is the list of your books:
Metric Merriment by Polly Poetica: $18.99
Deadly Farce by Dudley Forse: $15.99
Bye.
$ booksave
Current contents of book.dat:
Metric Merriment by Polly Poetica: $18.99
Deadly Farce by Dudley Forse: $15.99
Please add new book titles.
The Third Jar
Now enter the author.
Nellie Nostrum
Now enter the value.
22.99
Enter the next title.
[enter]
Here is the list of your books:
Metric Merriment by Polly Poetica: $18.99
Deadly Farce by Dudley Forse: $15.99
The Third Jar by Nellie Nostrum: $22.99
Bye.
```

#### 14.15 该例题使用枚举变量完成根据输入的颜色字符串输出对应的信息，使用while循环以交互的方式提示用户输入，并且要能处理错误输入。输出示例：

```
Enter a color (empty line to quit):
blue
Bluebells are blue.
Next color, please (empty line to quit):
orange
Poppies are orange.
Next color, please (empty line to quit):
purple
I don't know about the color purple.
Next color, please (empty line to quit):
Goodbye!
```

#### 14.16 使用函数指针，完成以下任务：

+ 提示用户输入一个待处理的字符串
+ 循环显示一个菜单提示用户输入选项
+ 能够处理错误选项
+ 根据选项调用对应的处理函数处理字符串
+ 使用函数指针，根据不同选项将不同的函数地址赋给该指针
+ 有一个调用对应函数的函数，参数为函数指针以及待处理的字符串

#### 输出示例：

```
Enter a string (empty line to quit):
Does C make you feel loopy?
Enter menu choice:
u) uppercase l) lowercase
t) transposed case o) original case
n) next string
t
dOES c MAKE YOU FEEL LOOPY?
Enter menu choice:
u) uppercase l) lowercase
t) transposed case o) original case
n) next string
l
does c make you feel loopy?
Enter menu choice:
u) uppercase l) lowercase
t) transposed case o) original case
n) next string
n
Enter a string (empty line to quit):
Bye!
```

#### 14.17 设计一个结构模板储存一个月份名、该月份名的3个字母缩写、该月的天数以及月份号。其次，定义一个数组，内含12个结构（第3题的结构类型）并初始化为一个年份（非闰年）。然后，编写一个函数，用户提供月份号，该函数就返回一年中到该月为止（包括该月）的总天数。输出示例：

```
Please enter a month:August
From January to ,there are 0 days.
```

#### 14.18 以下为一个程序的部分片段，现在要编写一个函数，以bem结构的地址作为参数，并以下面的形式输出结构的内容（假定结构模板在一个名为starfolk.h的头文件中）：Berbnazel Gwolkapwolk is a 6-limbed Arcturan.

```c
struct name {
    char first[20];
    char last[20];
};
struct bem {
    int limbs;
    struct name title;
    char type[30];
};
struct bem * pb;
struct bem deb = {
    6,
    { "Berbnazel", "Gwolkapwolk" },
    "Arcturan"
};
pb = &deb;
```

#### 14.19 假设有如下结构：

```c
struct gas {
float distance;
float gals;
float mpg;
};
```

+ 设计一个函数，接受struct gas类型的参数。假设传入的结构包含distance和gals信息。该函数为mpg成员计算正确的值，并把值返回该结构。

+ 设计一个函数，接受struct gas类型的参数。假设传入的结构包含distance和gals信息。该函数为mpg成员计算正确的值，并把该值赋给合适的成员。

#### 14.20 重新编写14.17，用月份名的拼写代替月份号（别忘了使用strcmp()）。在一个简单的程序中测试该函数。

#### 14.21 编写一个函数，提示用户输入日、月和年。月份可以是月份号、月份名或月份名缩写。然后该程序应返回一年中到用户指定日子（包括这一天）的总天数。

#### 14.22 修改程序清单 14.02 中的图书目录程序，使其按照输入图书的顺序输出图书的信息，然后按照标题字母的声明输出图书的信息，最后按照价格的升序输出图书的信息。

#### 14.23 编写一个程序，创建一个有两个成员的结构模板：

+ 第1个成员是社会保险号，第2个成员是一个有3个成员的结构，第1个成员代表名，第2个成员代表中间名，第3个成员表示姓。创建并初始化一个内含5个该类型结构的数组。该程序以这种格式打印数据：`Dribble, Flossie M.–– 302039823`如果有中间名，只打印它的第1个字母，后面加一个点（.）；如果没有中间名，则不用打印点。编写一个程序进行打印，把结构数组传递给这个函数。

+ 修改上面的内容，传递结构的值而不是结构的地址。

#### 14.24 编写一个程序满足下面的要求。
+ a.外部定义一个有两个成员的结构模板name：一个字符串储存名，一个字符串储存姓。
+ b.外部定义一个有3个成员的结构模板student：一个name类型的结构，一个grade数组储存3个浮点型分数，一个变量储存3个分数平均数。
+ c.在main()函数中声明一个内含CSIZE（CSIZE = 4）个student类型结构的数组，并初始化这些结构的名字部分。用函数执行d、e、f和g中描述的任务。
+ d.以交互的方式获取每个学生的成绩，提示用户输入学生的姓名和分数。把分数储存到grade数组相应的结构中。可以在main()函数或其他函数中用循环来完成。
+ e.计算每个结构的平均分，并把计算后的值赋给合适的成员。
+ f.打印每个结构的信息。
+ g.打印班级的平均分，即所有结构的数值成员的平均值。

#### 14.25 一个文本文件中保存着一个垒球队的信息。每行数据都是这样排列：

```
·4 Jessie Joybat 5 2 1 1
```

#### 第1项是球员号，为方便起见，其范围是0～18。第2项是球员的名。第3项是球员的姓。名和姓都是一个单词。第4项是官方统计的球员上场次数。接着3项分别是击中数、走垒数和打点（RBI）。文件可能包含多场比赛的数据，所以同一位球员可能有多行数据，而且同一位球员的多行数据之间可能有其他球员的数据。编写一个程序，把数据储存到一个结构数组中。该结构中的成员要分别表示球员的名、姓、上场次数、击中数、走垒数、打点和安打率（稍后计算）。可以使用球员号作为数组的索引。该程序要读到文件结尾，并统计每位球员的各项累计总和。世界棒球统计与之相关。例如，一次走垒和触垒中的失误不计入上场次数，但是可能产生一个RBI。但是该程序要做的是像下面描述的一样读取和处理数据文件，不会关心数据的实际含义。要实现这些功能，最简单的方法是把结构的内容都初始化为零，把文件中的数据读入临时变量中，然后将其加入相应的结构中。程序读完文件后，应计算每位球员的安打率，并把计算结果储存到结构的相应成员中。计算安打率是用球员的累计击中数除以上场累计次数。这是一个浮点数计算。最后，程序结合整个球队的统计数据，一行显示一位球员的累计数据。

#### 14.26 修改程序清单14.14，从文件中读取每条记录并显示出来，允许用户删除记录或修改记录的内容。如果删除记录，把空出来的空间留给下一个要读入的记录。要修改现有的文件内容，必须用"r+b"模式，而不是"a+b"模式。而且，必须更加注意定位文件指针，防止新加入的记录覆盖现有记录。最简单的方法是改动储存在内存中的所有数据，然后再把最后的信息写入文件。跟踪的一个方法是在book结构中添加一个成员表示是否该项被删除。

#### 14.27 巨人航空公司的机群由12个座位的飞机组成。它每天飞行一个航班。根据下面的要求，编写一个座位预订程序。
+ a.该程序使用一个内含 12 个结构的数组。每个结构中包括：一个成员表示座位编号、一个成员表示座位是否已被预订、一个成员表示预订人的名、一个成员表示预订人的姓。
+ b.该程序显示下面的菜单：

```
To choose a function, enter its letter label:
a) Show number of empty seats
b) Show list of empty seats
c) Show alphabetical list of seats
d) Assign a customer to a seat assignment
e) Delete a seat assignment
f) Quit
```
+ c.该程序能成功执行上面给出的菜单。选择d)和e)要提示用户进行额外输入，每个选项都能让用户中止输入。
+ d.执行特定程序后，该程序再次显示菜单，除非用户选择f)。

#### 14.28 巨人航空公司（编程练习 8）需要另一架飞机（容量相同），每天飞4 班（航班 102、311、444 和519）。把程序扩展为可以处理4个航班。用一个顶层菜单提供航班选择和退出。选择一个特定航班，就会出现和编程练习8类似的菜单。但是该菜单要添加一个新选项：确认座位分配。而且，菜单中的退出是返回顶层菜单。每次显示都要指明当前正在处理的航班号。另外，座位分配显示要指明确认状态。

#### 14.29 编写一个程序，通过一个函数指针数组实现菜单。例如，选择菜单中的 a，将激活由该数组第 1个元素指向的函数。

#### 14.30 编写一个名为transform()的函数，接受4个参数：内含double类型数据的源数组名、内含double类型数据的目标数组名、一个表示数组元素个数的int类型参数、函数名（或等价的函数指针）。transform()函数应把指定函数应用于源数组中的每个元素，并把返回值储存在目标数组中。例如：

```
transform(source, target, 100, sin);
```

#### 该声明会把target[0]设置为sin(source[0])，等等，共有100个元素。在一个程序中调用transform()4次，以测试该函数。分别使用math.h函数库中的两个函数以及自定义的两个函数作为参数。