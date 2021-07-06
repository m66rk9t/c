/*浮点型转换说明与修饰符的组合*/
#include<stdio.h>
#include<stdlib.h>
#define PI 3.1415926535 //符号常量
int main(void)
{
    printf("*%f*\n",PI);        //默认打印格式
    printf("*%e*\n",PI);        //指数计数法
    printf("*%4.2f*\n",PI);     //指定宽度为4，2位小数
    printf("*%3.1f*\n",PI);     //指定宽度为3，1位小数
    printf("*%10.3f*\n",PI);    //指定宽度为10，3位小数
    printf("*%10.3E*\n",PI);    //指定宽度为10，3位小数，指数计数法格式
    printf("*%+4.2f*\n",PI);    //指定宽度为4，2位小数，显示符号
    printf("*%010.2f*\n",PI);   //指定宽度为10，2位小数，前导0代替空格填充字段宽度

    system("pause");
    return 0;
}