#include<stdio.h>
#define ROWS 3
#define COLS 4
void copy_arr(double source[],double target[],int n);/*拷贝一维数组内容函数原型*/
void show_arr(double (*arr)[COLS],int rows);         /*显示二维数组内容的函数原型*/
int main(void)
{
    double source[ROWS][COLS]={
        {1.1,2.2,3.3,4.4,},
        {5.5,6.6,7.7,8.8,},
        {9.9,10.10,11.11,12.12}
    };/*声明并初始化源二维数组*/

    /*声明目标数组*/
    double target[ROWS][COLS];

    /*函数调用，拷贝数组内容*/
    for (int i = 0; i < ROWS; i++)
    {/*传递参数：两个一维数组的首元素地址和元素个数*/
        copy_arr(source[i],target[i],COLS);
    }

    printf("Source:\n");
    show_arr(source,ROWS);
    printf("Target:\n");
    show_arr(target,ROWS);

    return 0;
}
/*函数定义*/
/*拷贝一维数组内容*/
void copy_arr(double source[],double target[],int n)
{
     for (int i = 0; i < n; i++)
        target[i]=source[i];
}
/*显示二维数组内容*/
void show_arr(double (*arr)[COLS],int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("%6.2f ",arr[i][j]);
        printf("\n");
    }
}