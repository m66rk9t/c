## 《C Primer Plus》第16章练习题

#### 16.01 使用简单的预处理指令，输出示例：

```
X is 2.
X is 4.
Consistency is the last refuge of the unimaginative. - Oscar Wilde
TWO: OW
```

#### 16.02 创建并使用类宏函数，输出示例：

```
x = 5
Evaluating SQUARE(x): The result is 25.
Evaluating SQUARE(2): The result is 4.
Evaluating SQUARE(x+2): The result is 17.
Evaluating 100/SQUARE(2): The result is 100.
x is 5.
Evaluating SQUARE(++x): The result is 49.
After incrementing, x is 7.
```

#### 16.03 使用#预处理运算符在字符串中替换参数，输出示例：

```
The square of y is 25.
The square of 2 + 4 is 36.
```

#### 16.04 使用##预处理运算符组合记号，输出示例：

```
x1 = 14
x2 = 20
x3 = 30
```

#### 16.05 使用可变参数宏，输出示例：

```
Message 1: x = 48
Message 2: x = 48.00, y = 6.9282
```

#### 16.06 使用头文件中的names_st结构，输出示例：

```
Please enter your first name: Yifan
Please enter your last name: Li
Let's welcome Yifan Li to this program!
```

#### 16.07 使用条件编译#ifdef以及#endif，输出示例：

```
i=1, running total = 3
i=2, running total = 12
i=3, running total = 31
i=4, running total = 64
Grand total = 64
```

#### 16.08 测试重复包含头文件，输出示例：

```
The winner is Less Ismoor.
```

#### 16.09 使用预定义宏和预定义标识符，输出示例：

```
The file is predef.c.
The date is Aug 14 2021.
The time is 12:15:21.
The version is 201710.
This is line 12.
This function is main
This function is why_me
This is line 23.
```

#### 16.10 使用泛型选择表达式，输出示例：

```
int
double
other
other
```

#### 16.11 把直角坐标转换成极坐标，输出示例：

```
Enter x and y coordinates; enter q to quit:
10 10
magnitude = 14.14, angle = 45.00
-12 -5
magnitude = 13.00, angle = -157.38
q
Bye.
```

#### 16.12 定义并使用泛型宏，输出示例：

```
6.70820379257202148
6.70820393249936942
6.70820393249936909
6.70820393249936942
0.70710678118654752
```

#### 16.13 使用atexit()，输出示例：

```
Enter an integer:
212
212 is even.
Thus terminates another magnificent program from
SeeSaw Software!
Enter an integer:
what?
That's no integer!
SeeSaw Software extends its heartfelt condolences
to you upon the failure of your program.
Thus terminates another magnificent program from
SeeSaw Software!
```

#### 16.14 使用qsort()快速排序，输出示例：

```
Random list:
   2.1304    0.9808    4.6147    0.4364    0.5014    0.7591 
   0.7105    1.0393    0.8863    0.2333    0.0671    0.1706 
   0.3908    1.1928    4.5768    0.6113    2.0695    1.2160 
   0.5074    0.3792    0.6842    0.4489    0.8038    0.8789 
   0.0735    6.1123    0.2898    2.5516    3.2049    7.2541 
   0.2455    1.0603    0.4940    0.4935    0.7676   13.5337 
   0.4697    1.2911    0.3849    1.8076 

Sorted list:
   0.0671    0.0735    0.1706    0.2333    0.2455    0.2898 
   0.3792    0.3849    0.3908    0.4364    0.4489    0.4697 
   0.4935    0.4940    0.5014    0.5074    0.6113    0.6842 
   0.7105    0.7591    0.7676    0.8038    0.8789    0.8863 
   0.9808    1.0393    1.0603    1.1928    1.2160    1.2911 
   1.8076    2.0695    2.1304    2.5516    3.2049    4.5768 
   4.6147    6.1123    7.2541   13.5337
```

#### 16.15 使用assert()，输出示例：

```
Enter a pair of numbers (0 0 to quit):
4 3
answer is 2.645751
Next pair of numbers:
5 3
answer is 4.000000
Next pair of numbers:
3 5
assert: assert.c:13: main: Assertion `z >= 0' failed.
Aborted (core dumped)
```

#### 16.16 使用_Static_assert声明，输出示例：

```
$ gcc statasrt.c 
statasrt.c:4:1: error: static assertion failed: "16-bit char falsely assumed"
    4 | _Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
      | ^~~~~~~~~~~~~~
```

#### 16.17 使用memcpy()和memmove()，输出示例：

```
memcpy() used:
values (original data): 
1 2 3 4 5 6 7 8 9 10 
target (copy of values):
1 2 3 4 5 6 7 8 9 10 

Using memmove() with overlapping ranges:
values -- elements 0-5 copied to 2-7:
1 2 1 2 3 4 5 8 9 10 

Using memcpy() to copy double to int:
target -- 5 doubles into 10 int positions:
0 1073741824 0 1091070464 536870912 
1108516959 2025163840 1143320349 -2012696540 1179618799 
```

#### 16.18 使用可变参数，输出示例：

```
return value for sum(3, 1.1, 2.5, 13.3):                16.9
return value for sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): 31.6
```

#### 16.19 开发一个包含你需要的预处理器定义的头文件。

#### 16.20 两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数的平均值，最后取计算结果的倒数。使用#define指令定义一个宏“函数”，执行该运算。编写一个简单的程序测试该宏。

#### 16.21 极坐标用向量的模（即向量的长度）和向量相对x轴逆时针旋转的角度来描述该向量。直角坐标用向量的x轴和y轴的坐标来描述该向量。编写一个程序，读取向量的模和角度（单位：度），然后显示x轴和y轴的坐标。相关方程如下：`x = r*cos A y = r*sin A`，注意cos()和sin()函数的参数为弧度值。需要一个函数来完成转换，该函数接受一个包含极坐标的结构，并返回一个包含直角坐标的结构（或返回指向该结构的指针）。

#### 16.22 ANSI库这样描述clock()函数的特性：

```c
#include <time.h>
clock_t clock (void);
```

#### 这里，clock_t是定义在time.h中的类型。该函数返回处理器时间，其单位取决于实现（如果处理器时间不可用或无法表示，该函数将返回-1）。然而，CLOCKS_PER_SEC（也定义在time.h中）是每秒处理器时间单位的数量。因此，两个 clock()返回值的差值除以 CLOCKS_PER_SEC得到两次调用之间经过的秒数。在进行除法运算之前，把值的类型强制转换成double类型，可以将时间精确到小数点以后。编写一个函数，接受一个double类型的参数表示时间延迟数，然后在这段时间运行一个循环。编写一个简单的程序测试该函数。

#### 16.23 编写一个函数接受这些参数：内含int类型元素的数组名、数组的大小和一个代表选取次数的值。该函数从数组中随机选择指定数量的元素，并打印它们。每个元素只能选择一次（模拟抽奖数字或挑选陪审团成员）。另外，如果你的实现有time()或类似的函数，可在srand()中使用这个函数的输出来初始化随机数生成器rand()。编写一个简单的程序测试该函数。

#### 16.24 修改程序清单16.17，使用struct names元素而不是double类型的数组进行姓名之间的排序。使用较少的元素，并用选定的名字显式初始化数组。

#### 16.25 下面是使用变参函数的一个程序段：

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void show_array(const double ar[], int n);
double * new_d_array(int n, ...);
int main()
{
    double * p1;
    double * p2;
    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1890.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);
    return 0;
}
```

#### new_d_array()函数接受一个int类型的参数和double类型的参数。该函数返回一个指针，指向由malloc()分配的内存块。int类型的参数指定了动态数组中的元素个数，double类型的值用于初始化元素（第1个值赋给第1个元素，以此类推）。编写show_array()和new_d_array()函数的代码，完成这个程序。