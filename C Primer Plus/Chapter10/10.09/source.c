#include<stdio.h>
/*变长数组做形参的拷贝函数原型*/
void copy_arr(int rows,int cols,double target[rows][cols],double (*source)[5]);
/*变长数组做形参的显示数组内容的函数原型*/
void show_arr(int rows,int cols,double arr[rows][cols]);
int main(void)
{
    double source[3][5]={
        {0.1,0.2,0.3,0.4,0.5},
        {2.5,2.6,2.9,2.1,2.3},
        {5.1,5.5,5.3,5.9,5.7}
    };/*声明并初始化源二维数组*/

    /*声明目标二维数组*/
    double target[3][5];

    /*函数调用*/
    copy_arr(3,5,target,source);
    printf("Source array:\n");
    show_arr(3,5,source);
    printf("Target array:\n");
    show_arr(3,5,target);

    return 0;
}
/*函数定义*/
/*变长数组做形参，拷贝数组内容*/
void copy_arr(int rows,int cols,double target[rows][cols],double (*source)[5])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            target[i][j]=source[i][j];
    }
}
/*变长数组做形参，显示数组内容*/
void show_arr(int rows,int cols,double arr[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%6.2f ",arr[i][j]);
        printf("\n");
    }
}