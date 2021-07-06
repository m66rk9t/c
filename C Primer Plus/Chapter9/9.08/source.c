/*求负幂*/
#include<stdio.h>
#include<stdlib.h>
double negative_power(double base, int index);                                  /*函数原型*/
int main(void)
{
    double input_base,result;                                                   /*存储待输入的底数以及求幂结果*/
    int input_index;                                                            /*存储带输入的负幂指数*/

    printf("Please enter a base and an exponent(press Ctrl+Z to quit):\n");     /*文字说明*/
    while (scanf("%lf %d",&input_base,&input_index)!=-1)                        /*重复输入直到遇到文件结尾*/
    {
        result=negative_power(input_base,input_index);                          /*函数表达式语句*/
        printf("Evaluation result:%f\n",result);                                /*输出求值结果*/
        printf("Now enter another set of valuse(press Ctrl+Z to quit):\n");     /*文字说明*/
    }
    printf("Done!\n");

    system("pause");
    return 0;
}

double negative_power(double base, int index)                                   /*函数定义*/
{
    double result=1.0;                                                          /*存储返回值*/
    if (base==0)                                                                /*处理底数为0的情况*/
    {
        if (index==0)
        {
            printf("0^0 undefined.\n");
            result=1;
        }
        else
        {
            printf("Any power of 0 is 0.\n");
            result=0;
        }
    }
    else if (index==0)                                                          /*处理指数为0的情况*/
    {
        result=1;
    }
    else                                                                        /*负幂求值*/
    {
        for (int i = 1; i <= -index; i++)
        {
            result*=1.0/base;
        }
    }
    
    return result;                                                              /*返回值*/
}