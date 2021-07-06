/*递归：进制转换升级版*/
#include<stdio.h>
#include<stdlib.h>
void to_base_n(unsigned long number,int base);                              /*函数原型*/
int main(void)
{
    unsigned long number;                                                   /*存储待转换的十进制值的变量*/
    int base;                                                               /*以该数值为进制进行转换*/
    printf("Please enter an integer and a base(press Ctrl+Z to qiut):\n");
    while (scanf("%lu %d",&number,&base)!=-1)                               /*提示用户重复输入直到遇到文件结尾结束循环*/
    {
        if (base<2||base>10)                                                /*判断有效性*/
        {
            printf("Please enter an integer in the range of 2~10:\n");
            scanf("%d",&base);
        }

        printf("Conversion result: ");
        to_base_n(number,base);                                             /*函数表达式语句，调用递归函数*/
        printf("\nNow enter another set of valuse(press Ctrl+Z to quit):\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

void to_base_n(unsigned long number,int base)                               /*递归函数定义*/
{
    int remainder;                                                          /*存储余数*/
    remainder=number%base;                                                  /*求余*/
    if (number/base>=1)                                                     /*判断是否还有下一进制位*/
    {
        to_base_n(number/base,base);                                        /*函数表达式语句，递归调用*/
    }
    printf("%d",remainder);                                                 /*打印每一进制位*/
}