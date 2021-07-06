#include<stdio.h>
#define SIZE 4
void add_ini(int *src1,int *src2,int *tgt,int n);/*对应元素相加并赋值的函数原型*/
void show_arr(int *start,int *end);        /*显示数组内容的函数原型*/
int main(void)
{
    /*声明并初始化两个源数组*/
    int src1[SIZE]={2,4,5,8};
    int src2[SIZE]={1,0,4,6};
    /*声明目标数组*/
    int tgt[SIZE];

    /*函数调用*/
    add_ini(src1,src2,tgt,SIZE);
    printf("Source Array 1:\n");
    show_arr(src1,src1+SIZE);
    printf("\nSource Array 2:\n");
    show_arr(src2,src2+SIZE);
    printf("\nTarget Array:\n");
    show_arr(tgt,tgt+SIZE);

    return 0;
}
/*函数定义*/
void add_ini(int *src1,int *src2,int *tgt,int n)
{
    for (int i = 0; i < n; i++)
        tgt[i]=src1[i]+src2[i];
}
void show_arr(int *start,int *end)
{
    while (start<end)
        printf("%d ",*(start++));
}