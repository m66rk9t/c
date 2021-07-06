/*求调和平均数*/
#include<stdio.h>
#include<stdlib.h>
double harmonic_mean(double first, double second);          /*函数原型*/
int main(void)
{
    double first_value,second_value,result;                 /*待求值的两个运算对象以及计算结果*/
    
    /*文字说明*/
    printf("Please enter two floating-point values(press Ctrl+Z to quit):\n");
    while (scanf("%lf %lf",&first_value,&second_value)==2)  /*重复输入数据直到遇到文件结尾结束循环*/
    {
        result=harmonic_mean(first_value,second_value);     /*函数表达式语句，调用函数*/
        /*文字说明*/
        printf("The harmonic mean of %lf and %lf is %lf.\n",first_value,second_value,result);
        printf("Now enter another set of valuse(press Ctrl+Z to quit):\n");
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

double harmonic_mean(double first, double second)           /*函数定义*/
{
    return 1.0/((1.0/first+1.0/second)/2.0);                /*返回调和平均数求值结果*/
}