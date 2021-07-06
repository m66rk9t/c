/*使用递归计算阶乘*/
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int  get_num();                                             /*函数原型*/
long re_factorial(int num);                                 /*函数原型*/
int main(void)
{
    int input;                                              /*存储待输入数据的变量*/
    long result;                                            /*存储递归求值的结果*/
    while (true)
    {
        input=get_num();
        if (input==-1)
        {
            break;
        }
        else
        {
            result=re_factorial(input);                         /*函数表达式语句*/
            /*文字说明*/
            printf("The factorial of %d is %ld.\n",input,result);
        }
    }
    printf("Done!\n");                                      /*文字说明*/

    system("pause");
    return 0;
}

/*判断输入数据的有效性并返回该数据*/
/*函数定义*/
int  get_num()
{
    int number;                                             /*存储返回值的变量*/
    int flag=0;                                             /*标记变量*/
    char ch;
    printf("Please enter an integer(press Ctrl+Z to quit):\n");
    flag=scanf("%d",&number);
    while (flag!=1)
    {
        if (flag==-1)
        {
            return -1;
        }
        else
        {
            printf("ERROR:");
            while ((ch=getchar())!='\n')
                putchar(ch);
            printf(" is not an number!\n");
            printf("Please enter an number in the range 0~12(press Ctrl+Z to quit):\n");
            flag=scanf("%d",&number);
        }
    }
    return number;
}

/*使用递归求输入数据的阶乘的函数*/
/*函数定义*/
long re_factorial(int num)
{
    long result;                                            /*存储返回值的变量*/

    if(num==1)
        return 1;                                           /*1的阶乘是1*/
    else
        result=num*re_factorial(num-1);                     /*函数表达式语句，递归调用*/

    return result;                                          /*返回本级递归的求值结果*/
}