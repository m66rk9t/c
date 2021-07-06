/*使用指针变量判断两数大小并交换数值*/
#include<stdio.h>
#include<stdlib.h>
void Swap_2(int * num_1, int * num_2);  /*函数原型*/
int main(void)
{
    int num1,num2;  /*存储待输入数据的两个变量*/

    printf("Please enter two integers:\n"); /*文字说明*/
    scanf("%d %d",&num1,&num2); /*输入两个数*/
    Swap_2(&num1,&num2);        /*函数表达式语句，将变量地址作为实际参数传递*/
    printf("The max is %d, the min is %d.\n",num1,num2);    /*文字说明*/

    system("pause");
    return 0;
}

/*使用指针变量交换最大值最小值的函数*/
/*函数定义*/
void Swap_2(int * num_1, int * num_2)
{
    int temp;   /*临时变量存储要交换的值*/

    if(*num_1<*num_2)   /*解引用变量并判断大小*/
    {
        /*交换数值，满足将最大值放入第一个变量中*/
        temp=*num_1;
        *num_1=*num_2;
        *num_2=temp;
    }
}