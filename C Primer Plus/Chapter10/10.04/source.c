#include<stdio.h>
double max_index(double *arr,double n);/*函数原型*/
int main(void)
{
    /*声明并初始化数组*/
    double arr[5]={5.6,7.4,6.2,11.8,9.9};
    int index;/*储存最大值下标*/

    /*函数调用*/
    index=max_index(arr,5);
    printf("The max element's index is %d.\n",index);

    return 0;
}
/*函数定义*/
double max_index(double *arr,double n)
{
    int index=0;/*首元素的下标*/
    double max=*arr;/*首元素的值*/

    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            index=i;/*i的值是比max大的元素的下标*/
        }
    }

    return index;
}