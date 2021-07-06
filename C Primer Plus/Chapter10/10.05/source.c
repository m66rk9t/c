#include<stdio.h>
double difference(double *start, double *end);/*函数原型*/
int main(void)
{
    /*声明并初始化数组*/
    double arr[5]={5.6,7.4,6.2,11.8,9.9};
    double dif;/*储存最大值与最小值的差值*/

    /*函数调用*/
    dif=difference(arr,arr+5);
    printf("The difference between the maximum and minimum is %.2f.\n",dif);
    return 0;
}
/*函数定义*/
double difference(double *start, double *end)
{
    double max=*start,min=*start;

    for (start++; start < end; start++)
    {
        if(*start>max)
            max=*start;
        if(*start<min)
            min=*start;
    }

    return max-min;
}