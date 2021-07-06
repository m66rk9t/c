#include<stdio.h>
void reverse(double *arr,int n);            /*使数组倒序排列的函数原型*/
void show_arr(double *start,double *end);   /*显示数组内容的函数原型*/
int main(void)
{
    /*声明并初始化数组*/
    double arr[5]={5.6,7.4,6.2,11.8,9.9};

    printf("Original:\n");
    show_arr(arr,arr+5);

    /*函数调用*/
    reverse(arr,5);
    printf("Reverse:\n");
    show_arr(arr,arr+5);


    return 0;
}
/*函数定义*/
/*倒序排列*/
void reverse(double *arr,int n)
{
    double temp;/*临时变量，储存待交换的的值*/
    /*不论元素个数是基数还是偶数，当下标为n/2时不再交换两个元素的值*/
    for (int i = 0; i < n/2; i++)
    {
        temp=arr[n-1-i];
        arr[n-1-i]=arr[i];
        arr[i]=temp;
    }
}
/*显示数组内容*/
void show_arr(double *start,double *end)
{
    while (start<end)
        printf("%.1f ",*(start++));
    printf("\n");
}