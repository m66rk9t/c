#include<stdio.h>
int max_elmt(int *arr,int *end);/*函数原型*/
int main(void)
{
    /*声明并初始化数组*/
    int arr[5]={5,7,6,11,9};
    int max;/*储存最大值*/
    
    /*函数调用，传递地址*/
    max=max_elmt(arr,arr+5);
    printf("The max element's value is %d.\n",max);

    return 0;
}
/*函数定义*/
int max_elmt(int *arr,int *end)
{
    /*将首元素值赋给临时变量*/
    int max=*(arr++);

    while (arr<end)
    {/*如果有比max大的值就再赋值*/
        if(*arr>max)
            max=*arr;
        arr++;/*使指针指向下一个地址/元素*/
    }

    return max;
}
