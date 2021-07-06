/*使用指针变量判断三数大小并交换数值*/
#include<stdio.h>
#include<stdlib.h>
void Swap_3(double * num_1, double * num_2, double * num_3); /*函数原型*/
int main(void)
{
    double num1,num2,num3;                     /*存储待输入数据的三个变量*/

    printf("Please enter three numbers:\n");   /*文字说明*/
    scanf("%lf %lf %lf",&num1,&num2,&num3);    /*输入double类型数据*/
    Swap_3(&num1,&num2,&num3);                 /*函数表达式语句，变量地址作实际参数传递*/
    printf("%f>%f>%f\n",num1,num2,num3);       /*文字说明*/

    system("pause");
    return 0;
}

/*使用指针变量交换最值的函数*/
/*函数定义*/
void Swap_3(double * num_1, double * num_2, double * num_3)
{
    int temp;   /*存储要交换值的临时变量*/

    /*判断大小并交换值*/
    if(*num_1<*num_2)   {temp=*num_1;*num_1=*num_2;*num_2=temp;}
    if(*num_1<*num_3)   {temp=*num_1;*num_1=*num_3;*num_3=temp;}
    if(*num_2<*num_3)   {temp=*num_2;*num_2=*num_3;*num_3=temp;}
}