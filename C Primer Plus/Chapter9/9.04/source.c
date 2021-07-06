/*递归：十进制值转换二进制值*/
#include<stdio.h>
#include<stdlib.h>
void to_binary(unsigned long number);   /*函数原型*/
int main(void)
{
    unsigned long number;               /*存储待转换的十进制值的变量*/
    /*文字说明*/
    printf("Please enter an integer(enter 'q' to qiut):\n");
    while (scanf("%d",&number)==1)      /*提示用户重复输入直到输入'q'结束循环*/
    {
        printf("Binary equivalent: ");  /*文字说明*/
        to_binary(number);              /*函数表达式语句，调用递归函数*/
        /*文字说明*/
        printf("\nNow enter another integer(enter 'q' to qiut):\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

void to_binary(unsigned long number)    /*递归函数定义*/
{
    int remainder;                      /*存储余数，即二进制数的每一位，非0即1*/
    remainder=number%2;                 /*求余*/
    if (number>=2)                      /*如果本次递归中被除数大于或等于2说明还有二进制位*/
    {
        to_binary(number/2);            /*函数表达式语句，递归调用*/
    }
    putchar(remainder==0?'0':'1');      /*输出二进制位的数，非0即1，或为printf("%d",remainder);*/
}
/*递归函数方法二
void to_binary(unsigned long number)
{
    int remainder,quotient;             //quotient存储本次递归中的商
    remainder=number%2;
    quotient=number/2;                  //求商
    if (quotient>=1)                    //如果商大于或等于1说明还有二进制位
    {
        to_binary(quotient);            //函数表达式语句，递归调用
    }
    putchar(remainder==0?'0':'1');
}*/