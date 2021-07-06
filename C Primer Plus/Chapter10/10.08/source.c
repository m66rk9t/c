#include<stdio.h>
void copy_arr(int source[],int target[],int n);/*拷贝数组内容的函数原型*/
void show_arr(int *start,int *end);      /*显示数组内容的函数原型*/
int main(void)
{
    /*声明并初始化源数组*/
    int source[7]={5,8,2,4,6,9,10};
    /*声明目标数组*/
    int target[3];

    /*函数调用*/
    copy_arr(source+2,target,3);
    printf("Source:");
    show_arr(source,source+7);
    printf("Target:");
    show_arr(target,target+3);

    return 0;
}
/*函数定义*/
/*拷贝数组内容的函数定义*/
void copy_arr(int source[],int target[],int n)
{
    for (int i = 0; i < n; i++)
        *(target++)=*(source++);
}
/*显示数组内容的函数定义*/
void show_arr(int *start,int *end)
{
    while (start<end)
        printf("%.1d ",*(start++));
    printf("\n");
}